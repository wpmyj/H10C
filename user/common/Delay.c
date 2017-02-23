/**
  *	@filename	: Delay.c
  *	@author		: Will Fu
  *	@date		: 2016-11-16
  *	@brief		: 延时子程序
  *	@maodify	: 2016-11-16 setup
  *	@version	: 1.0
  */

#include "Delay.h"

/*******************************************************
函数名称：delay_100us
函数功能：软件延时100us程序
		  MCU频率：内部时钟12MHz
输入参数：无
返回参数：无
*******************************************************/
void delay_100us(void)
{
	uint8_t i, j;

	i = 2;
	j = 139;

	do
	{
		while (--j);
	} 
	while (--i);
}

/*******************************************************
函数名称：DelayMs
函数功能：软件延时ms程序
		  MCU频率：内部时钟12MHz
输入参数：nMs
返回参数：无
*******************************************************/
void delay_ms(uint16_t nMs)
{
	uint16_t i, j;
	
	for(i = 0; i < nMs; i++)
		for(j = 0; j < 10; j++)
			delay_100us();
}

/* END OF FILE */
