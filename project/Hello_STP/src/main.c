/*
 * main.c
 *
 *  Created on: Sep 23, 2020
 *      Author: george
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	GPIO_voidSetPinDir(GPIOA,PIN0,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_2M_PUSH_PULL);

	STP_voidSend(0xFF);

	while(1);
}
