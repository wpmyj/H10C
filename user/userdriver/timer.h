/**
	*	@filename		: timer.h
	*	@author			: Will Fu
	*	@date				: 2016-11-15
	*	@brief			:
	*	@modify			: 2016-11-15 setup
	*	@version		: 1.0
 	*/

#ifndef TIMER_H
#define TIMER_H

#include "N76E003.h"
#include "Define.h"
#include "Common.h"
#include "SFR_Macro.h"
#include "Function_define.h"

#define TH0_INIT        (65536-40000)/256	/* 30ms@16MHz */
#define TL0_INIT        (65536-40000)%256

void timer_init(void);

#endif

/* END OF FILE */