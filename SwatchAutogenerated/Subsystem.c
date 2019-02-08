/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
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

#include "Subsystem.h"
#include "Subsystem_private.h"

/* Named constants for Chart: '<S1>/StopwatchAndrea ' */
#define Subsystem_IN_AlarmSet          ((uint8_T)1U)
#define Subsystem_IN_Buzzing           ((uint8_T)1U)
#define Subsystem_IN_Counting          ((uint8_T)1U)
#define Subsystem_IN_Display           ((uint8_T)1U)
#define Subsystem_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Subsystem_IN_NotCounting       ((uint8_T)2U)
#define Subsystem_IN_Partial           ((uint8_T)2U)
#define Subsystem_IN_SetHours          ((uint8_T)1U)
#define Subsystem_IN_SetHours1         ((uint8_T)1U)
#define Subsystem_IN_SetMinutes        ((uint8_T)2U)
#define Subsystem_IN_SetMinutes1       ((uint8_T)2U)
#define Subsystem_IN_Silent            ((uint8_T)2U)
#define Subsystem_IN_Stopwatch         ((uint8_T)2U)
#define Subsystem_IN_TimeDispaly       ((uint8_T)3U)
#define Subsystem_IN_TimeSet           ((uint8_T)4U)
#define Subsystem_event_Alarmmode      (5)
#define Subsystem_event_Swatchmode     (6)
#define Subsystem_event_Tick           (0)
#define Subsystem_event_Timemode       (3)
#define Subsystem_event_Timesetmode    (4)
#define Subsystem_event_minusbutton    (2)
#define Subsystem_event_plusbutton     (1)

/* Forward declaration for local functions */
static void Subsys_enter_internal_Stopwatch(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  DW_Subsystem_T *Subsystem_DW);
static void Subsystem_Interface(const int32_T *sfEvent, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, DW_Subsystem_T
  *Subsystem_DW);
static void Subsyste_chartstep_c3_Subsystem(const int32_T *sfEvent, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, DW_Subsystem_T
  *Subsystem_DW);

/* Function for Chart: '<S1>/StopwatchAndrea ' */
static void Subsys_enter_internal_Stopwatch(uint8_T *Subsystem_Y_hours, uint8_T *
  Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T *Subsystem_Y_tenths,
  DW_Subsystem_T *Subsystem_DW)
{
  switch (Subsystem_DW->was_Stopwatch) {
   case Subsystem_IN_Display:
    Subsystem_DW->is_Stopwatch = Subsystem_IN_Display;
    Subsystem_DW->was_Stopwatch = Subsystem_IN_Display;
    break;

   case Subsystem_IN_Partial:
    Subsystem_DW->is_Stopwatch = Subsystem_IN_Partial;
    Subsystem_DW->was_Stopwatch = Subsystem_IN_Partial;

    /* Outport: '<Root>/hours' */
    *Subsystem_Y_hours = Subsystem_DW->Phours;

    /* Outport: '<Root>/minutes' */
    *Subsystem_Y_minutes = Subsystem_DW->Pminutes;

    /* Outport: '<Root>/seconds' */
    *Subsystem_Y_seconds = Subsystem_DW->Pseconds;

    /* Outport: '<Root>/tenths' */
    *Subsystem_Y_tenths = Subsystem_DW->Ptenths;
    break;

   default:
    Subsystem_DW->is_Stopwatch = Subsystem_IN_Display;
    Subsystem_DW->was_Stopwatch = Subsystem_IN_Display;
    break;
  }
}

/* Function for Chart: '<S1>/StopwatchAndrea ' */
static void Subsystem_Interface(const int32_T *sfEvent, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, DW_Subsystem_T
  *Subsystem_DW)
{
  uint8_T x;
  int32_T tmp;
  switch (*sfEvent) {
   case Subsystem_event_Timemode:
    Subsystem_DW->is_AlarmSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_TimeSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Interface = Subsystem_IN_TimeDispaly;

    /* Outport: '<Root>/mode' */
    *Subsystem_Y_mode = 0U;
    break;

   case Subsystem_event_Swatchmode:
    Subsystem_DW->is_AlarmSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_TimeSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Interface = Subsystem_IN_Stopwatch;

    /* Outport: '<Root>/mode' */
    *Subsystem_Y_mode = 3U;
    Subsys_enter_internal_Stopwatch(Subsystem_Y_hours, Subsystem_Y_minutes,
      Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_DW);
    break;

   default:
    switch (Subsystem_DW->is_Interface) {
     case Subsystem_IN_AlarmSet:
      /* Outport: '<Root>/mode' */
      *Subsystem_Y_mode = 2U;
      if (*sfEvent == Subsystem_event_Timesetmode) {
        Subsystem_DW->is_AlarmSet = Subsystem_IN_NO_ACTIVE_CHILD;
        Subsystem_DW->is_Interface = Subsystem_IN_TimeSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 1U;
        Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
      } else if (Subsystem_DW->is_AlarmSet == Subsystem_IN_SetHours1) {
        switch (*sfEvent) {
         case Subsystem_event_plusbutton:
          tmp = (int32_T)(Subsystem_DW->Ahours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
          break;

         case Subsystem_event_minusbutton:
          tmp = (int32_T)(Subsystem_DW->Ahours + 24U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          x = (uint8_T)(tmp - 1);
          Subsystem_DW->Ahours = (uint8_T)((uint32_T)x - (uint8_T)(x / 24U * 24U));
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
          break;

         case Subsystem_event_Alarmmode:
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetMinutes1;
          break;

         default:
          /* Outport: '<Root>/hours' */
          *Subsystem_Y_hours = Subsystem_DW->Ahours;

          /* Outport: '<Root>/minutes' */
          *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
          break;
        }
      } else {
        switch (*sfEvent) {
         case Subsystem_event_plusbutton:
          tmp = (int32_T)(Subsystem_DW->Aminutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetMinutes1;
          break;

         case Subsystem_event_minusbutton:
          tmp = (int32_T)(Subsystem_DW->Aminutes + 60U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          x = (uint8_T)(tmp - 1);
          Subsystem_DW->Aminutes = (uint8_T)((uint32_T)x - (uint8_T)(x / 60U *
            60U));
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetMinutes1;
          break;

         case Subsystem_event_Alarmmode:
          Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
          break;

         default:
          /* Outport: '<Root>/hours' */
          *Subsystem_Y_hours = Subsystem_DW->Ahours;

          /* Outport: '<Root>/minutes' */
          *Subsystem_Y_minutes = Subsystem_DW->Aminutes;
          break;
        }
      }
      break;

     case Subsystem_IN_Stopwatch:
      /* Outport: '<Root>/mode' */
      *Subsystem_Y_mode = 3U;
      switch (*sfEvent) {
       case Subsystem_event_Timesetmode:
        Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
        Subsystem_DW->is_Interface = Subsystem_IN_TimeSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 1U;
        Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
        break;

       case Subsystem_event_Alarmmode:
        Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
        Subsystem_DW->is_Interface = Subsystem_IN_AlarmSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 2U;
        Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
        break;

       case Subsystem_event_Swatchmode:
        Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
        Subsys_enter_internal_Stopwatch(Subsystem_Y_hours, Subsystem_Y_minutes,
          Subsystem_Y_seconds, Subsystem_Y_tenths, Subsystem_DW);
        break;

       default:
        if (Subsystem_DW->is_Stopwatch == Subsystem_IN_Display) {
          if (*sfEvent == Subsystem_event_minusbutton) {
            Subsystem_DW->Phours = Subsystem_DW->Shours;
            Subsystem_DW->Pminutes = Subsystem_DW->Sminutes;
            Subsystem_DW->Pseconds = Subsystem_DW->Sseconds;
            Subsystem_DW->Ptenths = Subsystem_DW->Stenths;
            Subsystem_DW->is_Stopwatch = Subsystem_IN_Partial;
            Subsystem_DW->was_Stopwatch = Subsystem_IN_Partial;

            /* Outport: '<Root>/hours' */
            *Subsystem_Y_hours = Subsystem_DW->Phours;

            /* Outport: '<Root>/minutes' */
            *Subsystem_Y_minutes = Subsystem_DW->Pminutes;

            /* Outport: '<Root>/seconds' */
            *Subsystem_Y_seconds = Subsystem_DW->Pseconds;

            /* Outport: '<Root>/tenths' */
            *Subsystem_Y_tenths = Subsystem_DW->Ptenths;
          } else {
            /* Outport: '<Root>/hours' */
            *Subsystem_Y_hours = Subsystem_DW->Shours;

            /* Outport: '<Root>/minutes' */
            *Subsystem_Y_minutes = Subsystem_DW->Sminutes;

            /* Outport: '<Root>/seconds' */
            *Subsystem_Y_seconds = Subsystem_DW->Sseconds;

            /* Outport: '<Root>/tenths' */
            *Subsystem_Y_tenths = Subsystem_DW->Stenths;
          }
        } else {
          if (*sfEvent == Subsystem_event_minusbutton) {
            Subsystem_DW->is_Stopwatch = Subsystem_IN_Display;
            Subsystem_DW->was_Stopwatch = Subsystem_IN_Display;
          }
        }
        break;
      }
      break;

     case Subsystem_IN_TimeDispaly:
      /* Outport: '<Root>/mode' */
      *Subsystem_Y_mode = 0U;
      switch (*sfEvent) {
       case Subsystem_event_Timesetmode:
        Subsystem_DW->is_Interface = Subsystem_IN_TimeSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 1U;
        Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
        break;

       case Subsystem_event_Alarmmode:
        Subsystem_DW->is_Interface = Subsystem_IN_AlarmSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 2U;
        Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
        break;

       default:
        /* Outport: '<Root>/hours' */
        *Subsystem_Y_hours = Subsystem_DW->hours;

        /* Outport: '<Root>/minutes' */
        *Subsystem_Y_minutes = Subsystem_DW->minutes;

        /* Outport: '<Root>/seconds' */
        *Subsystem_Y_seconds = Subsystem_DW->seconds;

        /* Outport: '<Root>/tenths' */
        *Subsystem_Y_tenths = Subsystem_DW->tenths;
        break;
      }
      break;

     default:
      /* Outport: '<Root>/mode' */
      *Subsystem_Y_mode = 1U;
      if (*sfEvent == Subsystem_event_Alarmmode) {
        Subsystem_DW->is_TimeSet = Subsystem_IN_NO_ACTIVE_CHILD;
        Subsystem_DW->is_Interface = Subsystem_IN_AlarmSet;

        /* Outport: '<Root>/mode' */
        *Subsystem_Y_mode = 2U;
        Subsystem_DW->is_AlarmSet = Subsystem_IN_SetHours1;
      } else if (Subsystem_DW->is_TimeSet == Subsystem_IN_SetHours) {
        switch (*sfEvent) {
         case Subsystem_event_plusbutton:
          tmp = (int32_T)(Subsystem_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
          break;

         case Subsystem_event_Timesetmode:
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetMinutes;
          break;

         case Subsystem_event_minusbutton:
          tmp = (int32_T)(Subsystem_DW->hours + 24U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          x = (uint8_T)(tmp - 1);
          Subsystem_DW->hours = (uint8_T)((uint32_T)x - (uint8_T)(x / 24U * 24U));
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
          break;

         default:
          /* Outport: '<Root>/hours' */
          *Subsystem_Y_hours = Subsystem_DW->hours;

          /* Outport: '<Root>/minutes' */
          *Subsystem_Y_minutes = Subsystem_DW->minutes;
          break;
        }
      } else {
        switch (*sfEvent) {
         case Subsystem_event_plusbutton:
          tmp = (int32_T)(Subsystem_DW->minutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetMinutes;
          break;

         case Subsystem_event_Timesetmode:
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetHours;
          break;

         case Subsystem_event_minusbutton:
          tmp = (int32_T)(Subsystem_DW->minutes + 60U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          x = (uint8_T)(tmp - 1);
          Subsystem_DW->minutes = (uint8_T)((uint32_T)x - (uint8_T)(x / 60U *
            60U));
          Subsystem_DW->is_TimeSet = Subsystem_IN_SetMinutes;
          break;

         default:
          /* Outport: '<Root>/hours' */
          *Subsystem_Y_hours = Subsystem_DW->hours;

          /* Outport: '<Root>/minutes' */
          *Subsystem_Y_minutes = Subsystem_DW->minutes;
          break;
        }
      }
      break;
    }
    break;
  }
}

/* Function for Chart: '<S1>/StopwatchAndrea ' */
static void Subsyste_chartstep_c3_Subsystem(const int32_T *sfEvent, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode, DW_Subsystem_T
  *Subsystem_DW)
{
  int32_T tmp;

  /* Chart: '<S1>/StopwatchAndrea ' incorporates:
   *  Outport: '<Root>/mode'
   */
  if (Subsystem_DW->is_active_c3_Subsystem == 0U) {
    Subsystem_DW->is_active_c3_Subsystem = 1U;
    Subsystem_DW->hours = 0U;
    Subsystem_DW->minutes = 0U;
    Subsystem_DW->seconds = 0U;
    Subsystem_DW->Ahours = 0U;
    Subsystem_DW->Aminutes = 0U;
    Subsystem_DW->is_Interface = Subsystem_IN_TimeDispaly;

    /* Outport: '<Root>/mode' */
    *Subsystem_Y_mode = 0U;
    Subsystem_DW->Stenths = 0U;
    Subsystem_DW->Sseconds = 0U;
    Subsystem_DW->Sminutes = 0U;
    Subsystem_DW->Shours = 0U;
    Subsystem_DW->is_StopwatchCount = Subsystem_IN_NotCounting;

    /* Outport: '<Root>/tenths' */
    *Subsystem_Y_tenths = 0U;
    Subsystem_DW->tenths = 0U;
    Subsystem_DW->is_Alarm = Subsystem_IN_Silent;
  } else {
    Subsystem_Interface(sfEvent, Subsystem_Y_hours, Subsystem_Y_minutes,
                        Subsystem_Y_seconds, Subsystem_Y_tenths,
                        Subsystem_Y_mode, Subsystem_DW);
    if (Subsystem_DW->is_StopwatchCount == Subsystem_IN_Counting) {
      if (*sfEvent == Subsystem_event_Tick) {
        if (Subsystem_DW->Stenths == 9) {
          if (Subsystem_DW->Sseconds == 59) {
            if (Subsystem_DW->Sminutes == 59) {
              Subsystem_DW->Stenths = 0U;
              Subsystem_DW->Sseconds = 0U;
              Subsystem_DW->Sminutes = 0U;
              tmp = (int32_T)(Subsystem_DW->Shours + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Subsystem_DW->Shours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 24U * 24U));
              Subsystem_DW->is_StopwatchCount = Subsystem_IN_Counting;
            } else {
              Subsystem_DW->Stenths = 0U;
              Subsystem_DW->Sseconds = 0U;
              tmp = (int32_T)(Subsystem_DW->Sminutes + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              Subsystem_DW->Sminutes = (uint8_T)tmp;
              Subsystem_DW->is_StopwatchCount = Subsystem_IN_Counting;
            }
          } else {
            Subsystem_DW->Stenths = 0U;
            tmp = (int32_T)(Subsystem_DW->Sseconds + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->Sseconds = (uint8_T)tmp;
            Subsystem_DW->is_StopwatchCount = Subsystem_IN_Counting;
          }
        } else {
          tmp = (int32_T)(Subsystem_DW->Stenths + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->Stenths = (uint8_T)tmp;
          Subsystem_DW->is_StopwatchCount = Subsystem_IN_Counting;
        }
      } else {
        if ((*sfEvent == Subsystem_event_plusbutton) && (*Subsystem_Y_mode == 3))
        {
          Subsystem_DW->is_StopwatchCount = Subsystem_IN_NotCounting;
        }
      }
    } else if ((*sfEvent == Subsystem_event_plusbutton) && (*Subsystem_Y_mode ==
                3)) {
      Subsystem_DW->is_StopwatchCount = Subsystem_IN_Counting;
    } else {
      if ((*sfEvent == Subsystem_event_Swatchmode) && (*Subsystem_Y_mode == 3))
      {
        Subsystem_DW->Stenths = 0U;
        Subsystem_DW->Sseconds = 0U;
        Subsystem_DW->Sminutes = 0U;
        Subsystem_DW->Shours = 0U;
        Subsystem_DW->is_StopwatchCount = Subsystem_IN_NotCounting;
      }
    }

    if (*sfEvent == Subsystem_event_Tick) {
      if (Subsystem_DW->tenths == 9) {
        if (Subsystem_DW->seconds == 59) {
          if (Subsystem_DW->minutes == 59) {
            Subsystem_DW->tenths = 0U;
            Subsystem_DW->seconds = 0U;
            Subsystem_DW->minutes = 0U;
            tmp = (int32_T)(Subsystem_DW->hours + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 24U * 24U));
          } else {
            Subsystem_DW->tenths = 0U;
            Subsystem_DW->seconds = 0U;
            tmp = (int32_T)(Subsystem_DW->minutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            Subsystem_DW->minutes = (uint8_T)tmp;
          }
        } else {
          Subsystem_DW->tenths = 0U;
          tmp = (int32_T)(Subsystem_DW->seconds + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          Subsystem_DW->seconds = (uint8_T)tmp;
        }
      } else {
        tmp = (int32_T)(Subsystem_DW->tenths + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        Subsystem_DW->tenths = (uint8_T)tmp;
      }
    }

    if (Subsystem_DW->is_Alarm == Subsystem_IN_Buzzing) {
      if (*sfEvent == Subsystem_event_Alarmmode) {
        Subsystem_DW->is_Alarm = Subsystem_IN_Silent;
      }
    } else {
      if ((Subsystem_DW->Ahours == Subsystem_DW->hours) &&
          (Subsystem_DW->Aminutes == Subsystem_DW->minutes)) {
        Subsystem_DW->is_Alarm = Subsystem_IN_Buzzing;
      }
    }
  }

  /* End of Chart: '<S1>/StopwatchAndrea ' */
}

/* Model step function */
void Subsystem_step(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
                    Subsystem_U_plusbutton, boolean_T Subsystem_U_minusbutton,
                    boolean_T Subsystem_U_timemode, boolean_T
                    Subsystem_U_timesetmode, boolean_T Subsystem_U_alarmmode,
                    boolean_T Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours,
                    uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
                    uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode)
{
  DW_Subsystem_T *Subsystem_DW = ((DW_Subsystem_T *) Subsystem_M->dwork);
  PrevZCX_Subsystem_T *Subsystem_PrevZCX = ((PrevZCX_Subsystem_T *)
    Subsystem_M->prevZCSigState);
  boolean_T zcEvent[7];
  int32_T sfEvent;
  boolean_T zcEvent_0;

  /* Chart: '<S1>/StopwatchAndrea ' incorporates:
   *  TriggerPort: '<S3>/input events'
   */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  zcEvent[0] = (((Subsystem_DW->Output_DSTATE != 0) !=
                 (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[0] == POS_ZCSIG)) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[0] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/plusbutton' */
  zcEvent[1] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[1] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_plusbutton) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[1] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/minusbutton' */
  zcEvent[2] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[2] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_minusbutton) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[2] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timemode' */
  zcEvent[3] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[3] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_timemode) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[3] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/timesetmode' */
  zcEvent[4] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[4] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_timesetmode) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[4] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/alarmmode' */
  zcEvent[5] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[5] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_alarmmode) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[5] !=
                 UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/swatchmode' */
  zcEvent[6] = (((Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[6] == POS_ZCSIG)
                 != (int32_T)Subsystem_U_swatchmode) &&
                (Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[6] !=
                 UNINITIALIZED_ZCSIG));
  zcEvent_0 = false;
  for (sfEvent = 0; sfEvent < 7; sfEvent++) {
    zcEvent_0 = (zcEvent_0 || zcEvent[sfEvent]);
  }

  if (zcEvent_0) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    if ((int8_T)(zcEvent[0] ? Subsystem_DW->Output_DSTATE != 0 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      sfEvent = Subsystem_event_Tick;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/plusbutton' */
    if ((int8_T)(zcEvent[1] ? Subsystem_U_plusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_plusbutton;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/minusbutton' */
    if ((int8_T)(zcEvent[2] ? Subsystem_U_minusbutton ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_minusbutton;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/timemode' */
    if ((int8_T)(zcEvent[3] ? Subsystem_U_timemode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_Timemode;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/timesetmode' */
    if ((int8_T)(zcEvent[4] ? Subsystem_U_timesetmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_Timesetmode;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/alarmmode' */
    if ((int8_T)(zcEvent[5] ? Subsystem_U_alarmmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_Alarmmode;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }

    /* Inport: '<Root>/swatchmode' */
    if ((int8_T)(zcEvent[6] ? Subsystem_U_swatchmode ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      sfEvent = Subsystem_event_Swatchmode;
      Subsyste_chartstep_c3_Subsystem(&sfEvent, Subsystem_Y_hours,
        Subsystem_Y_minutes, Subsystem_Y_seconds, Subsystem_Y_tenths,
        Subsystem_Y_mode, Subsystem_DW);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[0] = (ZCSigState)
    (Subsystem_DW->Output_DSTATE != 0);

  /* Inport: '<Root>/plusbutton' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[1] = Subsystem_U_plusbutton;

  /* Inport: '<Root>/minusbutton' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[2] = Subsystem_U_minusbutton;

  /* Inport: '<Root>/timemode' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[3] = Subsystem_U_timemode;

  /* Inport: '<Root>/timesetmode' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[4] = Subsystem_U_timesetmode;

  /* Inport: '<Root>/alarmmode' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[5] = Subsystem_U_alarmmode;

  /* Inport: '<Root>/swatchmode' */
  Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[6] = Subsystem_U_swatchmode;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  Subsystem_DW->Output_DSTATE++;

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  UnitDelay: '<S2>/Output'
   */
  if (Subsystem_DW->Output_DSTATE > 1) {
    Subsystem_DW->Output_DSTATE = 0U;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void Subsystem_initialize(RT_MODEL_Subsystem_T *const Subsystem_M, boolean_T
  *Subsystem_U_plusbutton, boolean_T *Subsystem_U_minusbutton, boolean_T
  *Subsystem_U_timemode, boolean_T *Subsystem_U_timesetmode, boolean_T
  *Subsystem_U_alarmmode, boolean_T *Subsystem_U_swatchmode, uint8_T
  *Subsystem_Y_hours, uint8_T *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds,
  uint8_T *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode)
{
  DW_Subsystem_T *Subsystem_DW = ((DW_Subsystem_T *) Subsystem_M->dwork);
  PrevZCX_Subsystem_T *Subsystem_PrevZCX = ((PrevZCX_Subsystem_T *)
    Subsystem_M->prevZCSigState);

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      Subsystem_PrevZCX->StopwatchAndrea_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* SystemInitialize for Chart: '<S1>/StopwatchAndrea ' */
    Subsystem_DW->is_Alarm = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Interface = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_AlarmSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->was_Stopwatch = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_TimeSet = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_StopwatchCount = Subsystem_IN_NO_ACTIVE_CHILD;
    Subsystem_DW->is_active_c3_Subsystem = 0U;
  }
}

/* Model data allocation function */
RT_MODEL_Subsystem_T *Subsystem(boolean_T *Subsystem_U_plusbutton, boolean_T
  *Subsystem_U_minusbutton, boolean_T *Subsystem_U_timemode, boolean_T
  *Subsystem_U_timesetmode, boolean_T *Subsystem_U_alarmmode, boolean_T
  *Subsystem_U_swatchmode, uint8_T *Subsystem_Y_hours, uint8_T
  *Subsystem_Y_minutes, uint8_T *Subsystem_Y_seconds, uint8_T
  *Subsystem_Y_tenths, uint8_T *Subsystem_Y_mode)
{
  RT_MODEL_Subsystem_T *Subsystem_M;
  Subsystem_M = (RT_MODEL_Subsystem_T *) malloc(sizeof(RT_MODEL_Subsystem_T));
  if (Subsystem_M == NULL) {
    return NULL;
  }

  (void) memset((char *)Subsystem_M, 0,
                sizeof(RT_MODEL_Subsystem_T));

  /* states (dwork) */
  {
    DW_Subsystem_T *dwork = (DW_Subsystem_T *) malloc(sizeof(DW_Subsystem_T));
    rt_VALIDATE_MEMORY(Subsystem_M,dwork);
    Subsystem_M->dwork = (dwork);
  }

  /* previous zero-crossing states */
  {
    PrevZCX_Subsystem_T *zc = (PrevZCX_Subsystem_T *) malloc(sizeof
      (PrevZCX_Subsystem_T));
    rt_VALIDATE_MEMORY(Subsystem_M,zc);
    Subsystem_M->prevZCSigState = (zc);
  }

  {
    DW_Subsystem_T *Subsystem_DW = ((DW_Subsystem_T *) Subsystem_M->dwork);
    PrevZCX_Subsystem_T *Subsystem_PrevZCX = ((PrevZCX_Subsystem_T *)
      Subsystem_M->prevZCSigState);

    /* states (dwork) */
    (void) memset((void *)Subsystem_DW, 0,
                  sizeof(DW_Subsystem_T));

    /* external inputs */
    *Subsystem_U_plusbutton = false;
    *Subsystem_U_minusbutton = false;
    *Subsystem_U_timemode = false;
    *Subsystem_U_timesetmode = false;
    *Subsystem_U_alarmmode = false;
    *Subsystem_U_swatchmode = false;

    /* external outputs */
    (*Subsystem_Y_hours) = 0U;
    (*Subsystem_Y_minutes) = 0U;
    (*Subsystem_Y_seconds) = 0U;
    (*Subsystem_Y_tenths) = 0U;
    (*Subsystem_Y_mode) = 0U;

    /* previous zero-crossing states */
    {
    }
  }

  return Subsystem_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
