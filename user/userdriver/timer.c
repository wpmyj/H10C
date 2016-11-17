/**
	*	@filename		: timer.c
	*	@author			: Will Fu
	*	@date				: 2016-11-15
	*	@brief			:
	*	@modify			: 2016-11-15 setup
	*	@version		: 1.0
	*/

#include "timer.h"

/******************************************************************************
	�������ƣ�timer_init
	����˵����timer��ʼ��	timer0��ʱ900ms�ж�
	�������:	��
	���ز���:	��
******************************************************************************/
void timer_init(void)
{
	TIMER0_MODE1_ENABLE;

	clr_T0M;

	TH0 = TH0_INIT;
	TL0 = TL0_INIT;
	
	set_ET0;                                    //enable Timer0 interrupt
	set_EA;                                     //enable interrupts
	set_TR0;                                    //Timer0 run
}

/* END OF FILE */