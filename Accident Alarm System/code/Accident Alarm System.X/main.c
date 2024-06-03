/*
 * File:   ????.c
 * Author: Mohamed Hamada
 *
 * Created on October 18, 2020, 11:01 PM
 */


#include "GSM.h"
#include "GPS.h"
#include "LCD.h"
void main(void) {
    //GSM_init();
     GPS_init();
     LCD_init();
     
     Uint8 longitude[13]="mohamed",latitude[13]="mostafa";
     
     GPS_setLocation(longitude , latitude);
    LCD_displayString(latitude);
    displayStringRowColom(1,0,longitude);
    while(1)
    {
     
     
     
    }
    return;
}
