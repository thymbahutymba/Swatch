/*
 * WidgetConfig.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "pictures.h"
#include <stdio.h>
#include "stm32f4_discovery_lcd.h"
#include "fonts.h"

ButtonIcon buttontime = {
		icontime_on, icontime_off, TIMEMODE
};

ButtonIcon buttontimeset = {
		icontimeset_on, icontimeset_off, TIMESETMODE
};

ButtonIcon buttonalarm = {
		iconalarm_on, iconalarm_off, ALARMMODE
};

ButtonIcon buttonswatch = {
		iconswatch_on, iconswatch_off, SWATCHMODE
};

ButtonIcon buttonplus = {
		0, 0, PLUS
};

ButtonIcon buttonminus = {
		0, 0, MINUS
};

Text txt = {
		&Font32x48, White
};

Text stxt = {
		&Font24x36, White
};

Image backg = {
	ImageBuffer
};

const Widget MyWatchScr[NUMWIDGETS] = {
		{0, 0, 320, 240, BACKGROUND, (void *)&backg},
		{16, 180, 60, 60, BUTTONICON, (void *)&buttontime},
		{92, 180, 60, 60, BUTTONICON, (void *)&buttontimeset},
		{168, 180, 60, 60, BUTTONICON, (void *)&buttonalarm},
		{244, 180, 60, 60, BUTTONICON, (void *)&buttonswatch},
		{244, 10, 60, 60, BUTTONICON, (void *)&buttonplus},
		{244, 80, 60, 60, BUTTONICON, (void *)&buttonminus},

		{30, 70, 200, 50, TEXT, (void *)&txt},
		{50, 70, 180, 50, TEXT, (void *)&stxt},
		{76, 70, 5, 50, TEXT, (void *)&txt},
		{140, 70, 5, 50, TEXT, (void *)&txt},
		{87, 70, 5, 50, TEXT, (void *)&stxt},
		{135, 70, 5, 50, TEXT, (void *)&stxt},
		{183, 70, 5, 50, TEXT, (void *)&stxt},
};
