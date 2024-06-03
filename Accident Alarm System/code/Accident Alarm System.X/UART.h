#ifndef UART_H_
#define UART_H_

#include"Std_Types.h"
#include"common_macros.h"
#include"Micro_Config.h"

#define UART_BAUDRATE       9600

void UART_transmitter_init(void);
void UART_receiver_init(void);
void UART_sendByte(const Uint8 data);
Uint8 UART_receiveByte(void);
void UART_sendString(const Uint8 *data);
void UART_receiveString(Uint8 *data);


#endif