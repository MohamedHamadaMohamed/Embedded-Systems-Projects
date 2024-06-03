/*
 * LCD.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"



#include "../../01.MCAL/00.DIO/DIO.h"

#include "LCD_config.h"
#include "LCD.h"

extern Dio_ConfigType LCD_CTL_RS_Config;
extern Dio_ConfigType LCD_CTL_RW_Config;
extern Dio_ConfigType LCD_CTL_EN_Config;

extern Dio_ConfigType LCD_pin0_Config;
extern Dio_ConfigType LCD_pin1_Config;
extern Dio_ConfigType LCD_pin2_Config;
extern Dio_ConfigType LCD_pin3_Config;

extern Dio_ConfigType LCD_pin4_Config;
extern Dio_ConfigType LCD_pin5_Config;
extern Dio_ConfigType LCD_pin6_Config;
extern Dio_ConfigType LCD_pin7_Config;


void LCD_init()
{


	Dio_Init(&LCD_CTL_RS_Config);
	Dio_Init(&LCD_CTL_RW_Config);
	Dio_Init(&LCD_CTL_EN_Config);


	Dio_Init(&LCD_pin0_Config);
	Dio_Init(&LCD_pin1_Config);
	Dio_Init(&LCD_pin2_Config);
	Dio_Init(&LCD_pin3_Config);

#if DATA_BITS_MODE==4
	        LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
			LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);

#elif DATA_BITS_MODE==8

			Dio_Init(&LCD_pin4_Config);
			Dio_Init(&LCD_pin5_Config);
			Dio_Init(&LCD_pin6_Config);
			Dio_Init(&LCD_pin7_Config);

			LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
#endif
			LCD_sendCommand(CURSOR_OFF); /* cursor off */
			LCD_sendCommand(CLEAR_COMMAND);
}
void LCD_sendCommand(uint8 cmd)
{
	Dio_WriteChannel( LCD_CTRL_PORT,RS, LOW );
	Dio_WriteChannel( LCD_CTRL_PORT,RW, LOW );
	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, HIGH );
	_delay_ms(1);
#if DATA_BITS_MODE==4
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN0, GET_BIT(cmd,4 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN1, GET_BIT(cmd,5 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN2, GET_BIT(cmd,6 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN3, GET_BIT(cmd,7 ));

	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, HIGH );
	_delay_ms(1);

	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN0, GET_BIT(cmd,0 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN1, GET_BIT(cmd,1 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN2, GET_BIT(cmd,2 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN3, GET_BIT(cmd,3 ));

	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
    _delay_ms(1);
#elif DATA_BITS_MODE==8

	 Dio_WritePort( LCD_DATA_PORT, cmd );
   _delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
	   _delay_ms(1);


#endif



}
void LCD_displayCharacter(char data)
{
	Dio_WriteChannel( LCD_CTRL_PORT,RS, HIGH );
	Dio_WriteChannel( LCD_CTRL_PORT,RW, LOW );
	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, HIGH );
	_delay_ms(1);
#if DATA_BITS_MODE==4
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN0, GET_BIT(data,4 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN1, GET_BIT(data,5 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN2, GET_BIT(data,6 ));
	Dio_WriteChannel( LCD_DATA_PORT,LCD_DATA_PIN3, GET_BIT(data,7 ));

	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, HIGH );
	_delay_ms(1);

	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN0, GET_BIT(data,0 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN1, GET_BIT(data,1 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN2, GET_BIT(data,2 ));
	Dio_WriteChannel(  LCD_DATA_PORT,LCD_DATA_PIN3, GET_BIT(data,3 ));

	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
	_delay_ms(1);
#elif DATA_BITS_MODE==8

	 Dio_WritePort( LCD_DATA_PORT, data );
	_delay_ms(1);
	Dio_WriteChannel( LCD_CTRL_PORT,EN, LOW );
	   _delay_ms(1);


#endif


}
void LCD_displayString(char* data)
{
	uint8 i =0;

	while(data[i]!='\0')
	{
		 LCD_displayCharacter(data[i]);
	     i++;
	}

}
void LCD_goToRowColum(uint8 row,uint8  col)
{
	uint8 Address;
	switch(row)
	{
	case 0: Address=col;		break;
	case 1:	Address=col+0x40;	break;
	case 2:	Address=col+0x10;   break;
	case 3:Address=col+0x50;    break;
	}

	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}
void LCD_displayStringRowColum(char* data,uint8 row,uint8 col)
{
	LCD_goToRowColum( row,  col);
	LCD_displayString( data);


}
void LCD_cleanscreen()
{
	 LCD_sendCommand(CLEAR_COMMAND);

}
void LCD_integerToString(uint16 data)
{
	char buff[16]; /* String to hold the ascii result */
	   itoa(data,buff,10); /* 10 for decimal */
	   LCD_displayString(buff);

}
void LCD_floatToString(float32 data)
{
	   char buff[16]; /* String to hold the ascii result */
	   //gcvt(data,16,buff);
	   LCD_displayString(buff);

}

