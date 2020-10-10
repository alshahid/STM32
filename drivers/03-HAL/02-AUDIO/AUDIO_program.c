/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 11 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"


#include "AUDIO_interface.h"
#include "AUDIO_private.h"
#include "AUDIO_config.h"

volatile u32 i = 0;
u32 arraySize = 0;
u8 const *arrayName = (void*)0;

void AUDIO_voidAudio (void)
{
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN0,GET_BIT(arrayName[i],AUDIO_PIN0));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN1,GET_BIT(arrayName[i],AUDIO_PIN1));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN2,GET_BIT(arrayName[i],AUDIO_PIN2));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN3,GET_BIT(arrayName[i],AUDIO_PIN3));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN4,GET_BIT(arrayName[i],AUDIO_PIN4));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN5,GET_BIT(arrayName[i],AUDIO_PIN5));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN6,GET_BIT(arrayName[i],AUDIO_PIN6));
	GPIO_voidSetPinValue(AUDIO_PORT,AUDIO_PIN7,GET_BIT(arrayName[i],AUDIO_PIN7));
	i++;

	if(i == arraySize)
	{
		i = 0;
	}
}

void AUDIO_voidInit(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,AUDIO_PORT_NUM);

	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN0,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN1,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN2,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN3,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN4,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN5,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN6,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(AUDIO_PORT,AUDIO_PIN7,OUTPUT_2M_PUSH_PULL);

	STK_voidSetCallBack(AUDIO_voidAudio);
	STK_voidSetIntervalPeriodic(125);  /* for 8 KHz */

}

void AUDIO_voidSetArrNameSize (u8 const *ptr,u32 copy_u32Size)
{
	arrayName = ptr;
	arraySize = copy_u32Size;


}

