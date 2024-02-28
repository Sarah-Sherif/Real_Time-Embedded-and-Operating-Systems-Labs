#include "Tm4c123gh6pm.h"
#include "types.h"

#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)

static int volatile l_tickCntr;
int start;
int ticks = 1;
uint32  red_stack[40];
uint32_ptr red_sp = &red_stack[40];
uint32 blue_stack[40];
uint32_ptr blue_sp = &blue_stack[40];


void portF_init(){
  SYSCTL_RCGCGPIO_R |= 0x20;
  GPIO_PORTF_DIR_R |=0XE;
  GPIO_PORTF_DEN_R |= 0XE;
}

void systick_init(){
  NVIC_ST_RELOAD_R = 0XFFFFFF;
  NVIC_ST_CTRL_R = 7;
}

void systick_Handler(){
  ++l_tickCntr;
}

void delay(){
  __asm("CPSID I");
  start = l_tickCntr;
  __asm("CPSIE I");
  while((l_tickCntr-start)<ticks){} 
}

void blinky_red(){
  while(1){
     GPIO_PORTF_DATA_R = LED_RED;
     delay();
     GPIO_PORTF_DATA_R &= ~LED_RED;
     delay();
  }
}

void blinky_blue(){
  while(1){
     GPIO_PORTF_DATA_R = LED_BLUE;
     delay();
     GPIO_PORTF_DATA_R &= ~LED_BLUE;
     delay();
  }
}

int main()
{
  portF_init();
  systick_init();
  
  __asm("CPSIE I");
  *(--red_sp) = (1U <<24); /*XPSR*/
  *(--red_sp) = (uint32)blinky_red;
  *(--red_sp) = 0X0000000EU;
  *(--red_sp) = 0X000000CU;
  *(--red_sp) = 0X00000003U;   
  *(--red_sp) = 0X00000002U;
  *(--red_sp) = 0X00000001U;
  *(--red_sp) = 0X00000000U;
  *(--blue_sp) = (1U <<24); /*XPSR*/
  *(--blue_sp) = (uint32)&blinky_blue;
  *(--blue_sp) = 0X0000000EU;
  *(--blue_sp) = 0X000000CU;
  *(--blue_sp) = 0X00000003U;   
  *(--blue_sp) = 0X00000002U;
  *(--blue_sp) = 0X00000001U;
  *(--blue_sp) = 0X00000000U;
  blinky_red();
  return 0;
}
