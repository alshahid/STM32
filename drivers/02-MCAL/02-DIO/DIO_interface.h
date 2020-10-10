/******************************************************************************/
/* Author       :George Ghoubrial                                             */
/* Version      :V01                                                          */
/* Date         :12 Augest 2020                                               */                                                                     
/******************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

#define  PIN0   0
#define  PIN1   1
#define  PIN2   2
#define  PIN3   3
#define  PIN4   4
#define  PIN5   5
#define  PIN6   6
#define  PIN7   7
#define  PIN8   8
#define  PIN9   9
#define  PIN10  10
#define  PIN11  11
#define  PIN12  12
#define  PIN13  13
#define  PIN14  14
#define  PIN15  15

/* Pin Modes*/
#define INPUT_ANALOG              0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULL_UP_OR_DOWN     0b1000

#define OUTPUT_10M_PUSH_PULL      0b0001
#define OUTPUT_10M_OPEN_DRAIN     0b0101
#define OUTPUT_10M_AF_PUSH_PULL   0b1001
#define OUTPUT_10M_AF_OPEN_DRAIN  0b1101

#define OUTPUT_2M_PUSH_PULL       0b0010
#define OUTPUT_2M_OPEN_DRAIN      0b0110
#define OUTPUT_2M_AF_PUSH_PULL    0b1010
#define OUTPUT_2M_AF_OPEN_DRAIN   0b1110

#define OUTPUT_50M_PUSH_PULL      0b0011
#define OUTPUT_50M_OPEN_DRAIN     0b0111
#define OUTPUT_50M_AF_PUSH_PULL   0b1011
#define OUTPUT_50M_AF_OPEN_DRAIN  0b1111

#define HIGH   1
#define LOW    0

/**************************************************Function Prototypes********************************************/
void GPIO_voidSetPinDir(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Mode);

void GPIO_voidSetPinValue(u8 copy_u8Port,u8 copy_u8Pin,u8 copy_u8Value);

u8 GPIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin);

#endif