/************************************************************************************/
/* Author  : George Ghoubrial                                                       */
/* Date    : 22 AUG 2020                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidInit(void)
{
	#define SCB_AIRCR     *((u32*)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

void NVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber < 32)
	{
		NVIC_ISER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 60)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32 ;
		NVIC_ISER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}

void NVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber < 32)
	{
		NVIC_ICER0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 60)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32 ;
		NVIC_ICER1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}

void NVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber < 32)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 60)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32 ;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}

void NVIC_voidClearPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber < 32)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 60)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32 ;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
}

u8 NVIC_u8GetActiveFlag(u8 copy_u8IntNumber)
{
	u8 Local_u8Result;
	if(copy_u8IntNumber < 32)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 60)
	{
		copy_u8IntNumber = copy_u8IntNumber - 32 ;
		Local_u8Result = GET_BIT(NVIC_IABR1,copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
	return Local_u8Result;
}


void NVIC_voidSetPriority(u8 copy_u8IntId ,u8 copy_u8GroupPriority ,u8 copy_u8SubPriority)
{
	if(copy_u8IntId < 60)
	{
		u8 Local_u8Priority	= (copy_u8GroupPriority << ((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/0x100)) | copy_u8SubPriority ;
		NVIC_IPR[copy_u8IntId] = Local_u8Priority << 4 ;
	}
	else
	{
		/* return error*/
	}
	
	
	
	
	
	
	
	
	
	
	
}
