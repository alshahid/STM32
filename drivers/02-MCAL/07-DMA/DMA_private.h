/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 16 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_channel;

typedef struct{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_channel channel[6];
}DMA_t;

#define DMA ((DMA_t*)0x4002000)

#endif