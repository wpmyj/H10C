/**
	*	@filename	: led.h
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
#include "Common.h"
#include "Function_define.h"

#define ON	1
#define OFF	0

sbit LED_R 	= P1^1;
sbit LED_G 	= P1^3;
sbit LED_Y 	= P1^4;

sbit Sensor = P0^5;	
sbit Beep	= P0^1;	 
sbit Relay	= P1^0;
sbit Valve	= P0^0;

sbit Key	= P1^2;

void led_init(void);
void LED_Red(bit ctrl);
void LED_Green(uint8_t ctrl);
void LED_Yellow(bit ctrl);
void sensor_ctrl(bit ctrl);
void beep_ctrl(uint8_t ctrl);
void relay_ctrl(bit ctrl);
void valve_ctrl(bit ctrl);
bit read_key(void);

#endif

/* END OF FILE */
