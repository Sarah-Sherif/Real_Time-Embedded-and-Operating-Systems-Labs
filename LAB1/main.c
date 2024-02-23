#include "Tm4c123gh6pm.h"

#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)

static int volatile l_tickCntr;
int start;
int ticks = 1;


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
     GPIO_PORTF_DATA_R = LED_BLUE;
     delay();
     GPIO_PORTF_DATA_R &= ~LED_BLUE;
     delay();
     GPIO_PORTF_DATA_R = LED_GREEN;
     delay();
     GPIO_PORTF_DATA_R &= ~LED_GREEN;
     delay();
  }
}

//void blinky_blue(){
//  while(1){
//     GPIO_PORTF_DATA_R = LED_BLUE;
//     delay();
//     GPIO_PORTF_DATA_R &= ~LED_BLUE;
//     delay();
//  }
//}

int main()
{
  portF_init();
  systick_init();
  blinky_red();
//  blinky_blue();
  return 0;
}
