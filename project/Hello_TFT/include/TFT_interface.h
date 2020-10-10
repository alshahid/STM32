/******************************************************************************/
/* Author  : George Ghoubrial                                                 */
/* Date    : 28 SEP 2020													  */
/* Version : V01 															  */
/******************************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void TFT_voidInit(void);
void TFT_voidDisplayImage(u16 copy_u16StartX , u16 copy_u16LenghtX , u16 copy_u16StartY , u16 copy_u16LengthY , const u16*copy_Pu16Image);
void TFT_voidDisplayRectangle(u16 copy_u16StartX , u16 copy_u16LenghtX , u16 copy_u16StartY , u16 copy_u16LengthY , u16 copy_u16Color);


#endif
