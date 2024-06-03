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
     UART_init();
}
void GSM_sendMessage(const Uint8 *telephoneNumber,const Uint8 *message)
       
{      
      
       UART_sendString("AT");
       _delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       
           _delay_ms(1000);

       UART_sendString("AT+CMGF=1");
       _delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
     
        UART_sendString("AT+CGMS=");
        _delay_ms(1000);
        UART_sendByte(0x22);/* " ASCII code  */
        _delay_ms(1000);
        UART_sendString(telephoneNumber);
        _delay_ms(1000);
        UART_sendByte(0x22);/* " ASCII code  */
        _delay_ms(1000);
        UART_sendByte(0x0D);/* \r ASCII code  */
        //__delay_ms(1000);
        
        UART_sendString(message);
        _delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       _delay_ms(1000);
       UART_sendByte(26);/*CTRL +Z */
       _delay_ms(1000);
       UART_sendByte(0x0D);/* \r ASCII code  */
       UART_sendByte(0x0D);/* \r ASCII code  */
       UART_sendByte(0x0D);/* \r ASCII code  */

}