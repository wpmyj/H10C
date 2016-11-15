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
void self_check(void);

/******************************************************************************
	函数名称：main
	函数说明：主程序
	输入参数:	无
	输出参数:	无
******************************************************************************/
void main(void) 
{	
  uint8_t test1 = 0x56;
	uint16_t test2 = 0x1234;
	uint8_t test3 = 0, test4 = 0;
	uint16_t test5 = 0;
	uint16_t CH4_cali = 0;

	sys_init(); 
	self_check(); 
	
  while(1)
  {
		printf("Hello\r\n");
		printf("test1 = %x\r\n", test1);
		printf("test1 = %bx\r\n", test1);
		printf("test2 = %bx\r\n", test2);
		printf("test2 = %x\r\n", test2);
		write_DATAFLASH_BYTE(0x3870, 0xAA);
		write_DATAFLASH_BYTE(0x3871, 0x55);
		test3 = read_APROM_BYTE(0x3870);
		test4 = read_APROM_BYTE(0x3871);
		test5 = (uint16_t)test3;
		test5 = (test5 << 8) | (uint16_t)test4;
		printf("test3 = %bx\r\n", test3);
		printf("test4 = %bx\r\n", test4);
		printf("test5 = %x\r\n", test5);
		
		write_CH4_calibration(0x8877);
		CH4_cali = read_CH4_calibration();
		printf("CH4_calibration = %x\r\n", CH4_cali);
//		if(read_key() == ON)
//		{
//			beep_ctrl(ON);
//		}
//		else
//		{
//			beep_ctrl(OFF);
//		}
		LED_Green(ON);
//		beep_ctrl(ON);											
		Timer3_Delay1ms(1000);
//		LED_Red(ON);											
//		Timer3_Delay1ms(300);
//		LED_Yellow(ON);											
//		Timer3_Delay1ms(300);
//		beep_ctrl(OFF);
		LED_Green(OFF);											
		Timer3_Delay1ms(1000);
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
	函数名称：sys_init
	函数说明：系统初始化
	输入参数:	无
	输出参数:	无
******************************************************************************/
void sys_init(void)
{
	led_init();
	InitialUART0_Timer1(9600);
	set_CLOEN;
}

/******************************************************************************
	函数名称：self_check
	函数说明：自检
	输入参数:	无
	输出参数:	无
******************************************************************************/
void self_check(void)
{
	LED_Green(ON);
	Timer3_Delay1ms(500);
	LED_Green(OFF);
  LED_Red(ON);
	Timer3_Delay1ms(500);
	LED_Red(OFF);
	LED_Yellow(ON);
	Timer3_Delay1ms(500);
	LED_Yellow(OFF);
	beep_ctrl(ON);
	Timer3_Delay1ms(500);
	beep_ctrl(OFF);
}

/* END OF FILE */
