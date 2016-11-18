/**
	*	@filename	: uart.h
	*	@author		: Will Fu
	*	@date			: 2016-11-16
	*	@brief		: uartÇý¶¯
	*	@maodify	: 2016-11-16 setup
	*	@version	: 1.0
	*/

#ifndef UART_H
#define UART_H

#include "N76E003.h"
#include "Define.h"
#include "Common.h"
#include "Function_define.h"

extern uint8_t err;

void uart0_init(void);
void uart0_send_byte(uint8_t c);
void uart0_send_string(uint8_t *dat);
uint8_t toHex(uint8_t t);
void send_errs(void);
void print_ad(uint16_t ad_val);

#endif

/* END OF FILE */
