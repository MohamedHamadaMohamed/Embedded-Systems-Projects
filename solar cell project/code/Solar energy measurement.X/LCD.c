/*
 * File:   LCD.c
 * Author: Mohamed Hamada
 *
 * Created on October 13, 2020, 10:38 AM
 */


#include "LCD.h"


void LCD_init(void)
{
    CLEAR_BIT(LCD_CTR_PORT_DIR,RS);
    CLEAR_BIT(LCD_CTR_PORT_DIR,RW);
    CLEAR_BIT(LCD_CTR_PORT_DIR,EN);
    #if(DATA_BITS_MODE == 4)
        #ifdef UPPER_PORT_PINS
            LCD_DATA_PORT_DIR&=(~(LCD_DATA_PORT_DIR &0XF0));
        #else
            LCD_DATA_PORT_DIR&=(~(LCD_DATA_PORT_DIR &0X0F));
        #endif
        LCD_sendCommand(FOUR_BITS_DATA_MODE);
        LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE);
    #elif(DATA_BITS_MODE == 8)
     LCD_DATA_PORT_DIR =0x00;
     LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
    #endif
    LCD_sendCommand(CURSOR_OFF);
    LCD_sendCommand(CLEAR_COMMAND);

}
void LCD_sendCommand(Uint8 command)
{
    CLEAR_BIT(LCD_CTR_PORT,RS);
    CLEAR_BIT(LCD_CTR_PORT,RW);
    __delay_ms(1);
    SET_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#if DATA_BITS_MODE == 4
    #ifdef UPPER_PORT_PINS
    LCD_DATA_PORT =(LCD_DATA_PORT &0X0F)|(command &0XF0);
    #else
    LCD_DATA_PORT =(LCD_DATA_PORT &0XF0)|((command &0XF0)>>4);
    #endif
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
    SET_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
    #ifdef UPPER_PORT_PINS
    LCD_DATA_PORT =(LCD_DATA_PORT &0X0F)|((command &0X0F)<<4);
    #else
    LCD_DATA_PORT =(LCD_DATA_PORT &0XF0)|((command &0X0F));
    #endif
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#elif DATA_BITS_MODE == 8
    LCD_DATA_PORT =command;
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#endif
}
void LCD_displayCharacter(Uint8 character)
{
    SET_BIT(LCD_CTR_PORT,RS);
    CLEAR_BIT(LCD_CTR_PORT,RW);
    __delay_ms(1);
    SET_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#if DATA_BITS_MODE == 4
    #ifdef UPPER_PORT_PINS
    LCD_DATA_PORT =(LCD_DATA_PORT &0X0F)|(character &0XF0);
    #else
    LCD_DATA_PORT =(LCD_DATA_PORT &0XF0)|((character &0XF0)>>4);
    #endif
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
    SET_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
    #ifdef UPPER_PORT_PINS
    LCD_DATA_PORT =(LCD_DATA_PORT &0X0F)|((character &0X0F)<<4);
    #else
    LCD_DATA_PORT =(LCD_DATA_PORT &0XF0)|((character &0X0F));
    #endif
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#elif DATA_BITS_MODE == 8
    LCD_DATA_PORT =character;
    __delay_ms(1);
    CLEAR_BIT(LCD_CTR_PORT,EN);
    __delay_ms(1);
#endif



}
void LCD_displayString(Uint8 *data)
{
    Uint8 i=0;
    while(data[i]!='\0')
    {
        LCD_displayCharacter(data[i]);
        i++;
    }
}
void LCD_goToRowColum(Uint8 row,Uint8 col)
{
    Uint8 address;
    switch(row)
    {
        case 0 : address=col;      break;
        case 1 : address=col+0x40; break;
        case 2 : address=col+0x10; break;
        case 3 : address=col+0x50; break;
    }
    LCD_sendCommand(address | SET_CURSOR_LOCATION); 

}
void displayStringRowColom(Uint8 row,Uint8 col,Uint8 *data)
{
    LCD_goToRowColum(row,col);
    LCD_displayString(data);
}
void LCD_intergerToString(Uint16 data)
{
    Uint8 buffer[16];
    itoa(buffer,data,10);
    LCD_displayString(buffer);

}
void LCD_clear()
{
LCD_sendCommand(CLEAR_COMMAND);
}

