/*
 
 */

#ifndef LED_H
#define LED_H

#include "N76E003.h"

#define ON	1
#define OFF	0

sbit LED_R = P1^2;
sbit LED_G = P1^0;
sbit LED_Y = P1^3;	

void LED_Red(int ctrl);
void LED_Green(int ctrl);
void LED_Yellow(int ctrl);

#endif

/* END OF FILE */
