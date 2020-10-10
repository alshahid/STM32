/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 22 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI1_voidInit(void);
void SPI1_voidSendRecieveSynch(u8 copy_u8SendData,u8 *copy_u8RecieveData);
void SPI1_voidSendRecieveAsynch(u8 copy_u8SendData,void (*callBack)(u8));

#endif