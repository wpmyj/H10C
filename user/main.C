/**
	*	@filename		: main.c
	*	@author			: Will Fu
	*	@date				: 2016-10-25
	*	@brief			:
	*	@modify			: 2016-10-25 setup
	*	@version		: 1.0
 */

#include "main.h"

void sys_init(void);

/******************************************************************************
	函数名称：
	函数说明：
	输入参数:
	输出参数:
******************************************************************************/
void main (void) 
{
	sys_init();  

  while(1)
  {
		if(read_key() == ON)
		{
			beep_ctrl(ON);
		}
		else
		{
			beep_ctrl(OFF);
		}
//		LED_Green(ON);
//		beep_ctrl(ON);											
//		Timer3_Delay1ms(1000);
//		LED_Red(ON);											
//		Timer3_Delay1ms(300);
//		LED_Yellow(ON);											
//		Timer3_Delay1ms(300);
//		beep_ctrl(OFF);
//		LED_Green(OFF);											
//		Timer3_Delay1ms(1000);
//		LED_Red(OFF);											
//		Timer3_Delay1ms(300);
//		LED_Yellow(OFF);											
//		Timer3_Delay1ms(1000);
//		printf ("Hello\r\n");
//		relay_ctrl(ON);
//		Timer3_Delay1ms(1000);
//		relay_ctrl(OFF);
//		Timer3_Delay1ms(1000);
//		valve_ctrl(ON);
//		Timer3_Delay1ms(1000);
//		valve_ctrl(OFF);
//		Timer3_Delay1ms(1000);
//		sensor_ctrl(ON);
//		printf("sensor open.\n");
//		printf("%d\n", get_adc_val(6));
//		printf("%d\n", get_adc_val(7));
//		sensor_ctrl(OFF);
//		printf("sensor close.\n");
//		printf("%d\n", get_adc_val(6));
//		printf("%d\n", get_adc_val(7));
  }
}

/******************************************************************************
	函数名称：
	函数说明：
	输入参数:
	输出参数:
******************************************************************************/
void sys_init(void)
{
	led_init();
	InitialUART0_Timer1(9600);
	set_CLOEN;
}

/* END OF FILE */
