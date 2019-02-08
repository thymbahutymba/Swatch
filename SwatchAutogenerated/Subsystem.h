/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.h
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Nov 30 17:57:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include <stddef.h>
#include <string.h>
#ifndef Subsystem_COMMON_INCLUDES_
# define Subsystem_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Subsystem_COMMON_INCLUDES_ */

#include "Subsystem_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define Subsystem_M_TYPE               RT_MODEL_Subsystem_T

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
  uint8_T is_active_c3_Subsystem;      /* '<S1>/StopwatchAndrea ' */
  uint8_T is_Interface;                /* '<S1>/StopwatchAndrea ' */
  uint8_T is_TimeSet;                  /* '<S1>/StopwatchAndrea ' */
  uint8_T is_Stopwatch;                /* '<S1>/StopwatchAndrea ' */
  uint8_T was_Stopwatch;               /* '<S1>/StopwatchAndrea ' */
  uint8_T is_AlarmSet;                 /* '<S1>/StopwatchAndrea ' */
  uint8_T is_StopwatchCount;           /* '<S1>/StopwatchAndrea ' */
  uint8_T is_Alarm;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T Ahours;                      /* '<S1>/StopwatchAndrea ' */
  uint8_T Aminutes;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T hours;                       /* '<S1>/StopwatchAndrea ' */
  uint8_T minutes;                     /* '<S1>/StopwatchAndrea ' */
  uint8_T seconds;                     /* '<S1>/StopwatchAndrea ' */
  uint8_T tenths;                      /* '<S1>/StopwatchAndrea ' */
  uint8_T Shours;                      /* '<S1>/StopwatchAndrea ' */
  uint8_T Sminutes;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T Sseconds;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T Stenths;                     /* '<S1>/StopwatchAndrea ' */
  uint8_T Phours;                      /* '<S1>/StopwatchAndrea ' */
  uint8_T Pminutes;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T Pseconds;                    /* '<S1>/StopwatchAndrea ' */
  uint8_T Ptenths;                     /* '<S1>/StopwatchAndrea ' */
} DW_Subsystem_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StopwatchAndrea_Trig_ZCE[7];/* '<S1>/StopwatchAndrea ' */
} PrevZCX_Subsystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem_T {
  const char_T *errorStatus;
  PrevZCX_Subsystem_T *prevZCSigState;
  DW_Subsystem_T *dwork;
};

/* External data declarations for dependent source files */
const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern RT_MODEL_Subsystem_T *Subsystem(boolean_T *Subsystem_U_plusbutton,
  boolean_T *Subsystem_U_minusbutton, boolean_T *Subsystem_U_timemode, boolean_T
  *Subsystem_U_timesetmode, boolean_T *Subsystem_U_alarmmode, boolean_T
  *Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode);
extern void Subsystem_initialize(RT_MODEL_Subsystem_T *const Subsystem_M,
  boolean_T *Subsystem_U_plusbutton, boolean_T *Subsystem_U_minusbutton,
  boolean_T *Subsystem_U_timemode, boolean_T *Subsystem_U_timesetmode, boolean_T
  *Subsystem_U_alarmmode, boolean_T *Subsystem_U_swatchmode, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode);
extern void Subsystem_step(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
  Subsystem_U_plusbutton, boolean_T Subsystem_U_minusbutton, boolean_T
  Subsystem_U_timemode, boolean_T Subsystem_U_timesetmode, boolean_T
  Subsystem_U_alarmmode, boolean_T Subsystem_U_swatchmode, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('StopwatchAndrea/Subsystem')    - opens subsystem StopwatchAndrea/Subsystem
 * hilite_system('StopwatchAndrea/Subsystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'StopwatchAndrea'
 * '<S1>'   : 'StopwatchAndrea/Subsystem'
 * '<S2>'   : 'StopwatchAndrea/Subsystem/Counter Limited'
 * '<S3>'   : 'StopwatchAndrea/Subsystem/StopwatchAndrea '
 * '<S4>'   : 'StopwatchAndrea/Subsystem/Counter Limited/Increment Real World'
 * '<S5>'   : 'StopwatchAndrea/Subsystem/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Subsystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
