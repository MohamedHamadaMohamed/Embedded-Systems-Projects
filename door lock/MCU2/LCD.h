/*
 * LCD.h
 *
 * Created: 9/29/2020 12:28:36 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"

/********************************************************************************/
/********************		    Preprocessor Macros 		**********************/
/********************************************************************************/
#define DATA_BITS_MODE   4

#if DATA_BITS_MODE ==4
#define UPPER_PORT_PINS
#endif

#define RS      PB0
#define RW      PB1
#define EN      PB2

#define  LCD_CTR_PORT_DIR      DDRB
#define  LCD_CTR_PORT		   PORTB

#define LCD_DATA_PORT_DIR      DDRA    
#define LCD_DATA_PORT          PORTA

#define CLEAR_COMMAND						0X01
#define FOUR_BITS_DATA_MODE					0X02
#define FOUR_BITS_DATA_1_LINE_MODE		    0X20
#define FOUR_BITS_DATA_2_LINE_MODE		    0X28
#define EIGHT_BITS_DATA_1_LINE_MODE		    0X30  
#define EIGHT_BITS_DATA_2_LINE_MODE		    0X38
#define CURSOR_OFF						    0X0E
#define CURSOR_ON							0X0C
#define SET_CURSOR_LOCATION                 0X80

/********************************************************************************/
/********************		    Functions prototype 		*********************/
/********************************************************************************/
void LCD_init(void);
void LCD_sendCommand(Uint8 command);
void LCD_displayChar(char data);
void LCD_displayString(char*data);
void LCD_clear();
void LCD_displayStringRowColumn(Uint8 row,Uint8 colum, char *data);
void LCD_goToRowColumn(Uint8 row,Uint8 colum);
void LCD_intergerToString(Uint16 data);

#endif /* LCD_H_ */