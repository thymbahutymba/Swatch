#ifndef SWATCH_H
#define SWATCH_H

typedef enum interface {
    TIME_DISPLAY,
    TIME_SET,
    ALARM_SET,
    STOPWATCH
} interface_t;

typedef enum setting { SET_HOURS, SET_MINUTE } setting_t;
typedef enum sw_subs { DISPLAY, PARTIAL } sw_subs_t;
typedef enum tc_state { NOT_COUNTING, COUNTING } tc_state_t;
typedef enum alarm_state { NOT_SETTED, SILENT, BUZZING } alarm_state_t;

typedef unsigned char bool_t;

typedef struct time {
    unsigned short int hours;
    unsigned short int minutes;
    unsigned short int seconds;
    unsigned short int tenths;
} stime_t;

typedef struct stopwatch {
    stime_t cur_time;
    stime_t alarm_time;
    stime_t swatch_time;
    stime_t part_time;
    stime_t *display_time;
    interface_t cur_state;
    setting_t sett_subs;
    sw_subs_t swatch_subs;
    tc_state_t sc_state;
    alarm_state_t a_state;
} stopwatch_t;

void swatch_init();
void swatch_step(bool_t, bool_t, bool_t, bool_t, bool_t, bool_t);
void init_time(stime_t *);
void time_copy(stime_t *, stime_t *);
void increase_time(stime_t *);
void handle_interface_signal(bool_t, bool_t, bool_t, bool_t);
void time_setting(stime_t *, bool_t, bool_t, setting_t);

#endif // SWATCH_H