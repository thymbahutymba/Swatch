/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

#include "ee.h"
#include "ee_irq.h"
#include <stdio.h>
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "stm32f4xx.h"

#include "STMPE811QTR.h"
#include "pictures.h"
#include "Widget.h"
#include "WidgetConfig.h"
#include "Touch.h"
#include "Event.h"
#include "Subsystem.h"
#include "lcd_add.h"
#include "fonts.h"
#include "debug.h"


RT_MODEL_Subsystem_T *Subsystem_M;
uint8_T hours=0, minutes=0, seconds=0, tenths=0, mode;
boolean_T plusbutton, minusbutton, timemode, timesetmode, alarmmode, swatchmode;

/*
 * SysTick ISR2
 */
ISR2(systick_handler)
{
	/* count the interrupts, waking up expired alarms */
	CounterTick(myCounter);
}

/*
 * TASK LCD
 */
TASK(TaskLCD)
{
	unsigned int px, py;
	TPoint p;
	if (GetTouch_SC_Async(&px, &py)) {
		p.x = px;
		p.y = py;
		OnTouch(MyWatchScr, &p);
	}
}

/*
 * TASK Clock
 */
void UpdateMode(unsigned char om, unsigned char m)
{
	switch(om) {
	case 2:
		DrawOff(&MyWatchScr[BALARM]);
		break;
	case 1:
		DrawOff(&MyWatchScr[BTIMESET]);
		break;
	case 0:
		DrawOff(&MyWatchScr[BTIME]);
		break;
	case 3:
		DrawOff(&MyWatchScr[BSWATCH]);
		break;
	}
	switch(m) {
	case 2:
		DrawOn(&MyWatchScr[BALARM]);
		break;
	case 1:
		DrawOn(&MyWatchScr[BTIMESET]);
		break;
	case 0:
		DrawOn(&MyWatchScr[BTIME]);
		break;
	case 3:
		DrawOn(&MyWatchScr[BSWATCH]);
		break;
	}
}

TASK(TaskClock)
{
	unsigned char i;
	static int oldmode=8;
	char tstr[3];

	Subsystem_step(Subsystem_M,
			IsEvent(PLUS), IsEvent(MINUS), IsEvent(TIMEMODE),
			IsEvent(TIMESETMODE), IsEvent(ALARMMODE), IsEvent(SWATCHMODE),
			&hours, &minutes, &seconds, &tenths, &mode);

	ClearEvents();

	LCD_SetTextColor(Black);
	LCD_SetBackColor(Black);
	LCD_DrawFullRect(28, 60, 200, 60);
	switch (mode) {
	case 0:
		// Time mode
		sprintf(tstr, "%02i%02i%02i", hours, minutes, seconds);
		WPrint(&MyWatchScr[BIG], tstr);
		WPrint(&MyWatchScr[BSEP1], ":");
		WPrint(&MyWatchScr[BSEP2], ":");
		break;
	case 3:
		// stopwatch mode
		sprintf(tstr, "%02i%02i%02i%i", hours, minutes, seconds, tenths);
		WPrint(&MyWatchScr[SMALL], tstr);
		WPrint(&MyWatchScr[SSEP1], ":");
		WPrint(&MyWatchScr[SSEP2], ":");
		WPrint(&MyWatchScr[SSEP3], ".");
		break;
	default:
		// timeset mode or alarmset mode
		sprintf(tstr, "%02i%02i", hours, minutes);
		WPrint(&MyWatchScr[BIG], tstr);
		WPrint(&MyWatchScr[BSEP1], ":");
	}

	if (mode != oldmode) {
		UpdateMode(oldmode, mode);
		oldmode = mode;
	}
}

/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */



/*
 * MAIN TASK
 */
int main(void)
{
	//GPIO_InitTypeDef GPIO_InitStructure;

	SystemInit();
  /*Initializes Erika related stuffs*/
	EE_system_init();

  /* init state machine */
	Subsystem_M = Subsystem(
			&plusbutton, &minusbutton, &timemode, &timesetmode, &alarmmode, &swatchmode,
			&hours, &minutes, &seconds, &tenths, &mode);

	Subsystem_initialize(Subsystem_M,
	  &plusbutton, &minusbutton, &timemode, &timesetmode, &alarmmode, &swatchmode,
	  &hours, &minutes, &seconds, &tenths, &mode);

	/*Initialize systick */
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, SystemCoreClock));
	EE_systick_enable_int();
	EE_systick_start();

	/* Initializes LCD and touchscreen */
	IOE_Config();
	/* Initialize the LCD */
	STM32f4_Discovery_LCD_Init();

//	LCD_Clear(White);

	/* Set the LCD Text size */
	//	LCD_SetFont(&Font8x12);
	//Lcd_Touch_Calibration();
	InitTouch(-0.102, 0.0656, -335, 10);

	//InitTouch(-0.9, 0.5, -355, 14);

	/* Draw the background */
	DrawInit(MyWatchScr);
	//LCD_SetTextColor(Black);
	//LCD_SetBackColor(Black);
	//LCD_DrawFullRect(28, 62, 200, 56);

	/* Program cyclic alarms which will fire after an initial offset,
	 * and after that periodically
	 * */
	SetRelAlarm(AlarmTaskLCD, 10, 50);
	SetRelAlarm(AlarmTaskClock, 10, 100);

  /* Forever loop: background activities (if any) should go here */
	for (;;) { 
	}

}


