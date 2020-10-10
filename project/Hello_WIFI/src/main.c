/*
 * main.c
 *
 *  Created on: Oct 3, 2020
 *      Author: george
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "USART_interface.h"

#include"ESP_interface.h"

void main(void)
{

	u8 data[47] = {0};
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);  /* enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,14); /* enable USART */

	GPIO_voidSetPinDir(GPIOA,PIN9,OUTPUT_2M_AF_PUSH_PULL);
	GPIO_voidSetPinDir(GPIOA,PIN10,INPUT_FLOATING);
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_2M_PUSH_PULL);
	STK_voidInit();

	USART1_voidInit();

	ESP_voidInit();
	ESP_voidConnectToWIFI("abc","gog12345");
	//ESP_voidConnectToServer("162.253.155.227",data);



	while(1)
	{
		ESP_voidConnectToServer("162.253.155.227",data);
		STK_voidSetBusyWait(100000);

		if(data[37] == '1')  /* 38 for no checking code */
		{
			GPIO_voidSetPinValue(GPIOA,PIN2,HIGH);

		}
		else if(data[37] == '0') /* 38 for no checking code */
		{
			GPIO_voidSetPinValue(GPIOA,PIN2,LOW);
		}
	}
}

