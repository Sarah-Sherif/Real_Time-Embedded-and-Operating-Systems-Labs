#include "Tm4c123gh6pm.h"

#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)

void portF_init(void){
  SYSCTL_RCGCGPIO_R |= 0x20;
  GPIO_PORTF_DIR_R |=0XE;
  GPIO_PORTF_DEN_R |= 0XE;
}

void toggle_red(void) {
  GPIO_PORTF_DATA_R ^= LED_RED;
}

void toggle_blue(void) {
  GPIO_PORTF_DATA_R ^= LED_BLUE;
}

void toggle_green(void) {
  GPIO_PORTF_DATA_R ^= LED_GREEN;
}