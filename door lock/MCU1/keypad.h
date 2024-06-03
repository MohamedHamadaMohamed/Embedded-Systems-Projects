/*
 * keypad.h
 *
 * Created: 9/29/2020 11:26:00 AM
 *  Author: Mohamed Hamada
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"

/********************************************************************************/
/********************		    Preprocessor Macros 		**********************/
/********************************************************************************/

#define N_col       3
#define N_row       4



#define KEYPAD_PORT_DIR    DDRA
#define KEYPAD_PORT_IN     PINA
#define KEYPAD_PORT_OUT    PORTA


/********************************************************************************/
/********************		    Functions prototype 		*********************/
/********************************************************************************/

Uint8 keypad_getPressedKey(void);

#endif /* KEYPAD_H_ */