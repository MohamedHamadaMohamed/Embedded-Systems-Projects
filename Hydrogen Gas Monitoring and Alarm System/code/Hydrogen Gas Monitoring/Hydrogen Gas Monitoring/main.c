/*
 * Hydrogen Gas Monitoring.c
 *
 * Created: 10/24/2020 8:05:14 AM
 * Author : Mohamed Hamada
 */ 

#include "GSM.h"
#include "LCD.h"
#include "GPIO.h"

int main(void)
{
    LCD_init();
	GSM_init();
	GPIO_setPinDirection(GPIO_PORTA , PIN0, INPUT);
	GPIO_setPinDirection(GPIO_PORTA , PIN1, OUTPUT);
	GPIO_setPinValue(GPIO_PORTA , PIN1, LOW);
	GPIO_setPinDirection(GPIO_PORTD , PIN2, OUTPUT);
	GPIO_setPinValue(GPIO_PORTD , PIN2, LOW);
    while (1) 
    {
		if(GPIO_getPinValue(GPIO_PORTA , PIN0)==HIGH)
		{
			LCD_clear();
			LCD_displayString("Gas is detected");
			LCD_displayStringRowColumn(1,0, "there is fire ");
			GPIO_setPinValue(GPIO_PORTA , PIN1, HIGH);
			GPIO_setPinValue(GPIO_PORTD , PIN2, HIGH);
			GSM_sendMessage("02001032775611","fire in the star factory");
			while(GPIO_getPinValue(GPIO_PORTA , PIN0)==HIGH);
		}
		else if(GPIO_getPinValue(GPIO_PORTA , PIN0)==LOW)
		{
			LCD_clear();
			LCD_displayString("Gas is NO detected");
			
			GPIO_setPinValue(GPIO_PORTA , PIN1, LOW);
			GPIO_setPinValue(GPIO_PORTD , PIN2, LOW);
			while(GPIO_getPinValue(GPIO_PORTA , PIN0)==LOW);
			
		}
			
    }
}

