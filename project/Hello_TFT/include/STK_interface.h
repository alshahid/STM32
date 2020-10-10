/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 30 AUG 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* Function Prototypes */
void STK_voidInit					(void);
void STK_voidSetBusyWait			(u32 copy_u32Ticks);
void STK_voidSetIntervalSingle		(u32 copy_u32Tick);
void STK_voidSetIntervalPeriodic	(u32 copy_u32Tick);
void STK_voidSetCallBack			( void(*ptr)(void) );
u32 STK_u32GetConsumedTime			(void);
u32 STK_u32GetRemainingTime			(void);

#endif
