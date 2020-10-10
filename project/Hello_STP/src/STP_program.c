/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 22 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_voidSend(u8 copy_u8Data)
{
	s8 local_s8Counter;
	u8 local_u8Bit;
	for(local_s8Counter = 7; local_s8Counter >= 0; local_s8Counter--)
	{
		/* send bit by bit starting from MSB */
		local_u8Bit = GET_BIT(copy_u8Data , local_s8Counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA , local_u8Bit);
		
		/* send pulse to shift clock */
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK , HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_SHIFT_CLOCK , LOW);
		STK_voidSetBusyWait(1);
	}
	/* send pulse to register clock */
	GPIO_voidSetPinValue(STP_REGISTER_CLOCK , HIGH);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(STP_REGISTER_CLOCK , LOW);
	STK_voidSetBusyWait(1);
}
