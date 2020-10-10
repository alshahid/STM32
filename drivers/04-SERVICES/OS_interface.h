/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 11 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreateTask(u8 copy_u8ID , u16 copy_u16Periodicity , void (*ptr)(void) , u8 copy_u8FirstDelay);
void OS_voidStart(void);
void OS_voidWaitTask(u8 copy_u8TaskID);
void OS_voidResumeTask(u8 copy_u8TaskID);
#endif
