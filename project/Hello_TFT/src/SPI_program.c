/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 22 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

volatile void (*SPI_callBack)(u8);

void SPI1_IRQHandler(void)
{
	SPI_callBack(SPI1->DR);
}

void SPI1_voidInit(void)
{
	SPI1->CR1 = 0x0300;
	SPI1->CR1 |= SPI1_DATA_FORMAT << 11;
	SPI1->CR1 |= SPI1_FRAME_FORMAT << 7;
	SPI1->CR1 |= SPI1_BAUD_RATE << 3;
	SPI1->CR1 |= SPI1_MASTER_SELECT << 2;
	SPI1->CR1 |= SP1_CLOCK_POLARITY << 1;
	SPI1->CR1 |= SPI1_CLOCK_PHASE;
	SPI1->CR1 |= 1 << 6 ; /* enable SPI */
}

void SPI1_voidSendRecieveSynch(u8 copy_u8SendData,u8 *copy_u8RecieveData)
{
	GPIO_voidSetPinValue(SPI1_SLAVE_ENABLE_PIN,LOW); /* enable slave pin */
	SPI1->DR = copy_u8SendData; /*  send data */
	while(GET_BIT(SPI1->SR , 7)); /* check if SPI is busy or not */
	*copy_u8RecieveData = SPI1->DR; /* Recieve data */
	GPIO_voidSetPinValue(SPI1_SLAVE_ENABLE_PIN,HIGH); /* disable slave pin */
}

void SPI1_voidSendRecieveAsynch(u8 copy_u8SendData,void (*callBack)(u8))
{
	GPIO_voidSetPinValue(SPI1_SLAVE_ENABLE_PIN,LOW); /* enable slave pin */
	SPI1->DR = copy_u8SendData; /*  send data */
	SPI_callBack = callBack;   /* set callback*/
	SET_BIT(SPI1->CR2 , 6); /* enable recieve interupt*/
}

