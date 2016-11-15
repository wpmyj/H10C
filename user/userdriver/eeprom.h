/**
	*	@filename		: eeprom.h
	*	@author			: Will Fu
	*	@date				: 2016-11-14
	*	@brief			:
	*	@modify			: 2016-11-14 setup
	*	@version		: 1.0
 	*/

#ifndef EEPROM_H
#define EEPROM_H

#include <stdio.h>
#include "N76E003.h"
#include "Define.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_define.h"

#define CH4_ADR 	0x3880	

UINT8 read_APROM_BYTE(UINT16 code *u16_addr);
uint16_t read_CH4_calibration(void);
void write_CH4_calibration(uint16_t u16_data);
void write_DATAFLASH_BYTE(UINT16 u16_addr,UINT8 u8_data);

#endif

/* END OF FILE */
