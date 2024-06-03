 /******************************************************************************
 *
 * Module: GPIO Module
 *
 * File Name: GPIO.h
 *
 * Description: GPIO functions 
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef GPIO_H_
 #define GPIO_H_
 #include "Micro_Config.h"
 #include "Std_Types.h"
 #include "Common_Macros.h"
 /********************************************************************************/
 /********************		    Preprocessor Macros 		**********************/
 /********************************************************************************/
 
 #define GPIO_PORTA       0
 #define GPIO_PORTB       1
 #define GPIO_PORTC       2
 #define GPIO_PORTD       3
 #define GPIO_PORTE       4

 
#define INPUT			  0
#define OUTPUT            1
 /********************************************************************************/
 /********************		    Functions prototypes 		**********************/
 /********************************************************************************/ 
 
 
 /*	----------------------------------------------------------------------------------------------			           				 
		function name : set Pin Direction
        Description   : this function is response to determine the direction of pin in the port 
		[Arguments]   :
					  a_port	: the required GPIO port 
					  a_pin     : the required pin 
					  a_mode    : is a pin input mode or output mode
		[return]      : void    
    -----------------------------------------------------------------------------------------------*/
void GPIO_setPinDirection(Uint8 a_port , Uint8 a_pin, Uint8 a_mode);

 /*	----------------------------------------------------------------------------------------------			           				 
		function name : set Pin Value
        Description   : this function is response to set value on pin in the port 
		[Arguments]   :
					  a_port	: the required GPIO port 
					  a_pin     : the required pin 
					  a_value   : is a pin output HIGH or LOW 
		[return]      : void  
  -----------------------------------------------------------------------------------------------*/
 
void GPIO_setPinValue(Uint8 a_port , Uint8 a_pin, bool a_value);


 /*	----------------------------------------------------------------------------------------------			           				 
		function name : get Pin Value
        Description   : this function is response to get value from pin in the port 
		[Arguments]   :
					  a_port	: the required GPIO port 
					  a_pin     : the required pin 
		[return]      : pin value   					    
  -----------------------------------------------------------------------------------------------*/
 
Uint8 GPIO_getPinValue(Uint8 a_port , Uint8 a_pin);
 
 
 #endif