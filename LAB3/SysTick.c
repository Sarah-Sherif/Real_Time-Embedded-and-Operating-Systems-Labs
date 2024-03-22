#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "SysTick.h"
#include "scheduler.h"


//************************************************************
//*
//*Configuring delays using SysTick timer without interrupts
//*
//************************************************************

void SysTick_Init (void){
	//Initialize the SysTick Timer
	NVIC_ST_RELOAD_R = 16000 -1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x7;
	while((NVIC_ST_CTRL_R & (1<<16))== 0){}
}

void Delay_100ms(uint32 delay){
	volatile int i=0;
	for(i=0;i<(100*delay);i++){
		SysTick_Init ();
	}
}

//************************************************************
//*
//*Configuring delays using SysTick timer with interrupts
//*
//************************************************************

void 
SysTick_Setup_Second (void){
	//Initialize the SysTick Timer
        NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0xfffffe;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x7;
        
        // Global Enable IRQ.s
        __asm(" CPSIE i");
}

uint32 volatile counter;
uint32 volatile flag;

void 
SysTick_Handler (void){

        ++counter;
        flag=1;
}
