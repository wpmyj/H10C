/*
		@filename	: led.c
		@author		: Will Fu
		@date			: 2016-10-22
		@desc			: 基本输出驱动
		@maodify	: 2016-10-22 setup
		@version	: 1.0
 */

#include "led.h"

void LED_Red(bit ctrl)
{
	if(OFF == ctrl)
	{
		LED_R = 1;
	}
	else
	{
		LED_R = 0;
	}
}

void LED_Green(bit ctrl)
{
	if(OFF == ctrl)
	{
		LED_G = 1;
	}
	else
	{
		LED_G = 0;
	}
}

void LED_Yellow(bit ctrl)
{
	if(OFF == ctrl)
	{
		LED_Y = 1;
	}
	else
	{
		LED_Y = 0;
	}
}

void sensor_ctrl(bit ctrl)
{
	if(OFF == ctrl)
	{
		Sensor = 1;
	}
	else
	{
		Sensor = 0;
	}
}

void beep_ctrl(bit ctrl)
{
	if(OFF == ctrl)
	{
		Beep = 1;
	}
	else
	{
		Beep = 0;
	}
}
/* END OF FILE */
