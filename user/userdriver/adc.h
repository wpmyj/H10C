/**
	*	@filename		: adc.h
	*	@author			: Will Fu
	*	@date				: 2016-10-25
	*	@brief				:
	*	@modify			: 2016-10-25 setup
	*	@version		: 1.0
 	*/

#ifndef ADC_H
#define ADC_H

#include "N76E003.h"
#include "Define.h"
#include "Common.h"
#include "SFR_Macro.h"
#include "Function_define.h"

uint16_t get_adc_val(uint8_t channel);

#endif

/* END OF FILE */