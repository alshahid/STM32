/******************************************************************************/
/* Author  : George Ghoubrial                                                 */
/* Date    : 28 SEP 2020													  */
/* Version : V01 															  */
/******************************************************************************/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

static void TFT_voidSendCommand(u8 copy_u8Command);
static void TFT_voidSendData   (u8 copy_u8Data);
static void TFT_voidSetAddress(u16 copy_u16StartX , u16 copy_u16LenghtX , u16 copy_u16StartY , u16 copy_u16LengthY);

#endif
