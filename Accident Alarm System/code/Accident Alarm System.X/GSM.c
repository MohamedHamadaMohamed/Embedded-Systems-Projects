/*
 * File:   GSM.c
 * Author: Mohamed Hamada
 *
 * Created on October 18, 2020, 11:43 PM
 */


#include "UART.h"
#include "GSM.h"
void GSM_init(void)
{
    UART_transmitter_init();
    UART_receiver_init();
}
void GSM_sendMessage(const Uint8 *telephoneNumber,const Uint8 *message)
       
{      
      
       UART_sendString("AT");
       __delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       
           __delay_ms(1000);

       UART_sendString("AT+CMGF=1");
       __delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
     
        UART_sendString("AT+CGMS=");
        __delay_ms(1000);
        UART_sendByte(0x22);/* " ASCII code  */
        __delay_ms(1000);
        UART_sendString(telephoneNumber);
        __delay_ms(1000);
        UART_sendByte(0x22);/* " ASCII code  */
        __delay_ms(1000);
        UART_sendByte(0x0D);/* \r ASCII code  */
        //__delay_ms(1000);
        
        UART_sendString(message);
        __delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       __delay_ms(1000);
       UART_sendByte(26);/*CTRL +Z */
       __delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       UART_sendByte(0x0D);/* \r ASCII code  */
       UART_sendByte(0x0D);/* \r ASCII code  */

}