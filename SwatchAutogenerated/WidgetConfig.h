/*
 * WidgetConfig.h
 *
 *  Created on: 22/ott/2015
 *      Author: admim
 */

#ifndef WIDGETCONFIG_H_
#define WIDGETCONFIG_H_

#define NUMWIDGETS 14

#define BAKCG 0
#define BTIME 1
#define BTIMESET 2
#define BALARM 3
#define BSWATCH 4
#define BPLU 5
#define BMINUS 6
#define BIG 7
#define SMALL 8
#define BSEP1 9
#define BSEP2 10
#define SSEP1 11
#define SSEP2 12
#define SSEP3 13

#define TIMEMODE 0x01
#define TIMESETMODE 0x02
#define ALARMMODE 0x04
#define SWATCHMODE 0x08
#define PLUS 0x10
#define MINUS 0x20

extern const Widget MyWatchScr[NUMWIDGETS];

#endif /* WIDGETCONFIG_H_ */
