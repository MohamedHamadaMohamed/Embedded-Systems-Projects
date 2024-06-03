/*
 * UART.h
 *
 * Created: 9/30/2020 3:45:49 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef UART_H_
#define UART_H_

#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"

/********************************************************************************/
/********************		    Preprocessor Macros 		**********************/
/********************************************************************************/
#define UART_BAUDRATE       9600

void UART_init(void);
void UART_sendByte(const Uint8 data);
Uint8 UART_recieveByte();
void UART_sendString(const Uint8* data);
void UART_recieveString(Uint8* data);



#endif /* UART_H_ */