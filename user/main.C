/**
	*	@filename		: main.c
	*	@author			: Will Fu
	*	@date				: 2016-10-25
	*	@brief			:	MCU型号N76E003
	*								UART1使用Timer1
	*								延时使用Timer3
	*	@modify			: 2016-10-25 setup
	*	@version		: 1.0
  */

#include "main.h"

extern CaliInfo CH4_info;

uint8_t *sys_info = "H10C_STD_V1.0_20161107\r\n";

uint8_t sys_state = 0;	/* 0--自检　1--预热 2--正常 3--报警 4--故障 5--标定 */
uint16_t adc_CH4 = 0, adc_power = 0;
uint8_t alarm_flag = 0; /* 报警切阀标志 */
uint8_t err = 0;				/* 校验 */

void sys_init(void);
void self_check(void);
void pre_heat(void);
void normal_state(void);
void alarm_state(void);
void error_state(void);
void calibration_state(void);
void get_data(void);
void data_process(void);
void data_report(void);

/******************************************************************************
	函数名称：main
	函数说明：主程序
	输入参数:	无
	返回参数:	无
******************************************************************************/
void main(void) 
{	
	sys_init(); 
	
  while(1)
  {
		get_data();
		data_process();
		data_report();
  }
}

/******************************************************************************
	函数名称：sys_init
	函数说明：系统初始化
	输入参数:	无
	返回参数:	无
******************************************************************************/
void sys_init(void)
{
	led_init();
	uart0_init();
	set_CLOEN;
//	timer_init();

	printf(sys_info); 
	calibration_init();
	printf("value = 0x%x, flag = 0x%bx\r\n", CH4_info.value, CH4_info.flag);
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

/******************************************************************************
	函数名称：pre_heat
	函数说明：预热　预热期间绿色指示灯闪烁周期1秒，按自检键可退出预热。
	输入参数:	无
	返回参数:	无
******************************************************************************/
void pre_heat(void)
{
	uint16_t i;

	sensor_ctrl(ON);		/* 给传感器供电 */

	for(i = 0; i < 360; i++)
	{
		if(i % 2 == 0)
		{
			LED_Green(ON);
		}
		else
		{
			LED_Green(OFF);
		}

		if(read_key() == ON)
		{
			Timer3_Delay1ms(20);

			if(read_key() == ON)
			{
				break;
			}
		}
			
		Timer3_Delay1ms(500);
	}
} 

/******************************************************************************
	函数名称：normal_process
	函数说明：正常状态处理
	输入参数:	无
	返回参数:	无
******************************************************************************/
void normal_state(void)
{
	alarm_flag = 0;
	beep_ctrl(OFF);
	valve_ctrl(OFF);
	relay_ctrl(OFF);
	LED_Red(OFF);
	LED_Yellow(OFF);
	LED_Green(ON);
	
	if(ON == read_key())
	{
		while(ON ==read_key());
		self_check();
	}	
}

/******************************************************************************
	函数名称：alarm_process
	函数说明：报警状态处理
	输入参数:	无
	返回参数:	无
******************************************************************************/
void alarm_state(void)
{
	LED_Yellow(OFF);
	LED_Green(ON);				/* 绿色指示灯长亮 */
	LED_Red(ON);					/* 红色指示灯长亮 */
	relay_ctrl(ON);				/* 继电器打开 */
	beep_ctrl(ON);

	if(0 == alarm_flag)		/* 切阀 */
	{
		valve_ctrl(ON);
		Timer3_Delay1ms(2000);
		valve_ctrl(OFF);
		alarm_flag = 1;
	}
}

/******************************************************************************
	函数名称：error_process
	函数说明：故障状态处理
	输入参数:	无
	返回参数:	无
******************************************************************************/
void error_state(void)
{
	LED_Red(OFF);
	LED_Green(OFF);
	LED_Yellow(ON);				/* 黄色指示灯长亮 */
	beep_ctrl(ON);
}

/******************************************************************************
	函数名称：calibration_process
	函数说明：标定状态处理
	输入参数:	无
	返回参数:	无
******************************************************************************/
void calibration_state(void)
{
		
}
/******************************************************************************
	函数名称：Timer0_ISR
	函数说明：timer0中断子程序  实测500ms
	输入参数:	无
	返回参数:	无
******************************************************************************/
//uint8_t timer0_cnt = 0;
//void Timer0_ISR (void) interrupt 1
//{ 
//	TH0 = TH0_INIT;
//  TL0 = TL0_INIT;
//
//	if(timer0_cnt < 132)
//	{
//		timer0_cnt++;
//	}
//	else
//	{
//		timer0_cnt = 0;
//	} 
//}

/******************************************************************************
	函数名称：get_data
	函数说明：获取传感器电源及甲烷AD值数据
						报警判断：
						adc_CH4 > 报警设定值
						故障判断：
						传感器短路与开路判断
						(1,3)--(4,5,6) 	adc_CH4 = 4095
						(2)--(4,5,6)		adc_power = 4095 adc_CH4 < 100
						(1,3)-(2)				adc_CH4 = adc_power
						开路						adc_CH4 = 0
	输入参数:	无
	返回参数:	无
******************************************************************************/
void get_data(void)
{
	uint16_t CH4_data_temp[12] = {0}, power_data_temp[12] = {0};
	uint16_t CH4_data_sum = 0, power_data_sum = 0;
	uint8_t i;
	uint16_t adc_delta = 0;

	for(i = 0; i < 12; i++)
	{
		CH4_data_temp[i] = get_adc_val(6);
		Timer3_Delay1ms(20);
		power_data_temp[i] = get_adc_val(5);
		Timer3_Delay1ms(20);

		CH4_data_sum += CH4_data_temp[i];
		power_data_sum += power_data_temp[i];
	}

	adc_CH4 = CH4_data_sum / 12;
	adc_power = power_data_sum / 12;

	if(adc_CH4 > adc_power)
	{
		adc_delta = adc_CH4 - adc_power;
	}
	else
	{
		adc_delta = adc_power - adc_CH4;
	}

	switch(sys_state)
	{
		case 0	: break;
		case 1	: break;
		case 2	: if(adc_power >= 200 && adc_power < 300)
							{
								if(adc_CH4 > CH4_info.value)
								{
									sys_state = 3;
								}
							}
							
							if(adc_power > 500)	/* 传感器(2)--(4,5,6)短路 */
							{
								sys_state = 4;	
							}
						
							if(adc_CH4 < 20)		/* 传感器开路 */
							{
								sys_state = 4;
							}
							else if(adc_CH4 > 4050)	/* 传感器(1,3)--(4,5,6)短路 */
							{
								sys_state = 4;			
							}
						
							/* (2)--(1,3)短路 */
							if(adc_delta < 10)		
							{
								sys_state = 4;
							}
							break;
		case 3	: if(adc_CH4 < CH4_info.value)
							{
								sys_state = 2;
							}
							break;
		case 4	: if(adc_power >= 200 && adc_power < 300)
							{
								if(adc_CH4 < CH4_info.value)
								{
									sys_state = 2;
								}
								else if(adc_CH4 >= CH4_info.value && adc_CH4 < 4050)
								{
									sys_state = 3;
								}
							}
							break;
		case 5	: sys_state = 2;
							break;
		default	: sys_state = 2;
							break;
	}
}

/******************************************************************************
	函数名称：data_report
	函数说明：数据输出
	输入参数:	无
	返回参数:	无
******************************************************************************/
void data_report(void)
{
	printf("Power = %d\r\n", adc_power);
	printf("AD = %d\r\n", adc_CH4);

	Timer3_Delay1ms(500);
}

/******************************************************************************
	函数名称：data_process
	函数说明：数据处理
	输入参数:	无
	返回参数:	无
******************************************************************************/
void data_process(void)
{
	switch(sys_state)
	{
		case 0	: self_check();
							sys_state = 1;	
							break;
		case 1	: pre_heat();
							sys_state = 2;
							break;
		case 2	: normal_state();
							break;
		case 3	: alarm_state();
							break;
		case 4	: error_state();
							break;
		case 5	: calibration_state();
							break;
		default	: break;
	}	
}

/* END OF FILE */
