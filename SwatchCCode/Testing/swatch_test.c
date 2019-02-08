//#include "CUnit-2.1-0/CUnit/Headers/Automated.h"
//#include "CUnit-2.1-0/CUnit/Headers/Basic.h"
#include "swatch.h"
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

extern stopwatch_t MySwatch;

void test_time_copy(void) {
    stime_t t1 = {10, 15, 0, 0};
    stime_t t2;
    time_copy(&t2, &t1);
    CU_ASSERT(t2.hours == t1.hours);
    CU_ASSERT(t2.minutes == t1.minutes);
    CU_ASSERT(t2.seconds == t1.seconds);
    CU_ASSERT(t2.tenths == t1.tenths);
}

void test_increase_time(void) {
    stime_t t;

    // Test the increasing of the tenths
    init_time(&t);
    increase_time(&t);
    CU_ASSERT(t.tenths == 1);
    CU_ASSERT((t.seconds | t.minutes | t.hours) == 0);

    // Test the increasing of the seconds
    init_time(&t);
    for (size_t i = 0; i < 10; ++i)
        increase_time(&t);

    CU_ASSERT(t.seconds == 1);
    CU_ASSERT((t.tenths | t.minutes | t.hours) == 0);

    // Test the increasing of the minutes
    init_time(&t);
    for (size_t i = 0; i < 10 * 60 * 2; ++i)
        increase_time(&t);

    CU_ASSERT(t.minutes == 2);
    CU_ASSERT((t.tenths | t.seconds | t.hours) == 0);

    // Test the increasing of the hours
    init_time(&t);
    for (size_t i = 0; i < 10 * 60 * 60 * 5; ++i)
        increase_time(&t);

    CU_ASSERT(t.hours == 5);
    CU_ASSERT((t.tenths | t.seconds | t.minutes) == 0);
}

void test_handle_interface_signal(void) {
    handle_interface_signal(1, 0, 0, 0);
    CU_ASSERT(MySwatch.cur_state == TIME_DISPLAY);

    handle_interface_signal(0, 1, 0, 0);
    CU_ASSERT(MySwatch.cur_state == TIME_SET &&
              MySwatch.sett_subs == SET_HOURS);
    handle_interface_signal(0, 1, 0, 0);
    CU_ASSERT(MySwatch.sett_subs == SET_MINUTE);
}

void test_time_setting(void) {
    stime_t t;
    init_time(&t);
    time_setting(&t, 1, 0, SET_HOURS);
    CU_ASSERT(t.hours == 23);

    for (size_t i = 0; i < 25; ++i)
        time_setting(&t, 0, 1, SET_MINUTE);
    CU_ASSERT(t.hours == 23 && t.minutes == 25);
}

void test_swatch_step(void) {
    swatch_step(0, 0, 0, 0, 0, 1);
    CU_ASSERT(MySwatch.cur_state == STOPWATCH);

    CU_ASSERT(MySwatch.sc_state == NOT_COUNTING);
    swatch_step(1, 0, 0, 0, 0, 0);
    CU_ASSERT(MySwatch.sc_state == COUNTING);

    CU_ASSERT(MySwatch.swatch_subs == DISPLAY);
    for (size_t i = 0; i < 5; ++i) // Increase a bit the swatch time
        swatch_step(0, 0, 0, 0, 0, 0);
    CU_ASSERT(MySwatch.swatch_time.tenths == 5);
    // check that the time is not reset even if STOPWATCH is pressed
    swatch_step(0, 0, 0, 0, 0, 1);
    CU_ASSERT(MySwatch.swatch_time.tenths == 6);

    swatch_step(1, 0, 0, 0, 0, 0);
    CU_ASSERT(MySwatch.sc_state == NOT_COUNTING);
    CU_ASSERT(MySwatch.swatch_time.tenths == 7);

    // Check that the stopwatch time wasn't resetted even if there was a
    // transition to another state
    swatch_step(0, 0, 0, 1, 0, 0);
    swatch_step(0, 0, 0, 0, 0, 1);
    CU_ASSERT(MySwatch.swatch_time.tenths == 7);

    swatch_step(0, 1, 0, 0, 0, 0);
    CU_ASSERT(MySwatch.swatch_subs == PARTIAL);
}

int main() {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Suite", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "Test the time copy", test_time_copy)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL ==
        CU_add_test(pSuite, "Test the increase time", test_increase_time)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "Test the button press",
                            test_handle_interface_signal)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL ==
        CU_add_test(pSuite, "Test the time setting", test_time_setting)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "Test the FSM", test_swatch_step)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}