/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 11 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL  (void*)0

volatile u16 TickCounts = 0;
Task OS_tasks[NUM_OF_TASKS] = {NULL};   /* array of tasks (array of structures) */

void scheduler (void)
{
	for(u8 i=0;i<NUM_OF_TASKS;i++)
	{
		if(OS_tasks[i].Fptr != NULL && OS_tasks[i].state == READY)
		{
			if(OS_tasks[i].firstDelay == 0)
			{
				OS_tasks[i].Fptr();
				OS_tasks[i].firstDelay = OS_tasks[i].periodicity - 1;
			}
			else
			{
				OS_tasks[i].firstDelay--;
			}
		}
	}
}

void OS_voidStart(void)
{
	STK_voidInit();
	STK_voidSetCallBack(scheduler);
	STK_voidSetIntervalPeriodic(1000);
}

void OS_voidCreateTask(u8 copy_u8ID , u16 copy_u16Periodicity , void (*ptr)(void) , u8 copy_u8FirstDelay)
{
	OS_tasks[copy_u8ID].periodicity = copy_u16Periodicity;
	OS_tasks[copy_u8ID].Fptr = ptr;
	OS_tasks[copy_u8ID].firstDelay = copy_u8FirstDelay;
	OS_tasks[copy_u8ID].state = READY ;
}
void OS_voidWaitTask(u8 copy_u8TaskID)
{
	OS_tasks[copy_u8TaskID].state = WAITING ;
}

void OS_voidResumeTask(u8 copy_u8TaskID)
{
	OS_tasks[copy_u8TaskID].state = READY ;
}

