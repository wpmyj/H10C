/*

 */

#include "led.h"

void LED_Red(int ctrl)
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

void LED_Green(int ctrl)
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

void LED_Yellow(int ctrl)
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

/* END OF FILE */
