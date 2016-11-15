/**
	*	@filename		: eeprom.c
	*	@author			: Will Fu
	*	@date				: 2016-11-14
	*	@brief			:
	*	@modify			: 2016-11-14 setup 驱动有误，目前无法正常使用。
	*   						2016-11-15 驱动测试OK，之前问题原因是数据类型不匹配。
	*	@version		: 1.0
	*/

#include "eeprom.h"

/******************************************************************************
	函数名称：read_APROM_BYTE
	函数说明：从APROM中读取一个字节数据
	输入参数:	u16_addr地址
	输出参数:	返回uint8_t
******************************************************************************/
UINT8 read_APROM_BYTE(UINT16 code *u16_addr)
{
	UINT8 rdata;

	rdata = *u16_addr>>8;

	return rdata;
}

/******************************************************************************
	函数名称：read_CH4_calibration
	函数说明：读取甲烷标定数据
	输入参数:	无
	输出参数:	返回uint16_t CH4标定数据
******************************************************************************/
uint16_t read_CH4_calibration(void)
{
	uint8_t data_H = 0, data_L = 0;
	uint16_t data_calibration = 0;
	
	data_H = read_APROM_BYTE(CH4_ADR);
	data_L = read_APROM_BYTE(CH4_ADR + 1);

	data_calibration = (uint16_t)data_H;
	data_calibration = (data_calibration << 8) | (uint16_t)data_L;

	return data_calibration;
}

/******************************************************************************
	函数名称：write_DATAFLASH_BYTE
	函数说明：写入一个字节数据
	输入参数:	u16_addr--写入地址,u8_data--写入数据
	输出参数:	无
******************************************************************************/
void write_DATAFLASH_BYTE(UINT16 u16_addr,UINT8 u8_data)
{
	UINT8 looptmp=0,u8_addrl_r;
	unsigned char code *cd_longaddr;
	unsigned char xdata *xd_tmp;
	
//Check page start address
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		u8_addrl_r = 0;
	}
	else 
	{
		u8_addrl_r = 0x80;
	}
//Save APROM data to XRAM
	xd_tmp = 0x80;
	cd_longaddr = (u16_addr&0xff00)+u8_addrl_r;	
	while (xd_tmp !=0x100)
	{
		*xd_tmp = *cd_longaddr;
		looptmp++;
		xd_tmp++;
		cd_longaddr++;
	}
// Modify customer data in XRAM
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		xd_tmp = u8_addrl_r+0x80;
	}
	else
	{
		xd_tmp = u8_addrl_r+0;
	}
	*xd_tmp = u8_data;
//Erase APROM DATAFLASH page
		IAPAL = u16_addr;
		IAPAH = u16_addr>>8;
		IAPFD = 0xFF;
	  set_IAPEN; 
		set_APUEN;
    IAPCN = 0x22; 		
 		set_IAPGO; 
//Save changed RAM data to APROM DATAFLASH
	u8_addrl_r = u16_addr;
	if (u8_addrl_r<0x80)
	{
		u8_addrl_r =0;
	}
	else
	{
		u8_addrl_r = 0x80;
	}
		xd_tmp = 0x80;
	  IAPAL = u8_addrl_r;
    IAPAH = u16_addr>>8;
		set_IAPEN; 
		set_APUEN;
	  IAPCN = 0x21;
		while (xd_tmp !=0xFF)
		{
			IAPFD = *xd_tmp;
			set_IAPGO;
			IAPAL++;
			xd_tmp++;
		}
		clr_APUEN;
		clr_IAPEN;
}

/******************************************************************************
	函数名称：write_CH4_calibration
	函数说明：写入甲烷标定数据
	输入参数:	u16_data
	输出参数:	无
******************************************************************************/
void write_CH4_calibration(uint16_t u16_data)
{
	uint8_t data_H = 0, data_L = 0;
	uint16_t data_temp = 0;

	data_temp = u16_data;
	data_L = (uint8_t)(data_temp & 0x00FF);
	data_H = (uint8_t)(data_temp >> 8);

	write_DATAFLASH_BYTE(CH4_ADR, data_H);
	write_DATAFLASH_BYTE(CH4_ADR + 1, data_L);
}

/* END OF FILE */
