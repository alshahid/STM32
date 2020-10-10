/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 30 AUG 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/* Register Definition */
#define STK_CTRL  	*((volatile u32*)0xE000E010)
#define STK_LOAD	*((volatile u32*)0xE000E014)
#define STK_VALUE	*((volatile u32*)0xE000E018)

/* Pin Definition */
#define STK_ENABLE				0
#define STK_TICKINT				1
#define STK_CLKSOURCE			2
#define STK_COUNTFLAG			16

#define STK_AHB     	    	1
#define STK_AHB_SUB_8  	    	0

#define STK_SINGLE_INTERVAL    	1
#define STK_PERIODIC_INTERVAL  	0
#endif