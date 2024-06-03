#ifndef GSM_H_
#define GSM_H_

#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"



void GSM_init(void);
void GSM_sendMessage(const Uint8 *telephoneNumber,const Uint8 *message);




#endif