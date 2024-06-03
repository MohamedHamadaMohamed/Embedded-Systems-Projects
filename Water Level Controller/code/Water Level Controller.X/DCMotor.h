#include "Micro_Config.h"
#include "Std_Types.h"
#include "Common_Macros.h"
 /********************************************************************************/
 /********************		    Preprocessor Macros 		**********************/
 /********************************************************************************/
#define DCMotor_port     PORTC
#define IN1              RC6
#define IN2              RC7
 /********************************************************************************/
 /********************		    function prototypes 		**********************/
 /********************************************************************************/

void DCMotor_rotateClockwise();
void DCMotor_rotateAntiClockwise();
void DCMotor_stop();