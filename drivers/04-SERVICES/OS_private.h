/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 11 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef enum
{
	IDLE,READY,RUNNING,WAITING
}states;


typedef struct
{
	u16 periodicity;
	u16 firstDelay;
	void (*Fptr)(void);
	states state;
}Task;


#endif

