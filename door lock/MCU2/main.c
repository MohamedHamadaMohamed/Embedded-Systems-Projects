/*
 * door lock MCU 2.c
 *
 * Created: 10/3/2020 4:06:36 PM
 * Author : Mohamed Hamada
 */ 

#include "GPIO.h"
#include "DC_Motor.h"
#include "external_EEPROM.h"
#include "UART.h"
#include "LCD.h"
#include "Timer.h"



/**********	preprocessors commands	******/
#define setNewPassword           '@'   /*send new password command*/
#define checkAndOpenDoor         '!'   /*send open door command*/
#define checkPassword			 '&'   /*check stored password in EEOROM command*/
#define correctPassword          '+'   /*receive correct message command*/
#define inCorrectPassword        '-'   /*receive incorrect message command*/
#define  thief                   '*'   /*receive thief message command*/






/*
 * global send and receive command and data from MCU 1
 */
static volatile char g_sendCommand='\0' ;/*valuable responsible to send command to the MCU 1*/
static volatile char g_receiveString[20] ;/*receive string from MCU 1*/
static volatile char g_receiveCommand='\0';/*valuable responsible to receive command from the MCU 1*/


void storeNewPassword();/*function responsible to sore new password in EEPROM */
bool checkStoredPassword();/*read stored password from EEPROM*/



int main(void)
{
	
	
	
	static Uint8 trial=0;
	/*
	 * PORD : PIN6 && PIN7 for DC motor
	 */
    SET_BIT(DDRD,PIN6);
	SET_BIT(DDRD,PIN7);
	SET_BIT(DDRC,PIN7);/*PORTC .PC7 for buzzer */
	UART_init();
	EEPROM_init();
	LCD_init();
	while(1)
	{   
		
		/*
		 * receive command from MCU 1
		 * 3 options : 
					 1- set new password command 
					 2- check password
					 3- open door           
		 */
		g_receiveCommand = UART_recieveByte();
		if(g_receiveCommand == setNewPassword)
		{
			storeNewPassword();
		}
		else if(g_receiveCommand == checkPassword)
		{
			
			 if (checkStoredPassword())
			 {
				 UART_sendByte(correctPassword);
				  trial=0;
			 }
			 else
			 {				 
				
				  trial++;
				 if (trial>=3)
				 {
					 UART_sendByte(thief);
					 SET_BIT(PORTC,PC7);
					  _delay_ms(10000);
					  CLEAR_BIT(PORTC,PC7);
					  trial=0;
				 }
				 else
				 {
					  UART_sendByte(inCorrectPassword);
				 }
			 }
			 
		}
		else if (g_receiveCommand == checkAndOpenDoor )
		{
			 
			 if (checkStoredPassword())
			 {
				 UART_sendByte(correctPassword);
				 DC_Motor_RotateClockWise();
				 
			       _delay_ms(5000);
				 DC_Motor_stop();
				  _delay_ms(5000);
				 DC_Motor_RotateAntiClockWise();
				 _delay_ms(5000);
				 DC_Motor_stop();
				
				
				 trial=0;
			 }
			 else
			 { 
				 
				 trial++;
				 if (trial>=3)
				 {
					  UART_sendByte(thief);
					  SET_BIT(PORTC,PC7);
					  _delay_ms(10000);
					  CLEAR_BIT(PORTC,PC7);
					  trial=0;
				 }
				 else
				 {
				     UART_sendByte(inCorrectPassword);
				 }
				 
			 }
		}
	}
		
	
}
	
void storeNewPassword()
{
	UART_recieveString(g_receiveString);
    /////////////////////////////////////////////////////////////
	
	Uint8 iter=0;
	while (g_receiveString[iter] !='\0')
	{
		EEPROM_writeByte(0x0311+iter, g_receiveString[iter]);
		_delay_ms(10);
		
		iter++;
	}
	Uint8 EEPROMpassword[20];
	for (Uint8 it =0;it<4;it++)
	{
		EEPROM_readByte(0x0311+it, &EEPROMpassword[it]);
	}

	
	
}

bool checkStoredPassword()
{
	UART_recieveString(g_receiveString);

	bool flag ;
	Uint8 i=0;
	
	Uint8 EEPROMpassword[20];
	for (Uint8 iter =0;iter<4;iter++)
	{
		EEPROM_readByte(0x0311+iter, &EEPROMpassword[iter]);
	}
	while (g_receiveString[i] !='\0')
	{
		
		if( g_receiveString[i] !=EEPROMpassword[i] )
		{
			
			return FALSE;
		}
		i++;
	}
	
	return TRUE;
}
