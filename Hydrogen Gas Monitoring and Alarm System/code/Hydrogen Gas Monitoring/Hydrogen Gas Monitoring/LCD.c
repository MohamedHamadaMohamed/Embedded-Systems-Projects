/*
 * LCD.c
 *
 * Created: 9/29/2020 12:28:26 PM
 *  Author: Mohamed Hamada
 */ 
#include "LCD.h"

void LCD_init(void)
{
	LCD_CTR_PORT_DIR|=(1<<EN)|(1<<RS)|(1<<RW);
	#if DATA_BITS_MODE ==4
		#ifdef UPPER_PORT_PINS
			LCD_DATA_PORT_DIR|=0XF0;
		#else
			LCD_DATA_PORT_DIR|=0X0F;
		#endif	
		LCD_sendCommand(FOUR_BITS_DATA_MODE);
		LCD_sendCommand(FOUR_BITS_DATA_2_LINE_MODE);
	#elif DATA_BITS_MODE ==8
		LCD_DATA_PORT_DIR =0XFF;
		LCD_sendCommand(EIGHT_BITS_DATA_2_LINE_MODE);
	#endif
		LCD_sendCommand(CURSOR_OFF);
		LCD_clear();
}
void LCD_sendCommand(Uint8 command)
{
	CLEAR_BIT(LCD_CTR_PORT,RS);
	CLEAR_BIT(LCD_CTR_PORT,RW);
	_delay_ms(1);
	SET_BIT(LCD_CTR_PORT,EN);
	_delay_ms(1);
	#if DATA_BITS_MODE ==4
		#ifdef  UPPER_PORT_PINS
			LCD_DATA_PORT =(command&0XF0)|(LCD_DATA_PORT&0x0F);		
		#else 
		    LCD_DATA_PORT =((command&0XF0)>>4)|(LCD_DATA_PORT&0xF0);
		#endif
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
		SET_BIT(LCD_CTR_PORT,EN);
		#ifdef  UPPER_PORT_PINS
			LCD_DATA_PORT =((command&0X0F)<<4)|(LCD_DATA_PORT&0x0F);
		#else
			LCD_DATA_PORT =((command&0X0F))|(LCD_DATA_PORT&0xF0);
		#endif
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
	#elif DATA_BITS_MODE ==8
		LCD_DATA_PORT = command;
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
	#endif
	
	
}
void LCD_displayChar(char data)
{
		SET_BIT(LCD_CTR_PORT,RS);
		CLEAR_BIT(LCD_CTR_PORT,RW);
		_delay_ms(1);
		SET_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
		#if DATA_BITS_MODE ==4
		#ifdef  UPPER_PORT_PINS
		LCD_DATA_PORT =(data&0XF0)|(LCD_DATA_PORT&0x0F);
		#else
		LCD_DATA_PORT =((data&0XF0)>>4)|(LCD_DATA_PORT&0xF0);
		#endif
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
		SET_BIT(LCD_CTR_PORT,EN);
		#ifdef  UPPER_PORT_PINS
		LCD_DATA_PORT =((data&0X0F)<<4)|(LCD_DATA_PORT&0x0F);
		#else
		LCD_DATA_PORT =((data&0X0F))|(LCD_DATA_PORT&0xF0);
		#endif
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
		#elif DATA_BITS_MODE ==8
		LCD_DATA_PORT = data;
		_delay_ms(1);
		CLEAR_BIT(LCD_CTR_PORT,EN);
		_delay_ms(1);
		#endif
		
}
void LCD_displayString(char*data)
{
	Uint8 i=0;
	while(data[i]!='\0')
	{
		LCD_displayChar(data[i]);
		i++;
	}
}
void LCD_clear()
{
	LCD_sendCommand(CLEAR_COMMAND);
}
void LCD_displayStringRowColumn(Uint8 row,Uint8 colum, char *data)
{
	LCD_goToRowColumn( row, colum);
	LCD_displayString(data);
}
void LCD_goToRowColumn(Uint8 row,Uint8 colum)
{
		Uint8 address=0;
	switch(row)
	{
		case 0 : address =colum;			break;
		case 1 : address=colum+0X40;		break;
		case 2 : address=colum+0X10;		break;
		case 3 : address=colum+0X50;		break;
	}
	LCD_sendCommand(SET_CURSOR_LOCATION | address);

}
void LCD_intergerToString(Uint16 data)
{
	Uint16 buffer[16];
	itoa(data,buffer,10);
	LCD_displayString(buffer);
}