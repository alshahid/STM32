/****************************************************************************/
/* Author   :George Ghoubrial                                               */
/* Version  :V01                                                            */
/* Date     :8 Augest 2020                                                  */
/****************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"

void RCC_voidInitSysClock(void)
{
#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CFGR = 0x00000001;
	RCC_CR   = 0x00010000; /* Enable HSE Without Bypass*/
#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CFGR = 0x00000001;
	RCC_CR   = 0x00050000; /* Enable HSE With Bypass */
#elif   RCC_CLOCK_TYPE == RCC_HSI
	RCC_CFGR = 0x00000000;
	RCC_CR   = 0x00000081; /* Enable HSI + Triming = 0 */
#elif   RCC_CLOCK_TYPE == RCC_PLL

     #if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	     CLEAR_BIT(RCC_CFGR,16);
	     RCC_CFGR |= (RCC_PLL_MUL_VAL<<18);
	     SET_BIT(RCC_CFGR,1);
	     RCC_CR = 0x01000000; /* Enable PLL */

	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	     SET_BIT(RCC_CFGR,16);
	     SET_BIT(RCC_CFGR,17);
	     RCC_CFGR |= (RCC_PLL_MUL_VAL<<18);
	     SET_BIT(RCC_CFGR,1);
	     RCC_CR = 0x01000000; /* Enable PLL */

	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	     SET_BIT(RCC_CFGR,16);
	     CLEAR_BIT(RCC_CFGR,17);
	     RCC_CFGR |= (RCC_PLL_MUL_VAL<<18);
	     SET_BIT(RCC_CFGR,1);
	     RCC_CR = 0x01000000; /* Enable PLL */
	#else
		#error("You chose wrong PLL input")
	#endif
#else
	#error("you chose wrong clock type")

#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PreId)
{
	if(Copy_u8PreId<=31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR,Copy_u8PreId);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR,Copy_u8PreId);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR,Copy_u8PreId);
			break;
			//default:/*return error*/
		}
	}
	else
	{
		/*return error*/
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PreId)
{
	if(Copy_u8PreId<=31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB:
			CLEAR_BIT(RCC_AHBENR,Copy_u8PreId);
			break;
		case RCC_APB1:
			CLEAR_BIT(RCC_APB1ENR,Copy_u8PreId);
			break;
		case RCC_APB2:
			CLEAR_BIT(RCC_APB2ENR,Copy_u8PreId);
			break;
			//default:/*return error*/
		}
	}
	else
	{
		/*return error*/
	}
}
