/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 3 SEP 2020                                                                   */
/* Verson : V01                                                                          */
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"


#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"


void LEDMRX_voidInit(void)
{
	GPIO_voidSetPinDir(LEDMRX_ROW0_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW1_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW2_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW3_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW4_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW5_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW6_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_ROW7_PIN,OUTPUT_2M_PUSH_PULL);
	
	GPIO_voidSetPinDir(LEDMRX_COL0_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL1_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL2_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL3_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL4_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL5_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL6_PIN,OUTPUT_2M_PUSH_PULL);
	GPIO_voidSetPinDir(LEDMRX_COL7_PIN,OUTPUT_2M_PUSH_PULL);
}