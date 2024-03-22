
#ifndef __SysTick__
#define __SysTick__

#include "types.h"

//*****************************************************************************
//
// Define the SystTick functions
//
//*****************************************************************************
extern uint32 volatile counter;
extern uint32 volatile flag;

void SysTick_Setup_Second (void);
void SysTick_Init (void);
void Delay_100ms (uint32 delay);


#endif
