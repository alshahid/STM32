/*
 * main.c
 *
 *  Created on: Sep 28, 2020
 *      Author: george
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "SPI_interface.h"
#include "TFT_interface.h"
#include "image.h"

void main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,12); /* enable SPI1 */

	GPIO_voidSetPinDir(GPIOA,PIN1,OUTPUT_2M_PUSH_PULL); /* reset pin */
	GPIO_voidSetPinDir(GPIOA,PIN2,OUTPUT_2M_PUSH_PULL); /* A0 pin*/
	GPIO_voidSetPinDir(GPIOA,PIN5,OUTPUT_10M_AF_PUSH_PULL); /* SCK */
	GPIO_voidSetPinDir(GPIOA,PIN7,OUTPUT_10M_AF_PUSH_PULL); /* MOSI */

	STK_voidInit();

	SPI1_voidInit();

	TFT_voidInit();
	TFT_voidDisplayImage(image);

	while(1);
}


