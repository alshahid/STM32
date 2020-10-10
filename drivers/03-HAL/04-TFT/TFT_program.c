/******************************************************************************/
/* Author  : George Ghoubrial                                                 */
/* Date    : 28 SEP 2020													  */
/* Version : V01 															  */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void TFT_voidInit(void)
{
	/* Reset Pulse */
	GPIO_voidSetPinValue(TFT_RESET_PIN,HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,LOW);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(TFT_RESET_PIN,HIGH);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,LOW);
	STK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,HIGH);
	STK_voidSetBusyWait(120000);
	
	/* send sleep out command */
	TFT_voidSendCommand(0x11);
	
	/* wait 150 ms */
	STK_voidSetBusyWait(150000);
	
	/* send color mode command */
	TFT_voidSendCommand(0x3A);
	
	/* send color mode paramter */
	TFT_voidSendData(0x05); /* RGB 444 = 0x03 /RGB 565 = 0x05 /RGB 666 = 0x06 */
	
	/* send display on command */
	TFT_voidSendCommand(0x29);
}

static void TFT_voidSendCommand(u8 copy_u8Command)
{
	u8 local_u8Temp ;
	
	/* set pin A0 to low */
	GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	
	/* send command over SPI Protocol */
	SPI1_voidSendRecieveSynch(copy_u8Command,&local_u8Temp);
}

static void TFT_voidSendData(u8 copy_u8Data)
{ 
	u8 local_u8Temp ;
	
	/* set pin A0 to high */
	GPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
	
	/* send data over SPI protocol */
	SPI1_voidSendRecieveSynch(copy_u8Data,&local_u8Temp);
}

void TFT_voidDisplayImage(const u16*copy_Pu16Image)
{
	/* set x address */
	TFT_voidSendCommand(0x2A);
	TFT_voidSendData(0);   /* start address high byte */
	TFT_voidSendData(0);   /* start address low byte */
	TFT_voidSendData(0);   /* end address high byte */ 
	TFT_voidSendData(127); /* end address low byte */
	
	/* set y address */
	TFT_voidSendCommand(0x2B);
	TFT_voidSendData(0);   /* start address high byte */
	TFT_voidSendData(0);   /* start address low byte */
	TFT_voidSendData(0);   /* end address high byte */ 
	TFT_voidSendData(159); /* end address low byte */

	/* RAM write */
	TFT_voidSendCommand(0x2C);
	
	/* display image */
	for(u16 i=0;i<20480;i++)
	{
		TFT_voidSendData(copy_Pu16Image[i] >> 8); /* send high byte first */
		TFT_voidSendData(copy_Pu16Image[i]);
	}
}
