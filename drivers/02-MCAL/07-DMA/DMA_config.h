/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 16 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

/* Options: 1 -> 7 */
#define CHANNEL_NUM		1

/* Options:
		   0  disable
		   1  Enable     */
#define MEMORY_TO_MEMORY_MODE   0

/* Options:
		   0  disable
		   1  Enable     */
#define MEMORY_INCREMENT_MODE   0

/* Options:
		   0  disable
		   1  Enable     */
#define PERIPHERAL_INCREMENT_MODE   0

/* Options:
		   0  disable
		   1  Enable     */
#define Circular_MODE   0


/* Options:
		   0  read from peripheral
		   1  read from memory     */
#define DATA_DIRECTION		0


/* Options:
		   0: Low
		   1: Medium
		   2: High
           3: Very high*/
#define CHANNEL_PRIORITY	3

/* Options:
		   0: 8-bits
		   1: 16-bits
		   2: 32-bits*/
#define MEMORY_SIZE		2

/* Options:
		   0: 8-bits
		   1: 16-bits
		   2: 32-bits*/
#define PERIPHERAL_SIZE		2

#endif