#include "swatch.h"

stopwatch_t MySwatch;

// Init the struct time with all fields equal to 0
void init_time(stime_t *t) {
    t->hours = 0;
    t->minutes = 0;
    t->seconds = 0;
    t->tenths = 0;
}

// Copy time from source to dest
void time_copy(stime_t *dst, stime_t *src) {
    dst->hours = src->hours;
    dst->minutes = src->minutes;
    dst->seconds = src->seconds;
    dst->tenths = src->tenths;
}

// Increase time counting
void increase_time(stime_t *t) {
    t->tenths = (t->tenths + 1) % 10;
    if (t->tenths)
        return;

    t->seconds = (t->seconds + 1) % 60;
    if (t->seconds)
        return;

    t->minutes = (t->minutes + 1) % 60;
    if (t->minutes)
        return;

    t->hours = (t->hours + 1) % 24;
}

// Initialization of stopwatch data structure
void swatch_initialization() {
    // Initialization of time fields
    init_time(&MySwatch.alarm_time);
    init_time(&MySwatch.cur_time);
    init_time(&MySwatch.swatch_time);
    init_time(&MySwatch.part_time);

    // Pointer to time to display
    MySwatch.display_time = &MySwatch.cur_time;

    // Initialization of interface current state and setting mode state
    MySwatch.cur_state = TIME_DISPLAY;
    MySwatch.sett_subs = SET_HOURS;
    MySwatch.swatch_subs = DISPLAY;
    MySwatch.sc_state = NOT_COUNTING;
}

/* Handle signal for changing the current interface state */
void handle_interface_signal(bool_t time_mode, bool_t time_set_mode,
                             bool_t alarm_mode, bool_t swatch_mode) {
    if (time_mode)
        MySwatch.cur_state = TIME_DISPLAY;
    else if (time_set_mode) {
        if (MySwatch.cur_state != TIME_SET) {
            MySwatch.cur_state = TIME_SET;
            MySwatch.sett_subs = SET_HOURS;
        } else {
            // Change the time setting mode for increasing hours or minutes
            MySwatch.sett_subs = 1 - MySwatch.sett_subs;
        }
    } else if (alarm_mode) {
        if (MySwatch.cur_state != ALARM_SET) {
            MySwatch.cur_state = ALARM_SET;
            MySwatch.sett_subs = SET_HOURS;
        } else {
            // Change the alarm setting mode for increasing hours or minutes
            MySwatch.sett_subs = 1 - MySwatch.sett_subs;
        }
    } else if (swatch_mode)
        MySwatch.cur_state = STOPWATCH;
}

// Update the time if the plus or minus buttons are pressed
void time_setting(stime_t *t, bool_t minus, bool_t plus, setting_t s) {
    // Increase the hours or the minutes of the time given
    if (s == SET_HOURS) {
        t->hours = (plus) ? (++(t->hours) % 24) : t->hours;
        t->hours = (minus) ? ((24 + t->hours - 1) % 24) : t->hours;
    } else {
        t->minutes = (plus) ? (++(t->minutes) % 60) : t->minutes;
        t->minutes = (minus) ? ((60 + t->minutes - 1) % 60) : t->minutes;
    }
}

void swatch_step(bool_t plus_b, bool_t minus_b, bool_t time_mode,
                 bool_t time_set_mode, bool_t alarm_mode, bool_t swatch_mode) {
    interface_t old_state = MySwatch.cur_state;

    // Increase the current time
    increase_time(&MySwatch.cur_time);

    // Handle signal into interface except minus and plus
    handle_interface_signal(time_mode, time_set_mode, alarm_mode, swatch_mode);

    switch (MySwatch.cur_state) {
    case TIME_SET:
        // Update the current time and change the display time
        time_setting(&MySwatch.cur_time, minus_b, plus_b, MySwatch.sett_subs);
        MySwatch.display_time = &MySwatch.cur_time;
        break;
    case ALARM_SET:
        // Update the alarm time and change the display time
        time_setting(&MySwatch.alarm_time, minus_b, plus_b, MySwatch.sett_subs);
        MySwatch.display_time = &MySwatch.alarm_time;
        break;
    case STOPWATCH:
        switch (MySwatch.swatch_subs) {
        case PARTIAL:
            MySwatch.display_time = &MySwatch.part_time;
            if (minus_b)
                MySwatch.swatch_subs = DISPLAY;
            break;
        default:
            MySwatch.display_time = &MySwatch.swatch_time;
            if (minus_b) {
                MySwatch.swatch_subs = PARTIAL;
                time_copy(&MySwatch.part_time, &MySwatch.swatch_time);
                MySwatch.display_time = &MySwatch.part_time;
            }
            break;
        }
        break;
    default:
        MySwatch.display_time = &MySwatch.cur_time;
        break;
    }

    switch (MySwatch.sc_state) {
    case COUNTING:
        increase_time(&MySwatch.swatch_time);
        if (MySwatch.cur_state == STOPWATCH && plus_b)
            MySwatch.sc_state = NOT_COUNTING;
        break;
    default:
        if (MySwatch.cur_state == STOPWATCH) {
            if (plus_b)
                MySwatch.sc_state = COUNTING;
            else if (old_state == STOPWATCH && swatch_mode)
                init_time(&MySwatch.swatch_time);
        }
        break;
    }
}