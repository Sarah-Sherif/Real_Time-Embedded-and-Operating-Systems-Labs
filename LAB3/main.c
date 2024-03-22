#include "leds_driver.h"
#include "scheduler.h"
#include "Systick.h"

void task_1(void) {
  toggle_blue();
}

void task_2(void) {
  toggle_green();
}

void task_3(void) {
  toggle_red();
}

int main()
{
  portF_init();
  create_task(task_1, 2);
  create_task(task_2, 3);
  create_task(task_3, 7);
  SysTick_Setup_Second();
  Tasks_Scheduler();
  
  return 0;
}
