/*
 * DIO_PBcfg.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#include "../00.DIO/DIO_Types.h"

Dio_ConfigType  LED_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};


Dio_ConfigType switch_1_Config ={PORT_D,PIN_3,INPUT,OFF,LOW};
Dio_ConfigType switch_2_Config ={PORT_D,PIN_4,INPUT,OFF,LOW};
Dio_ConfigType switch_3_Config ={PORT_D,PIN_5,INPUT,OFF,LOW};


Dio_ConfigType  decoder_input_1_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};;
Dio_ConfigType  decoder_input_2_Config ={PORT_C,PIN_1,OUTPUT,OFF,LOW};;

Dio_ConfigType  multiplexer_select_input_1_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType  multiplexer_select_input_2_Config ={PORT_C,PIN_1,OUTPUT,OFF,LOW};


Dio_ConfigType seven_segment_pin0_Config ={PORT_A,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin1_Config ={PORT_A,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin2_Config ={PORT_A,PIN_2,OUTPUT,OFF,LOW};
Dio_ConfigType seven_segment_pin3_Config ={PORT_A,PIN_3,OUTPUT,OFF,LOW};

Dio_ConfigType  keypad_Col0  ={PORT_A,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col1  ={PORT_A,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col2  ={PORT_A,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Col3  ={PORT_A,PIN_7,OUTPUT,OFF,LOW};
Dio_ConfigType  keypad_Row0  ={PORT_A,PIN_0,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row1  ={PORT_A,PIN_1,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row2  ={PORT_A,PIN_2,INPUT,OFF,LOW};
Dio_ConfigType  keypad_Row3  ={PORT_A,PIN_3,INPUT,OFF,LOW};

Dio_ConfigType  Servo_Motor_control_config  ={PORT_C,PIN_0,OUTPUT,OFF,LOW};

Dio_ConfigType Blutooth_TXconfig = {PORT_D,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType Blutooth_RXconfig = {PORT_D,PIN_0,INPUT,OFF,LOW};


Dio_ConfigType LCD_CTL_RS_Config ={PORT_D,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_CTL_RW_Config ={PORT_D,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_CTL_EN_Config ={PORT_D,PIN_7,OUTPUT,OFF,LOW};


Dio_ConfigType LCD_pin0_Config ={PORT_C,PIN_0,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin1_Config ={PORT_C,PIN_1,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin2_Config ={PORT_C,PIN_2,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin3_Config ={PORT_C,PIN_3,OUTPUT,OFF,LOW};

Dio_ConfigType LCD_pin4_Config ={PORT_C,PIN_4,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin5_Config ={PORT_C,PIN_5,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin6_Config ={PORT_C,PIN_6,OUTPUT,OFF,LOW};
Dio_ConfigType LCD_pin7_Config ={PORT_C,PIN_7,OUTPUT,OFF,LOW};
