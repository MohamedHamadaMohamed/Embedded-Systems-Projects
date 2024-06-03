#ifndef GPS_H_
#define GPS_H_

#include "Micro_Config.h"
#include "Std_Types.h"
#include "common_macros.h"

void GPS_init(void);
void GPS_setLocation(Uint8 *longitude ,Uint8 *latitude);







#endif