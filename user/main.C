/*
	@filename		: main.c
	@author			: Will Fu
	@date				: 2016-10-25
	@desc				:
	@modify			: 2016-10-25 setup
	@version		: 1.0
 */

#include "main.h"

void sys_init(void);

void main (void) 
{
	sys_init();  
  	
  while(1)
  {
		LED_Green(ON);											
		Timer3_Delay1ms(300);
		LED_Red(ON);											
		Timer3_Delay1ms(300);
		LED_Yellow(ON);											
		Timer3_Delay1ms(300);
		LED_Green(OFF);											
		Timer3_Delay1ms(300);
		LED_Red(OFF);											
		Timer3_Delay1ms(300);
		LED_Yellow(OFF);											
		Timer3_Delay1ms(2000);
		printf ("Hello\r\n");
		printf("%d\n", get_adc_val(6));
		printf("%d\n", get_adc_val(7));
  }
}

void sys_init(void)
{
	Set_All_GPIO_Quasi_Mode;
	InitialUART0_Timer1(9600);
	set_CLOEN;
}

/* END OF FILE */
