/**
	*	@filename		: timer.c
	*	@author			: Will Fu
	*	@date				: 2016-11-15
	*	@brief			:
	*	@modify			: 2016-11-15 setup
	*	@version		: 1.0
	*/

#include "timer.h"
extern uint16_t timer0_cnt;
/******************************************************************************
	函数名称：timer_init
	函数说明：timer初始化	timer0定时900ms中断
	输入参数:	无
	返回参数:	无
******************************************************************************/
void timer_init(void)
{
	TIMER0_MODE1_ENABLE;

	clr_T0M;

	TH0 = TH0_INIT;
	TL0 = TL0_INIT;

	clr_PT0H;								/* 设置定时器0中断优先级为0(最低优先级) */										
	clr_PT0;	

	set_ET0;                //enable Timer0 interrupt
	set_EA;                 //enable interrupts
	set_TR0;                //Timer0 run
}

/* END OF FILE */