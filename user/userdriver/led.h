/**
	*	@filename	: led.c
	*	@author		: Will Fu
	*	@date			: 2016-10-22
	*	@brief		: 基本输出驱动
	*	@maodify	: 2016-10-22 setup
	*	@version	: 1.0
	*/

#ifndef LED_H
#define LED_H

#include "N76E003.h"
#include "Define.h"
#include "Function_define.h"

#define ON	1
#define OFF	0

sbit LED_R 	= P1^2;
sbit LED_G 	= P1^1;
sbit LED_Y 	= P1^3;

sbit Sensor = P1^5;	
sbit Beep		= P1^4;	 
sbit Relay	= P0^1;
sbit Valve	= P0^0;

sbit Key		= P1^0;

void led_init(void);
void LED_Red(bit ctrl);
void LED_Green(bit ctrl);
void LED_Yellow(bit ctrl);
void sensor_ctrl(bit ctrl);
void beep_ctrl(bit ctrl);
void relay_ctrl(bit ctrl);
void valve_ctrl(bit ctrl);
bit read_key(void);

#endif

/* END OF FILE */
