/*
 * UART.c
 *
 * Created: 9/30/2020 3:45:27 PM
 *  Author: Mohamed Hamada
 */ 

#include "UART.h"

#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 8UL))) - 1)

void UART_init(void)
{
	/* U2X = 1 for double transmission speed */
		SET_BIT(DDRD,0);
		CLEAR_BIT(DDRD,0);
	UCSRA = (1<<U2X);
	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/ 
	UCSRB = (1<<RXEN) | (1<<TXEN);
	
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/ 	
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); 
	
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
}
void UART_sendByte(const Uint8 data)
{
		/* UDRE flag is set when the Tx buffer (UDR) is empty and ready for 
	 * transmitting a new byte so wait until this flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
	/* Put the required data in the UDR register and it also clear the UDRE flag as 
	 * the UDR register is not empty now */	 
	UDR = data;
	/************************* Another Method *************************
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transimission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	*******************************************************************/	
}
Uint8 UART_recieveByte()
{
	/* RXC flag is set when the UART receive data so wait until this 
	 * flag is set to one */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	/* Read the received data from the Rx buffer (UDR) and the RXC flag 
	   will be cleared after read this data */	 
    return UDR;		
}
void UART_sendString(const Uint8* data)
{
		Uint8 i = 0;
		while(data[i] != '\0')
		{
			UART_sendByte(data[i]);
			i++;
		}

}
void UART_recieveString(Uint8* data)
{
	Uint8 i = 0;
	data[i] = UART_recieveByte();
	while(data[i] != '#')
	{
		i++;
		data[i] = UART_recieveByte();
	}
	data[i] = '\0';
}
