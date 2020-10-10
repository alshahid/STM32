/************************************************************************************/
/* Author  : George Ghoubrial                                                       */
/* Date    : 22 AUG 2020                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H

/* Function Prototypes */	
void NVIC_voidInit             (void);
void NVIC_voidEnableInterrupt  (u8 copy_u8IntNumber);
void NVIC_voidDisableInterrupt (u8 copy_u8IntNumber);
void NVIC_voidSetPendingFlag   (u8 copy_u8IntNumber);
void NVIC_voidClearPendingFlag (u8 copy_u8IntNumber);
u8   NVIC_u8GetActiveFlag      (u8 copy_u8IntNumber);
void NVIC_voidSetPriority      (u8 copy_u8IntId ,u8 copy_u8GroupPriority ,u8 copy_u8SubPriority);

/* Group Priority*/
#define NVIC_GROUP_4_SUB_0      0x05FA0300       /* 4 bits for group priority & 0 bit for sub priority */
#define NVIC_GROUP_3_SUB_1      0x05FA0400       /* 3 bits for group priority & 1 bit for sub priority */ 
#define NVIC_GROUP_2_SUB_2      0x05FA0500 		 /* 2 bits for group priority & 2 bit for sub priority */
#define NVIC_GROUP_1_SUB_3      0x05FA0600 		 /* 1 bits for group priority & 3 bit for sub priority */
#define NVIC_GROUP_0_SUB_4      0x05FA0700 		 /* 0 bits for group priority & 4 bit for sub priority */

#endif 