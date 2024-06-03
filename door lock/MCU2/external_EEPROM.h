/*
 * external_EEPROM.h
 *
 * Created: 10/1/2020 8:00:54 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_



#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"


#define ERROR        0
#define SUCCESS      1

void EEPROM_init(void);
Uint8 EEPROM_readByte(Uint16 address,Uint16* data);
Uint8 EEPROM_writeByte(Uint16 address,Uint16 data);




#endif /* EXTERNAL_EEPROM_H_ */