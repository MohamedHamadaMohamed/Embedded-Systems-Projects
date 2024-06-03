/*
 * external_EEPROM.c
 *
 * Created: 10/1/2020 8:01:15 PM
 *  Author: Mohamed Hamada
 */ 
#include "I2C.h"
#include "external_EEPROM.h"




void EEPROM_init(void)
{
	TWI_init();
}
Uint8 EEPROM_writeByte(Uint16 address,Uint16 data)
{

	TWI_start();
	if(TWI_getStatus()!=TW_START)
	return ERROR;
	
	TWI_write((Uint8)(0XA0|((address&0X0700)>>7)));
	if(TWI_getStatus()!=TW_MT_SLA_W_ACK)
	return ERROR;
	TWI_write((Uint8)(address));
	if(TWI_getStatus()!=TW_MT_DATA_ACK)
	return ERROR;
	TWI_write((data));
	if(TWI_getStatus()!=TW_MT_DATA_ACK)
	return ERROR;
	TWI_stop();
	return SUCCESS;
}

Uint8 EEPROM_readByte(Uint16 address,Uint16* data)
{
	TWI_start();
	if(TWI_getStatus()!=TW_START)
	return ERROR;
	TWI_write((Uint8)(0XA0|((address&0X0700)>>7)));
	if(TWI_getStatus()!=TW_MT_SLA_W_ACK)
	return ERROR;
	TWI_write((Uint8)(address));
	if(TWI_getStatus()!=TW_MT_DATA_ACK)
	return ERROR;
	
	
	TWI_start();
	if(TWI_getStatus()!=TW_REP_START)
	return ERROR;
	TWI_write((Uint8)(0XA0|((address&0X0700)>>7)|1));
	if(TWI_getStatus()!=TW_MT_SLA_R_ACK)
	return ERROR;
	*data = TWI_read_with_NACK();
	if(TWI_getStatus()!=TW_MR_DATA_NACK)
	return ERROR;
	
	TWI_stop();

	
	return SUCCESS;
	
}