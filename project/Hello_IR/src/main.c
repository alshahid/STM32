/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: george
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


volatile u8 u8Flag = 0;
volatile u32 u32FrameData[50] = {0};
volatile u8  u8edgeCounter = 0;
volatile u8 u8data = 0;

void voidTakeAction (void)
{
	u8data = 0;
	if((u32FrameData[0] > 10000) && (u32FrameData[0] < 14000))
	{
		for(u8 i=0;i<8;i++)
			{
				if ((u32FrameData[17+i] > 1000) && (u32FrameData[17+i] < 1200))
				{
					CLEAR_BIT(u8data,i);
				}
				else if((u32FrameData[17+i] > 2100) && (u32FrameData[17+i] < 2300))
				{
					SET_BIT(u8data,i);
				}
			}
	}
	else
	{
		/* invaled frame */
	}

	u8Flag = 0;
	u8edgeCounter = 0;
	u32FrameData[0] = 0;
}

void voidGetFrame(void)
{
	if (u8Flag == 0)
	{
		STK_voidSetIntervalSingle(1000000);
		u8Flag = 1;
	}
	else
	{
		u32FrameData[u8edgeCounter] = STK_u32GetConsumedTime();
		STK_voidSetIntervalSingle(1000000);
		u8edgeCounter++;
	}

}

void main(void)
{


	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* enable clock on GPIOA */


	GPIO_voidSetPinDir(GPIOA,PIN0,INPUT_FLOATING);
	GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_2M_PUSH_PULL);

	EXTI_voidSetCallBack(voidGetFrame);
	EXTI_voidInit();

	NVIC_voidInit();
	NVIC_voidEnableInterrupt(6);

	STK_voidSetCallBack(voidTakeAction);
	STK_voidInit();

	while(1)
	{


	}
}

