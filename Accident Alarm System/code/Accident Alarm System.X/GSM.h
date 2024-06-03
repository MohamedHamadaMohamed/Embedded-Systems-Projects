#ifndef GSM_H_
#define GSM_H_

#include "Micro_Config.h"
#include "Std_Types.h"
#include "common_macros.h"


void GSM_init(void);
void GSM_sendMessage(const Uint8 *telephoneNumber,const Uint8 *message);




#endif