/******************************************************************************/
/* Author       :George Ghoubrial                                             */
/* Version      :V01                                                          */
/* Date         :12 Augest 2020                                               */                                                                     
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void GPIO_voidSetPinDir(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA:
		    if(copy_u8Pin < 8)
		    {
		    	GPIOA_CRL = ((GPIOA_CRL & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else if(copy_u8Pin < 16)
		    {
		    	copy_u8Pin = copy_u8Pin - 8;
		    	GPIOA_CRH  = ((GPIOA_CRH & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else
		    {
		    	/*return error*/
		    }
		    break;
		case GPIOB:
		    if(copy_u8Pin < 8)
		    {
		    	GPIOB_CRL = ((GPIOB_CRL & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else if(copy_u8Pin < 16)
		    {
		    	copy_u8Pin = copy_u8Pin - 8;
		    	GPIOB_CRH  = ((GPIOB_CRH & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else
		    {
		    	/*return error*/
		    }
		    break;
		case GPIOC:
		    if(copy_u8Pin < 8)
		    {
		    	GPIOC_CRL = ((GPIOC_CRL & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else if(copy_u8Pin < 16)
		    {
		    	copy_u8Pin = copy_u8Pin - 8;
		    	GPIOC_CRH  = ((GPIOC_CRH & ~(0b1111<<(4*copy_u8Pin))) | (copy_u8Mode<<(4*copy_u8Pin)));
		    }
		    else
		    {
		    	/*return error*/
		    }
		    break;
		//default: /* return error */
	}
}

void GPIO_voidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
		case GPIOA:
			if(copy_u8Value == HIGH)
			{
				GPIOA_BSRR = (1 << copy_u8Pin);
			}
			else if (copy_u8Value == LOW)
			{
				GPIOA_BRR = (1 << copy_u8Pin);
			}
			break;
		case GPIOB:
			if(copy_u8Value == HIGH)
			{
				GPIOB_BSRR = (1 << copy_u8Pin);
			}
			else if (copy_u8Value == LOW)
			{
				GPIOB_BRR = (1 << copy_u8Pin);
			}
			break;
		case GPIOC:
			if(copy_u8Value == HIGH)
			{
				GPIOC_BSRR = (1 << copy_u8Pin);
			}
			else if (copy_u8Value == LOW)
			{
				GPIOC_BRR = (1 << copy_u8Pin);
			}
			break;
		//default: /* return error */
		/*
		case GPIOA:
		GPIOA_ODR |= copy_u8Value << copy_u8Pin;
		break;
		case GPIOB:
		GPIOB_ODR |= copy_u8Value << copy_u8Pin;
		break;
		case GPIOC:
		GPIOC_ODR |= copy_u8Value << copy_u8Pin;
		break;
		//default: // return error 
		*/
		
	}
}

u8 GPIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8Port)
	{
	    case GPIOA:
		    LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8Pin);
		    break;
		case GPIOB:
			LOC_u8Result = GET_BIT(GPIOB_IDR,copy_u8Pin);
			break;
		case GPIOC:
			LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8Pin);
			break;
		//default: /* return error */
	}
	return LOC_u8Result;
}
