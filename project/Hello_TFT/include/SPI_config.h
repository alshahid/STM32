/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 22 SEP 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* select slave pin in a pair GPIO,PIN */
#define SPI1_SLAVE_ENABLE_PIN    GPIOA,0

/* Options:
		   0:read then write
		   1:write then read*/
#define SPI1_CLOCK_PHASE		1
 
/* Options:
		   0:Idle zero
		   1:Idle one*/ 
#define SP1_CLOCK_POLARITY		1

/* Options:
		   0:Slave
		   1:Master*/
#define SPI1_MASTER_SELECT		1

/* Options:
		   000: fPCLK/2
		   001: fPCLK/4
		   010: fPCLK/8
		   011: fPCLK/16
		   100: fPCLK/32
		   101: fPCLK/64
		   110: fPCLK/128
		   111: fPCLK/256 */
#define SPI1_BAUD_RATE			000

/* Options:
		    0: MSB transmitted first
			1: LSB transmitted first*/
#define SPI1_FRAME_FORMAT		0

/* Options:
			0: 8-bit data frame 
			1: 16-bit data frame */
#define SPI1_DATA_FORMAT		0

#endif