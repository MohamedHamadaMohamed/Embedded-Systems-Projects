/*
 * LCD.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_03_LCD_LCD_H_
#define ATMEGA16_02_HAL_03_LCD_LCD_H_

#include "../../00.LIB/Std_types.h"


/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80



void LCD_init();
void LCD_sendCommand(uint8 cmd);
void LCD_displayCharacter(char data);
void LCD_displayString(char* data);
void LCD_goToRowColum(uint8 row,uint8  col);
void LCD_displayStringRowColum(char* data,uint8 row,uint8 col);
void LCD_cleanscreen();
void LCD_integerToString(uint16 data);
void LCD_floatToString(float32 data);
#endif /* ATMEGA16_02_HAL_03_LCD_LCD_H_ */

