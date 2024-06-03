 /******************************************************************************
 *
 * Module: GPIO Module
 *
 * File Name: GPIO.c
 *
 * Description: GPIO functions 
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #include "GPIO.h"
 /********************************************************************************/
 /********************		    Functions definations 		**********************/
 /********************************************************************************/ 
 /*				Determine pin in Port as Input or Output           				 */
void GPIO_setPinDirection(Uint8 a_port , Uint8 a_pin, Uint8 a_mode)
{
	switch(a_port)
	{
		case GPIO_PORTA :     
							if(a_mode == INPUT)
							{
								CLEAR_BIT(DDRA,a_pin);
							}
							else if(OUTPUT)
							{
								SET_BIT(DDRA,a_pin);
							}
						    break; 
		case GPIO_PORTB :   
						    if(a_mode == INPUT)
							{
								CLEAR_BIT(DDRB,a_pin);
							}
							else if(OUTPUT)
							{
								SET_BIT(DDRB,a_pin);
							}
							break;
		case GPIO_PORTC :     
						    if(a_mode == INPUT)
						    {
							    CLEAR_BIT(DDRC,a_pin);
						    }
						    else if(OUTPUT)
						    {
							    SET_BIT(DDRC,a_pin);
						    }
						    break;
		case GPIO_PORTD :     
						    if(a_mode == INPUT)
						    {
							    CLEAR_BIT(DDRD,a_pin);
						    }
						    else if(OUTPUT)
						    {
							    SET_BIT(DDRD,a_pin);
						    }
						    break;
	}
	
}
 /*				set pin in Port by value 0 or 1           				         */
void GPIO_setPinValue(Uint8 a_port , Uint8 a_pin, Uint8 a_value)
{
	switch(a_port)
	{
		case GPIO_PORTA :    if (a_value == HIGH)
							{
								SET_BIT(PORTA,a_pin);
							}
							else if(a_value == LOW)
							{
								CLEAR_BIT(PORTA,a_pin);
							}
							 break;
		case GPIO_PORTB :    if (a_value == HIGH)
						 	{
								SET_BIT(PORTB,a_pin);
							}
							else if(a_value == LOW)
							{
								CLEAR_BIT(PORTB,a_pin);
							}
							break;
		case GPIO_PORTC :    if (a_value == HIGH)
							{
								SET_BIT(PORTC,a_pin);
							}
							else if(a_value == LOW)
							{
								CLEAR_BIT(PORTC,a_pin);
							}
							break;
		case GPIO_PORTD :    if (a_value == HIGH)
							{
								SET_BIT(PORTD,a_pin);
							}
							else if(a_value == LOW)
							{
								CLEAR_BIT(PORTD,a_pin);
							}
							break;
	}
	
	

}
/*				get value from pin in Port                      				 */
Uint8 GPIO_getPinValue(Uint8 a_port , Uint8 a_pin)
{
	Uint8 Local_Value =0;
	switch(a_port)
	{
		case GPIO_PORTA :     Local_Value=GET_BIT(PINA,a_pin); break;
		case GPIO_PORTB :     Local_Value=GET_BIT(PINB,a_pin); break;
		case GPIO_PORTC :     Local_Value=GET_BIT(PINC,a_pin); break;
		case GPIO_PORTD :     Local_Value=GET_BIT(PIND,a_pin); break;
		default			:								       break;
	}
	return Local_Value;
}
 