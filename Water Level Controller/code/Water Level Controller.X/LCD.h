#ifndef LCD_H_
#define LCD_H_

#include"Std_Types.h"
#include"common_macros.h"
#include"Micro_Config.h"

#define DATA_BITS_MODE     4

#if (DATA_BITS_MODE ==4) 
#define UPPER_PORT_PINS
#endif
//#undef UPPER_PORT_PINS
#define LCD_CTR_PORT       PORTB
#define LCD_CTR_PORT_DIR   TRISB

#define RS      0
#define RW      1
#define EN      2

#define LCD_DATA_PORT       PORTC
#define LCD_DATA_PORT_DIR   TRISC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

/**************************************************/

void LCD_init(void);
void LCD_sendCommand(Uint8 command);
void LCD_displayCharacter(Uint8 character);
void LCD_displayString(Uint8 *data);
void LCD_goToRowColum(Uint8 row,Uint8 col);
void displayStringRowColom(Uint8 row,Uint8 col,Uint8 *data);
void LCD_intergerToString(Uint16 data);
void LCD_clear();




#endif