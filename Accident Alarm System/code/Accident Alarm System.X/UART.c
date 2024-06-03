/*
 * File:   UART.c
 * Author: Mohamed Hamada
 *
 * Created on October 12, 2020, 10:43 PM
 */


#include "UART.h"

#define BAUD_PRESCALE (((_XTAL_FREQ / (UART_BAUDRATE * 16UL))) - 1)

void UART_transmitter_init(void)
{
    /*
     BRGH = 1;  SPBRG = 25;   SYNC = 0;  SPEN = 1;  TRISC6 = 1;  TRISC7 = 1;  
     TXEN = 1; 
     */
    TXSTAbits.BRGH=1; /*enable high speed mode */
    SPBRG = BAUD_PRESCALE; /*set baud rate*/
    TXSTAbits.SYNC=0; /*Asynchronous mode */
    RCSTAbits.SPEN=1;
    TXSTAbits.TX9=0;  /*Selects 8-bit transmission*/
    TRISC6=1;
    TRISC7=1;
    TXSTAbits.TXEN=1; /*Transmit enabled*/
    RCSTAbits.SREN=1;
    RCSTAbits.RX9 =0;
    RCSTAbits.CREN= 1;
    RCSTAbits.FERR=0;
    RCSTAbits.OERR=0;
    
    
}
void UART_receiver_init(void)
{
    TXSTAbits.BRGH=1; /*enable high speed mode */
    SPBRG = BAUD_PRESCALE; /*set baud rate*/
    TXSTAbits.SYNC=0; /*Asynchronous mode */
    RCSTAbits.SPEN=1;
    RCSTAbits.RX9 =0;
    TRISC6=1;
    TRISC7=1;
    
    
 //   RCIE = 1; // UART Receving Interrupt Enable Bit
 // PEIE = 1; // Peripherals Interrupt Enable Bit
 // GIE = 1; // Global Interrupt Enable Bit
  RCSTAbits.CREN= 1;
}
void UART_sendByte(const Uint8 data)
{
    while(BIT_IS_CLEAR(TXSTA,TRMT));
    TXREG= data;
}
Uint8 UART_receiveByte(void)
{
    while(BIT_IS_CLEAR(PIR1,RCIF));
    return RCREG;
}
void UART_sendString(const Uint8 *data)
{
    Uint8 i=0;
    while(data[i]!='\0')
    {
        UART_sendByte(data[i]);
        i++;
    }
}
void UART_receiveString(Uint8 *data)
{
    Uint8 i=0;
    data[i]=UART_receiveByte();
    while(data[i]!='#')
    {  
      i++;  
      data[i]=UART_receiveByte();
    }
}
