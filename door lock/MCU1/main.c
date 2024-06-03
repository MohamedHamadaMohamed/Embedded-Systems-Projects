/*
 * dooe lock MCU 1.c
 *
 * Created: 10/2/2020 9:32:12 PM
 * Author : Mohamed Hamada
 */ 

#include "GPIO.h"
#include "LCD.h"
#include "keypad.h"
#include "Timer.h"
#include "UART.h"

/**********	preprocessors commands	******/
#define setNewPassword           '@'   /*send new password command*/
#define checkAndOpenDoor         '!'   /*send open door command*/
#define checkPassword			 '&'   /*check stored password in EEOROM command*/
#define correctPassword          '+'   /*receive correct message command*/
#define inCorrectPassword        '-'   /*receive incorrect message command*/
#define  thief                   '*'   /*receive thief message command*/




/*password which sent to the control MicroController*/
Uint8 g_password[5]={0,0,0,0,'#'};
Uint8 g_passwordTest[5]={0,1,1,1,'#'};
char g_uartRecieveCommand;
void setNewPasswordNumber(void); /*take new password from user*/
void checkNewPassword(void);     /*check the new password which taken from password*/
bool check(Uint8 *P,Uint8*PT);   /*compare between g_password && g_passwordTest */
bool test();                     /*ask user to set new password*/
void enterPassword(void);        /*function to ask user to enter the correct password*/

int main(void)
{
    
	 char mode;
	 /*initialize the LCD configuration */
     LCD_init();
	 /*initialize the UART configuration */
	 UART_init();
	
	 /*
	  * test function read the new password and check the password number  
	  */
       while(!test());
	 /*
	  * send the new password to the control MCU to save it in EEPROM  after test correct password
	  */
	   UART_sendByte(setNewPassword);/*send set new password command to control MCU*/
	   UART_sendString(g_password);  /*send the password to control MCU*/
	  

     while(1)   
     {
		     
			 LCD_clear();
			  /*
			   * options : '*' to open the door
	           *           '#' to change password 
	           */
			 LCD_displayString("* : open door");
			 LCD_displayStringRowColumn (1,0,"# : change password");
			 while(!keypad_getPressedKey());
			 mode = keypad_getPressedKey();/*take option change password or open door*/
			  LCD_clear();
			  LCD_displayString("input : ");
			  LCD_displayChar(mode);
			  _delay_ms(1000);
			  LCD_clear();
			  
			 switch (mode)
			 {
				 case '*':
				         /*ask user the stored password*/
				         enterPassword();
					     /*send check password and open the door command*/
				         UART_sendByte(checkAndOpenDoor);
						 /*send check password to check */
				         UART_sendString(g_passwordTest);
						 /* receive command from control MCU
						  * options : correct password command if the password is correct
						  *           incorrect password command if the password is not correct and the trial is less than 3 trials
						  *           thief command if the incorrect trials is more than 3 trials 
						  */
				         g_uartRecieveCommand = UART_recieveByte();
				         if (g_uartRecieveCommand == correctPassword)
				         {
							 /*
							  * 3 steps :
							            1- the door is unlocking for 5 sec duration
										2- the door is already open for 5 sec duration
										3- the door is locking for 5 sec duration
							  */
					         LCD_clear();
							 LCD_displayString("door is unlock !");
							 _delay_ms(5000);
							 LCD_clear();
							 LCD_displayString("door is open !");
							 _delay_ms(5000);
							 LCD_clear();
							 LCD_displayString("door is lock !");
							 _delay_ms(5000);
							 LCD_clear();				         
				         }				
						 else if (g_uartRecieveCommand == inCorrectPassword)
						 {
							 LCD_clear();
							 LCD_displayString("password is ");
							 LCD_displayStringRowColumn(1,0,"wrong");
							 _delay_ms(1000);
							 LCD_clear();
							 
						 }
						 else if(g_uartRecieveCommand == thief)
						 {
							 /*
							  * the user try to write password more than 3 trials
							  */
							 LCD_clear();
							 LCD_displayString("you are thief");
							 _delay_ms(10000);
							 LCD_clear();
						 }
						 break;         
					  
		    	 case '#': 
				         /* ask the user the old password*/
				         enterPassword();
						 /*send checking command */
						 UART_sendByte(checkPassword);
						 /*send the password to check it*/
						 UART_sendString(g_passwordTest);
						 /*
						  * receive command from control MCU
						  * option : correct command if the password is correct
						  *          incorrect command if the password is incorrect
						  *          thief command if the trials to enter password exceed 3 trials 
						  */
						 g_uartRecieveCommand = UART_recieveByte();
						 if (g_uartRecieveCommand == correctPassword)
						 {
							 LCD_clear();
							 LCD_displayString("password is OK");
							 _delay_ms(1000);
                             LCD_clear();
							 while(!test());
					         UART_sendByte(setNewPassword);
					         UART_sendString(g_password);
							 
						 }
						 else if (g_uartRecieveCommand == inCorrectPassword)
						 {
							 LCD_clear();
							 LCD_displayString("password is ");
							 LCD_displayStringRowColumn(1,0,"wrong");
							 _delay_ms(1000);
							 LCD_clear();
						 }
				         else if(g_uartRecieveCommand == thief)
				         {
					         LCD_clear();
					         LCD_displayString("you are thief");
					         _delay_ms(10000);
					         LCD_clear();
				         }
						 break;
			 }
			 
			 
		
				
     }
}
void setNewPasswordNumber(void)
{
		Uint8 i=0;
		LCD_clear();
		LCD_displayString("Enter new ");
		LCD_goToRowColumn(1,0);
		LCD_displayString("password :");
		for(i=0;i<4;i++)
		{
			while(!keypad_getPressedKey());
			g_password[i]=keypad_getPressedKey();
			LCD_displayChar('*');
			_delay_ms(250);
			
		}
}
void checkNewPassword(void)
{
		Uint8 i=0;
		LCD_clear();
		LCD_displayStringRowColumn(0,0,"enter again");
		LCD_goToRowColumn(1,0);
		
		for (i=0;i<4;i++)
		{
			while(!keypad_getPressedKey());
			g_passwordTest[i]=keypad_getPressedKey();
			LCD_displayChar('*');
			_delay_ms(250);
            		
		}

}
bool comparePasswordAndPasswordTest(const Uint8 *P,const Uint8*PT)
{
	for(Uint8 iter=0;iter<4;iter++)
	{
		if(P[iter]!=PT[iter])
		{
			return FALSE;
		}
	}
	return TRUE;
}
bool test()
{
	setNewPasswordNumber();
	checkNewPassword();
	if (comparePasswordAndPasswordTest(g_password,g_passwordTest))
	{
		LCD_clear();
		LCD_displayStringRowColumn(0,3,"correct ");
		LCD_displayStringRowColumn(1,3,"password");
		_delay_ms(500);
        
	}
	else
	{
		LCD_clear();
		LCD_displayStringRowColumn(0,3,"try again ");
		_delay_ms(500);
		return FALSE;
		
		
		
	}
	return TRUE;
}
void enterPassword(void)
{
	Uint8 i=0;
	LCD_clear();
	LCD_displayStringRowColumn(0,0,"enter password :");
	LCD_goToRowColumn(1,0);
			
	for (i=0;i<4;i++)
	{
		while(!keypad_getPressedKey());
		g_passwordTest[i]=keypad_getPressedKey();
		LCD_displayChar('*');
		_delay_ms(500);
	}

}
