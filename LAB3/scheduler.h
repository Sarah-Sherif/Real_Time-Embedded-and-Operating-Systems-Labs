#ifndef scheduler_h
#define scheduler_h

#include "types.h"
#include "SysTick.h"

#define NUM_OF_TASKS 3

/*Creating a Thread Control Block*/
typedef struct{
    void (*func)(); //Pointer to function
    uint32 periodicity;   
}osThread;

void create_task (void (*Task)(), uint32 ms_periodicity );
void Tasks_Scheduler  (void);

#endif