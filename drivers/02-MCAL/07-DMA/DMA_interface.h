/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 16 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void DMA_voidChannelInit(void);
void DMA_voidChannelStart(u32 *copy_Pu32SourceAddress , u32 *copy_Pu32DestinationAddrss , u16 copy_u16BlockLength);

#endif