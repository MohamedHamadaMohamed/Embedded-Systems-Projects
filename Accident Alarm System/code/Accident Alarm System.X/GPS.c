/*
 * File:   GPS.c
 * Author: Mohamed Hamada
 *
 * Created on October 19, 2020, 11:16 AM
 */

#include "UART.h"
#include "GPS.h"
#include "LCD.h"
void GPS_init(void)
{
    //UART_transmitter_init();
    UART_receiver_init();
}
void GPS_setLocation(Uint8 *longitude ,Uint8 *latitude )
{
    LCD_init();
    Uint8 received_data = 0;
    
    
    
    
    
   received_data= UART_receiveByte();
   while(received_data !='$')
   {
         received_data= UART_receiveByte();
   }
   if(received_data == '$')
   {   received_data= UART_receiveByte();
        
       if(received_data == 'G')
       {
           received_data= UART_receiveByte();
           if(received_data == 'P')
           {
               received_data= UART_receiveByte();
               if(received_data == 'R')
               {
                   received_data= UART_receiveByte();
                   if(received_data == 'M')
                   {
                        received_data= UART_receiveByte();
                        if(received_data == 'C')
                        {
                            received_data= UART_receiveByte();
                            if(received_data == ',')
                            {
                                received_data= UART_receiveByte();
                                while(received_data !='A')
                                {
                                    received_data= UART_receiveByte();
                                }
                                received_data= UART_receiveByte();
                                received_data= UART_receiveByte();
                                for(Uint8 i=0;received_data!=',';i++)
                                {
                                    latitude[i]=received_data;
                                    received_data= UART_receiveByte();
                                }
                                
                                received_data= UART_receiveByte();
                                if(received_data == 'N')
                                {
                                    received_data= UART_receiveByte();
                                    if(received_data == ',')
                                    { 
                                        received_data= UART_receiveByte();
                                        for(Uint8 i=0;received_data!=',';i++)
                                        {
                                            longitude[i]=received_data;
                                            received_data= UART_receiveByte();
                                        }
                                    }
                                
                                
                                
                                }
                            }
                        }
                   }
               }
           }
       }
   }

}
 
