/**
	*	@filename	: led.c
	*	@author		: Will Fu
	*	@date			: 2016-10-22
	*	@brief		: 基本输出驱动
	*	@maodify	: 2016-10-22 setup
	*	@version	: 1.0
	*/

#include "led.h"

/******************************************************************************
	函数名称：led_init
	函数说明：基本输入输出引脚初始化
	输入参数:	无
	返回参数:	无
******************************************************************************/
void led_init(void)
{
	P00_PushPull_Mode;
	P01_PushPull_Mode;
	P11_PushPull_Mode;
	P12_PushPull_Mode;
	P13_PushPull_Mode;
	P14_PushPull_Mode;
	P15_PushPull_Mode;

	P10_Input_Mode;	

	LED_Red(OFF);
	LED_Green(OFF);
	LED_Yellow(OFF);
	sensor_ctrl(OFF);
	beep_ctrl(OFF);
	relay_ctrl(OFF);
	valve_ctrl(OFF);
}

/******************************************************************************
	函数名称：LED_Red
	函数说明：红色报警指示灯控制
	输入参数:	ON--点亮 OFF--熄灭
	输出参数:	无
******************************************************************************/
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

/******************************************************************************
	函数名称：LED_Green
	函数说明：绿色正常指示灯控制
	输入参数:	ON--点亮 OFF--熄灭
	输出参数:	无
******************************************************************************/
void LED_Green(uint8_t ctrl)
{
	if(OFF == ctrl)
	{
		LED_G = 1;
	}
	else if(ON == ctrl)
	{
		LED_G = 0;
	}
	else
	{
		LED_G = ~LED_G;
	}
}

/******************************************************************************
	函数名称：LED_Yellow
	函数说明：黄色故障指示灯控制
	输入参数:	ON--点亮 OFF--熄灭
	输出参数:	无
******************************************************************************/
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

/******************************************************************************
	函数名称：sensor_ctrl
	函数说明：控制传感器加热
	输入参数:	ON--传感器加热　OFF--传感器不加热
	输出参数:	无
******************************************************************************/
void sensor_ctrl(bit ctrl)
{
	if(OFF == ctrl)
	{
		Sensor = 0;
	}
	else
	{
		Sensor = 1;
	}
}

/******************************************************************************
	函数名称：beep_ctrl
	函数说明：蜂鸣器控制
	输入参数:	ON--鸣响　OFF--不响	 其他--翻转
	输出参数:	无
******************************************************************************/
void beep_ctrl(uint8_t ctrl)
{
	if(OFF == ctrl)
	{
		Beep = 0;
	}
	else if(ON == ctrl)
	{
		Beep = 1;
	}
	else
	{
		Beep = ~Beep;
	}
}

/******************************************************************************
	函数名称：relay_ctrl
	函数说明：继电器控制
	输入参数:	ON--输出节点闭合　OFF--输出节点打开
	输出参数:	无
******************************************************************************/
void relay_ctrl(bit ctrl)
{
	if(OFF == ctrl)
	{
		Relay = 0;
	}
	else
	{
		Relay = 1;
	}
}

/******************************************************************************
	函数名称：valve_ctrl
	函数说明：电磁阀控制
	输入参数:	ON--电磁阀闭合　OFF--电磁阀不动作
	输出参数:	无
******************************************************************************/
void valve_ctrl(bit ctrl)
{
	if(OFF == ctrl)
	{
		Valve = 1;
	}
	else
	{
		Valve = 0;
	}
}

/******************************************************************************
	函数名称：read_key
	函数说明：读取按键信息
	输入参数:	无
	输出参数:	ON--按键按下　OFF--按键未按下
******************************************************************************/
bit read_key(void)
{
	if(Key == 0)
		return ON;
	else
		return OFF;
}

/* END OF FILE */
