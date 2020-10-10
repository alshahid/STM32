/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 30 AUG 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

#define NULL (void*)0

static void (*STK_callback)(void) = NULL;

static u8 STK_u8intervalMode;

void SysTick_Handler(void)
{
	u8 Local_u8Temp;
	if(STK_u8intervalMode == STK_SINGLE_INTERVAL)
	{
		/* disable SysTick */
		CLEAR_BIT(STK_CTRL,STK_ENABLE);  
		CLEAR_BIT(STK_CTRL,STK_TICKINT); /* disable interrupt because if it active and use busywait function it causes a broblem*/
		STK_VALUE = 0;					 /* clear value reg & clear flag bit */

	}

	if(STK_callback != NULL)
	{
		/* call of callback function */
		STK_callback();
		/* clear flag */
		Local_u8Temp = GET_BIT(STK_CTRL,STK_COUNTFLAG);
	}
}


void STK_voidInit(void)
{
	STK_CTRL = STK_CLK_SRS << 2;   /* set configuration clock AHB or AHB/8 */
}


void STK_voidSetBusyWait(u32 copy_u32Ticks)
{
	/* disable SysTick */
	CLEAR_BIT(STK_CTRL,STK_ENABLE);  
	CLEAR_BIT(STK_CTRL,STK_TICKINT); /* disable STK interrupt */
	STK_VALUE = 0;

	/* Load ticks to load register */
	STK_LOAD = copy_u32Ticks;

	/* Enable SysTick */
	SET_BIT(STK_CTRL,STK_ENABLE);    
	while(GET_BIT(STK_CTRL , STK_COUNTFLAG) == 0);  /* busy wait */

	/* disable SysTick */
	CLEAR_BIT(STK_CTRL,STK_ENABLE);  
	STK_VALUE = 0;     		 /* claer value register then will automatic reset flag*/
}

void STK_voidSetIntervalSingle(u32 copy_u32Tick)
{
	/* disable SysTick */
	CLEAR_BIT(STK_CTRL,STK_ENABLE);  
	STK_VALUE = 0;

	/* load ticks to load register */
	STK_LOAD = copy_u32Tick;

	/* Enable STK interrupt */
	SET_BIT(STK_CTRL,STK_TICKINT);

	/* select mode */
	STK_u8intervalMode = STK_SINGLE_INTERVAL;

	/* Enable SysTick */
	SET_BIT(STK_CTRL,STK_ENABLE);

}

void STK_voidSetIntervalPeriodic(u32 copy_u32Tick)
{
	/* disable SysTick */
	CLEAR_BIT(STK_CTRL,STK_ENABLE);  
	STK_VALUE = 0;

	/* load ticks to load register */
	STK_LOAD = copy_u32Tick;

	/* Enable STK interrupt */
	SET_BIT(STK_CTRL,STK_TICKINT);

	/* select mode */
	STK_u8intervalMode = STK_PERIODIC_INTERVAL;

	/* Enable SysTick */
	SET_BIT(STK_CTRL,STK_ENABLE);
}

void STK_voidSetCallBack( void(*ptr)(void) )
{
	STK_callback= ptr;
}

u32 STK_u32GetConsumedTime(void)
{
	return STK_LOAD - STK_VALUE;
}

u32 STK_u32GetRemainingTime(void)
{
	return  STK_VALUE;
}
