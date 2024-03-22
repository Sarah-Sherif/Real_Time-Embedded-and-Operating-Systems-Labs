#include <stdint.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)
static const uint8_t RED = 0X02;
static const uint8_t BLUE = 0X04;
static const uint8_t GREEN = 0X08;
void vPeriodicTaskRed(void *pvParameters)
{
	for(;;){
		GPIOF->DATA ^= *(uint8_t*)pvParameters;
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

}	
void vPeriodicTaskBlue(void *pvParameters)
{
	for(;;){
		GPIOF->DATA ^= *(uint8_t*)pvParameters;
		vTaskDelay(pdMS_TO_TICKS(2000));
	}

}
void vPeriodicTaskGreen(void *pvParameters)
{
	for(;;){
		GPIOF->DATA ^= *(uint8_t*)pvParameters;
		vTaskDelay(pdMS_TO_TICKS(3000));
	}

}

void port_init(void){
    SYSCTL->RCGCGPIO |= 0x20;   /* enable clock to GPIOF */
    GPIOF->LOCK = 0x4C4F434B;   // unlockGPIOCR register
    GPIOF->CR = 0x0e;           // Enable GPIOPUR register enable to commit
    GPIOF->DIR |= 0x0e;          //set PF1 as an output and PF4 as an input pin
    GPIOF->DEN |= 0x0e;          // Enable PF1 and PF4 as a digital GPIO pins
}



int main()
{

	port_init();
	xTaskCreate(vPeriodicTaskRed ,"REDToggle",120,(void*)&RED,1,NULL);
	xTaskCreate(vPeriodicTaskBlue ,"BLUEToggle",120,(void*)&BLUE,1,NULL);
	xTaskCreate(vPeriodicTaskGreen ,"GREENToggle",120,(void*)&GREEN,1,NULL);

	// Startup of the FreeRTOS scheduler.  The program should block here.  
	vTaskStartScheduler();
	
	// The following line should never be reached.  
	//Failure to allocate enough memory from the heap could be a reason.
	for (;;);
	
}


// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06



