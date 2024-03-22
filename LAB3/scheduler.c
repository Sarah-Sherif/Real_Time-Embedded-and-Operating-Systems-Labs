#include "scheduler.h"
#include "types.h"

osThread tasks[NUM_OF_TASKS];
uint32 cur_task = 0;

void create_task (void (*Task)(), uint32 ms_periodicity ){
  if (cur_task >= NUM_OF_TASKS) {
    return;
  }
  tasks[cur_task].func = Task;
  tasks[cur_task].periodicity = ms_periodicity;
  cur_task++;
}
void Tasks_Scheduler (void){
  while (1) {
    while (flag == 0);
    flag = 0;
    __asm("CPSID I");
    uint32 current_time = counter;
    for(uint32 i = 0; i<NUM_OF_TASKS; i++){
      if((current_time % tasks[i].periodicity) == 0){
        tasks[i].func();
      }
    }
    __asm("CPSIE I");
  }
}