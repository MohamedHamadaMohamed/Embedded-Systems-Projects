/*
 * File:   main.c
 * Author: Mohamed Hamada
 *
 * Created on October 23, 2020, 10:30 AM
 */

#include "GPIO.h"
#include "LCD.h"
#include "DCMotor.h"

void main(void) {
    
    LCD_init();
    GPIO_setPinDirection(GPIO_PORTD , PIN0, INPUT);
    GPIO_setPinDirection(GPIO_PORTD , PIN1, INPUT);
    GPIO_setPinDirection(GPIO_PORTD , PIN2, INPUT);
    GPIO_setPinDirection(GPIO_PORTD , PIN3, INPUT);
    //SET_BIT(TRISD , PIN0);  /* FULL */
   // SET_BIT(TRISD , PIN1);  /* 3/4 FULL */
   // SET_BIT(TRISD , PIN2);  /* HALF */
    //SET_BIT(TRISD , PIN3);  /* EMPTY */
    
    GPIO_setPinDirection(GPIO_PORTD , PIN4, OUTPUT);
    GPIO_setPinValue(GPIO_PORTD , PIN4,LOW);
    
    
    while(1)
    {
        if((PORTD&0x0F) ==0X00)
        {
            GPIO_setPinValue(GPIO_PORTD , PIN4,HIGH);
            LCD_clear();
            LCD_displayString("water level: EMPTY");
            while((PORTD&0x0F) ==0X00);
        }
        else if((PORTD&0x0F) ==0X08)
        {
            GPIO_setPinValue(GPIO_PORTD , PIN4,HIGH);
            LCD_clear();
            LCD_displayString("water level: QUARTER");
            while((PORTD&0x0F) ==0X08);
            
        }
        else if((PORTD&0x0F) ==0X0C)
        {
            GPIO_setPinValue(GPIO_PORTD , PIN4,HIGH);
            LCD_clear();
            LCD_displayString("water level: HALF");
            while((PORTD&0x0F) ==0X0C);
            
        }
        else if((PORTD&0x0F) ==0X0E)
        {
           GPIO_setPinValue(GPIO_PORTD , PIN4,HIGH);
            LCD_clear();
            LCD_displayString("water level:3/4 FULL");
            while((PORTD&0x0F) ==0X0F);
            while((PORTD&0x0F) ==0X0E);
            
            
        }
        else if((PORTD&0x0F) ==0X0F)
        {
            GPIO_setPinValue(GPIO_PORTD , PIN4,LOW);
            LCD_clear();
            LCD_displayString("water level: FULL");
            while((PORTD&0x0F) ==0X0F);
            
        }
        else
        {
            GPIO_setPinValue(GPIO_PORTC , PIN4, LOW); 
            LCD_clear();
            LCD_displayString("FAULT");
        }
        
    }
    return;
}
