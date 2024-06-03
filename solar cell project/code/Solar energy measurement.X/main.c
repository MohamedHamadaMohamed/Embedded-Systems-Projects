/*
 * File:   main.c
 * Author: Mohamed Hamada
 *
 * Created on October 18, 2020, 6:50 AM
 */


#include "ADC.h"
#include "LCD.h"

void main(void) {
    LCD_init();
    ADC_init();
    Uint16 volt;
    Uint16 current;
    LCD_displayString("voltage : ");
    displayStringRowColom(1,0,"current : ");
            
    while(1)
    {
        
       /*
        * max voltage = 22 V
        * max current = 4 A 
        * 
        */ 
       volt = (22*ADC_readChannel(1))/1023;
       current= (4.14*ADC_readChannel(0))/750;
       LCD_goToRowColum(0,10);
       LCD_intergerToString(volt);
        displayStringRowColom(0,14,"V");
       LCD_goToRowColum(1,10);
       LCD_intergerToString(current);
        displayStringRowColom(1,14,"A");
    }
    return;
}
