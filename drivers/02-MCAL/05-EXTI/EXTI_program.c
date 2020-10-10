/************************************************************************************/
/* Author  : George Ghoubrial                                                       */
/* Date    : 24 AUG 2020                                                            */
/* Version : V01                                                                    */
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL  (void*)0

static void (*EXTI_callBack)(void) = NULL;

void EXTI0_IRQHandler(void)
{
	if(EXTI_callBack!= NULL) /* check if user use EXTI_voidSetCallBack function or not */
	{
		EXTI_callBack();
		
		/* clear flag */
		SET_BIT(EXTI -> PR ,LINE0);
	}
	
}

void EXTI_voidInit(void)
{
	#if EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR , EXTI_LINE);
	#elif EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR , EXTI_LINE);
		SET_BIT(EXTI->FTSR , EXTI_LINE);
	#else
		#error("wrong mode choice")
	#endif
	
	#if EXTI_LINE == LINE0
		SET_BIT(EXTI->IMR , LINE0);
	#elif EXTI_LINE == LINE1
		SET_BIT(EXTI->IMR , LINE1);
	#elif EXTI_LINE == LINE2
		SET_BIT(EXTI->IMR , LINE2);
	#elif EXTI_LINE == LINE3
		SET_BIT(EXTI->IMR , LINE3);
	#elif EXTI_LINE == LINE4
		SET_BIT(EXTI->IMR , LINE4);
	#elif EXTI_LINE == LINE5
		SET_BIT(EXTI->IMR , LINE5);
	#elif EXTI_LINE == LINE6
		SET_BIT(EXTI->IMR , LINE6);
	#elif EXTI_LINE == LINE7
		SET_BIT(EXTI->IMR , LINE7);
	#elif EXTI_LINE == LINE8
		SET_BIT(EXTI->IMR , LINE8);
	#elif EXTI_LINE == LINE9
		SET_BIT(EXTI->IMR , LINE8);
	#elif EXTI_LINE == LINE10
		SET_BIT(EXTI->IMR , LINE10);
	#elif EXTI_LINE == LINE11
		SET_BIT(EXTI->IMR , LINE11);
	#elif EXTI_LINE == LINE12
		SET_BIT(EXTI->IMR , LINE12);
	#elif EXTI_LINE == LINE13
		SET_BIT(EXTI->IMR , LINE13);
	#elif EXTI_LINE == LINE14
		SET_BIT(EXTI->IMR , LINE14);
	#elif EXTI_LINE == LINE15
		SET_BIT(EXTI->IMR , LINE15);
	#else
		/* return error */
	#endif
	
}

void EXTI_voidEnableEXTI(u8 copy_u8Line)
{
	SET_BIT(EXTI->IMR , copy_u8Line);
}

void EXTI_voidDisableEXTI(u8 copy_u8Line)
{
	CLEAR_BIT(EXTI->IMR , copy_u8Line);
}
	
void EXTI_voidSwTrigger(u8 copy_u8Line)
{
	SET_BIT(EXTI->SWIER , copy_u8Line);
}

void EXTI_voidSetSignalLatch(u8 copy_u8Line ,u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case RISING   :SET_BIT(EXTI->RTSR , copy_u8Line); break;
		case FALLING  :SET_BIT(EXTI->FTSR , copy_u8Line); break;
		case ON_CHANGE:SET_BIT(EXTI->RTSR , copy_u8Line); 
					   SET_BIT(EXTI->FTSR , copy_u8Line); break;
	}
	SET_BIT(EXTI->IMR , copy_u8Line);
}

void EXTI_voidSetCallBack(void (*ptr)(void))
{
	EXTI_callBack = ptr;
}
