/**
  *	@filename	: uart.c
  *	@author		: Will Fu
  *	@date		: 2016-11-16
  *	@brief		: uart驱动
  *	@maodify	: 2016-11-16 setup
  *	@version	: 1.0
  */

#include "uart.h"

extern uint8_t err;
extern uint8_t errs[3];

/******************************************************************************
	函数名称：uart0_init
	函数说明：uart0初始化
	输入参数:	无
	返回参数:	无
******************************************************************************/
void uart0_init(void)
{
	P06_Quasi_Mode;						 	/* 引脚配置 */
	P07_Quasi_Mode;
	InitialUART0_Timer1(9600);
}

/******************************************************************************
	函数名称：uart0_send_byte
	函数说明：uart0发送一个字节
	输入参数:	无
	返回参数:	无
******************************************************************************/
void uart0_send_byte(uint8_t c)
{
	TI = 0;
	SBUF = c;
	while(TI==0);
	err += c;
}

/******************************************************************************
	函数名称：print_ad
	函数说明：打印AD值
	输入参数:	无
	返回参数:	无
******************************************************************************/
void print_ad(uint16_t ad_val)
{	
	if(ad_val >= 1000)
	{
		uart0_send_byte('0' + ad_val / 1000);
		uart0_send_byte('0' + ad_val / 100 % 10);
		uart0_send_byte('0' + ad_val / 10 % 10);
		uart0_send_byte('0' + ad_val % 10);
	}
	else if(ad_val >= 100)
	{
		uart0_send_byte('0' + ad_val / 100);
		uart0_send_byte('0' + ad_val / 10 % 10);
		uart0_send_byte('0' + ad_val % 10);
	}
	else if(ad_val >= 10)
	{
		uart0_send_byte('0' + ad_val / 10);
		uart0_send_byte('0' + ad_val % 10);
	}
	else
	{
		uart0_send_byte('0' + ad_val);
	}
		
}

/******************************************************************************
	函数名称：uart0_send_string
	函数说明：uart0发送字符串
	输入参数:	无
	返回参数:	无
******************************************************************************/
void uart0_send_string(uint8_t *dat)
{
	while(*dat != '\0')
	{
		uart0_send_byte(*dat);
		dat++;
	}
}

/******************************************************************************
	函数名称：toHex
	函数功能：只有4位，进来的只可能是0-9,A-F。0-9进来,变30-39
						A-F进来,变41-46
	输入参数：无
	返回参数：校验字
******************************************************************************/
uint8_t toHex(uint8_t t)
{
	if (t < 10)
		t += 0x30;
	else 
		t += (0x41-10);
	
	return t;
}

/******************************************************************************
	函数名称：send_errs
	函数说明：发送校验码
	输入参数:	无
	返回参数:	无
******************************************************************************/
void send_errs(void)
{
	err = (uint8_t)(-(signed char)err); 

	errs[0] = toHex(err >> 4);
	errs[1] = toHex(err & 0x0f);
	errs[2] = '\0';
	uart0_send_byte(0x09);
	uart0_send_string(errs);
	uart0_send_byte(0x0d);
	uart0_send_byte(0x0a);
}
/* END OF FILE */
