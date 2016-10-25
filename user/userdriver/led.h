/*
		@filename	: led.c
		@author		: Will Fu
		@date			: 2016-10-22
		@desc			: 基本输出驱动
		@maodify	: 2016-10-22 setup
		@version	: 1.0
 */

#ifndef LED_H
#define LED_H

#include "N76E003.h"

#define ON	1
#define OFF	0

sbit LED_R 	= P1^2;
sbit LED_G 	= P1^0;
sbit LED_Y 	= P1^3;

sbit Sensor = P1^5;	
sbit Beep		= P0^1;

void LED_Red(bit ctrl);
void LED_Green(bit ctrl);
void LED_Yellow(bit ctrl);
void sensor_ctrl(bit ctrl);
void beep_ctrl(bit ctrl);

#endif

/* END OF FILE */
