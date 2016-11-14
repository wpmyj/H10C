/**
	*	@filename		: adc.c
	*	@author			: Will Fu
	*	@date				: 2016-10-25
	*	@desc				:
	*	@modify			: 2016-10-25 setup
	*	@version		: 1.0
	*/

#include "adc.h"

/******************************************************************************
	函数名称：get_adc_val
	函数说明：获取某一通道AD值
	输入参数:	channel 0~7--通道0~通道7　8--bandgap
	输出参数:	返回值uint16_t
******************************************************************************/
uint16_t get_adc_val(uint8_t channel)
{
	uint16_t adc_val = 0, adc_val_l = 0;
		
	switch(channel)
	{
		case 0	: Enable_ADC_AIN0;
							break;
		case 1	: Enable_ADC_AIN1;
							break;
		case 2	: Enable_ADC_AIN2;
							break;
		case 3	: Enable_ADC_AIN3;
							break;
		case 4	: Enable_ADC_AIN4;
							break;
		case 5	: Enable_ADC_AIN5;
							break;
		case 6	: Enable_ADC_AIN6;
							break;
		case 7	: Enable_ADC_AIN7;
							break;
		case 8	: Enable_ADC_BandGap;
							break;
		default	: break;
	}

	clr_ADCF;
	set_ADCS;
	while(ADCF == 0);

	adc_val = ADCRH;
	adc_val_l = ADCRL;

	adc_val = (adc_val << 4) + (adc_val_l & 0x000f);

	return adc_val;
}

/* END OF FILE */