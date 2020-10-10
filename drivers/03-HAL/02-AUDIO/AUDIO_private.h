/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 11 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef AUDIO_PRIVATE_H
#define AUDIO_PRIVATE_H

#if AUDIO_PORT == GPIOA
#define AUDIO_PORT_NUM		 2
#elif AUDIO_PORT == GPIOB
#define AUDIO_PORT_NUM		 3
#endif

#endif
