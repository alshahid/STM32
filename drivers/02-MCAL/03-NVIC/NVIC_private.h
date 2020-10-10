/************************************************************************************/
/* Author  : George Ghoubrial                                                       */
/* Date    : 22 AUG 2020                                                            */
/* Version : V01                                                                    */
/************************************************************************************/
#ifndef NVIC_PRIVATE_H
#define	NVIC_PRIVATE_H

/* Register Definitions */
#define NVIC_ISER0    *((u32*)0xE000E100)            /* Enable external interrupt from  0 to 31                    */
#define NVIC_ISER1    *((u32*)0xE000E104)            /* Enable external interrupt from 32 to 63                    */

#define NVIC_ICER0    *((u32*)0xE000E180)            /* Disable external interrupt from   0 to 31                  */
#define NVIC_ICER1    *((u32*)0xE000E184)            /* Disable external interrupt from  32 to 63                  */

#define NVIC_ISPR0    *((u32*)0xE000E200)            /* Enable pending flag for external interrupt from  0 to 31   */
#define NVIC_ISPR1    *((u32*)0xE000E204)            /* Enable pending flag for external interrupt from  32 to 63  */

#define NVIC_ICPR0    *((u32*)0xE000E280)            /* Disable pending flag for external interrupt from  0 to 31  */
#define NVIC_ICPR1    *((u32*)0xE000E284)            /* Disable pending flag for external interrupt from  32 to 63 */

#define NVIC_IABR0    *((volatile u32*)0xE000E300)   /* read active flag for external interrupt from  0 to 31      */
#define NVIC_IABR1    *((volatile u32*)0xE000E304)   /* read active flag for external interrupt from  32 to 63     */

#define NVIC_IPR       ((u8*)0xE00E401)

#endif 