/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 26 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef USART1_INTERFACE_H
#define USART1_INTERFACE_H

void USART1_voidInit(void);
void USART1_voidSendByte(u8 copy_u8Data);
void USART1_voidSendString(u8 const*arr);
u8 USART1_u8ReceiveByte(void);
void USART1_voidReceiveString(u8 *arr);

#endif
