/*
 * I2C.c
 *
 * Created: 10/1/2020 6:41:54 PM
 *  Author: Mohamed Hamada
 */ 


#include "I2C.h"

void TWI_init(void)
{
	TWBR=2;
	TWSR=0x00;
	TWAR =0b00000010;
	TWCR=(1<<TWEN);
}

void TWI_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_stop(void)
{
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
}
void TWI_write(Uint8 data)
{
	TWDR =data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));

}
Uint8 TWI_read_with_ACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;

}
Uint8 TWI_read_with_NACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;

	
}
Uint8 TWI_getStatus(void)
{
	Uint8 status;
	status=TWSR&0XF8;
	return status;
}