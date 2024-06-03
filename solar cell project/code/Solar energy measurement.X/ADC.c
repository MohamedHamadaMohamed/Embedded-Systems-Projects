/*
 * File:   ADC.c
 * Author: Mohamed Hamada
 *
 * Created on October 17, 2020, 11:22 PM
 */


#include "ADC.h"

void ADC_init(void)
{
     ADCS2=0;   ADCS1 =0;  ADCS0 =1; /*ADC clock = clock / 8*/
     CHS2=0; CHS1=0; CHS0=0;
     ADCON1=0X80;
     ADON=1;
     
}
Uint16 ADC_readChannel(Uint8 channel)
{
    Uint16 ADC_value=0;
    ADCON0=(ADCON0&0b11000111)|((channel <<3)&0b00111000);
    __delay_us(30);

    GO_DONE =1;
    while(ADCON0bits.GO_DONE); 
    
    ADC_value= ADRESL;
    ADC_value|=(ADRESH<<8);
    return ADC_value;


}

