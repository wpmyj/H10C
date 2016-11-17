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

#define CH4_ADR 			0x3880
#define CH4_DEFAULT		2500

/* 
	value--CH4标定AD值
	flag:
	0xFF--未标定
	0x00--写入经验值
	0x01--已标定  
 */
struct calibration_info
{
	uint16_t	value;
	uint8_t 	flag;
};

typedef struct calibration_info CaliInfo;

UINT8 read_APROM_BYTE(UINT16 code *u16_addr);
uint16_t read_CH4_calibration(void);
void write_CH4_calibration(uint16_t u16_data);
void write_DATAFLASH_BYTE(UINT16 u16_addr,UINT8 u8_data);
void calibration_init(void);
void calibration_info_read(void);
void calibration_info_write(uint16_t ad_value);

#endif

/* END OF FILE */
