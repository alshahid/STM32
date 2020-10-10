/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 16 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

void DMA_voidChannelInit(void)
{
	DMA->channel[CHANNEL_NUM - 1].CCR  = 0x0000000E; /* enable 1-transfer complete interrupt 2-half transfer complete interrupt 3-transfer error interrupt*/
	DMA->channel[CHANNEL_NUM - 1].CCR |= DATA_DIRECTION			   <<  4;
	DMA->channel[CHANNEL_NUM - 1].CCR |= Circular_MODE  		   <<  5;
	DMA->channel[CHANNEL_NUM - 1].CCR |= PERIPHERAL_INCREMENT_MODE <<  6;
	DMA->channel[CHANNEL_NUM - 1].CCR |= MEMORY_INCREMENT_MODE     <<  7;
	DMA->channel[CHANNEL_NUM - 1].CCR |= PERIPHERAL_SIZE           <<  8;
	DMA->channel[CHANNEL_NUM - 1].CCR |= MEMORY_SIZE               << 10;
	DMA->channel[CHANNEL_NUM - 1].CCR |= CHANNEL_PRIORITY          << 12;
	DMA->channel[CHANNEL_NUM - 1].CCR |= MEMORY_TO_MEMORY_MODE     << 14;
}

void DMA_voidChannelStart(u32 *copy_Pu32SourceAddress , u32 *copy_Pu32DestinationAddrss , u16 copy_u16BlockLength)
{
	CLEAR_BIT(DMA->channel[CHANNEL_NUM - 1].CCR , 0); /* Disable DMA */
	
	DMA->channel[CHANNEL_NUM-1].CNDTR = copy_u16BlockLength; /* set block lenght */
	
	if(DATA_DIRECTION == 0)
	{
		DMA->channel[CHANNEL_NUM - 1].CPAR = copy_Pu32SourceAddress ;
		DMA->channel[CHANNEL_NUM - 1].CMAR = copy_Pu32DestinationAddrss;
	}
	else if(DATA_DIRECTION == 1)
	{
		DMA->channel[CHANNEL_NUM - 1].CPAR = copy_Pu32DestinationAddrss ;
		DMA->channel[CHANNEL_NUM - 1].CMAR = copy_Pu32SourceAddress ;
	}
	
	SET_BIT(DMA->channel[CHANNEL_NUM - 1].CCR , 0); /* Disable DMA */
}