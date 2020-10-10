/****************************************************************************/
/* Author   :George Ghoubrial                                               */
/* Version  :V01                                                            */
/* Date     :8 AUG 2020                                                     */
/****************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2

/* Function Prototypes */
void RCC_voidInitSysClock (void);
void RCC_voidEnableClock  (u8 Copy_u8BusId,u8 Copy_u8PreId);


#endif
