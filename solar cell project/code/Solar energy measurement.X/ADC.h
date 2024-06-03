#ifndef ADC_H_
#define ADC_H_

#include "Std_Types.h"
#include "Micro_Config.h"
#include "common_macros.h"

void ADC_init(void);
Uint16 ADC_readChannel(Uint8 channel);

#endif