/*****************************************************************************************/
/* Author : George Ghoubrial                                                             */
/* Date   : 03 OCT 2020                                                                  */
/* Verson : V01                                                                          */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "STK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_voidInit(void)
{
	/* disable ecco */
	USART1_voidSendString("ATE0\r\n");
	STK_voidSetBusyWait(100000);


	/* select wifi mode */
	USART1_voidSendString("AT+CWMODE=1\r\n");
	STK_voidSetBusyWait(100000);
}

void ESP_voidConnectToWIFI(u8 *copy_u8Name ,u8 *copy_u8Password)
{
	u8 i = 0;
	u8 j = 0;
	u8 command[100]={"AT+CWJAP_DEF="};

	command[13]='"';
	while(copy_u8Name[i] != '\0')
	{
		command[14+i]=copy_u8Name[i];
		i++;
	}
	command[14+i]='"';
	i++;
	command[14+i]=',';
	i++;
	command[14+i]='"';
	i++;

	while(copy_u8Password[j] != '\0')
	{
		command[14+i]=copy_u8Password[j];
		i++;
		j++;
	}
	command[14+i]='"';
	i++;
	command[14+i]='\r';
	i++;
	command[14+i]='\n';

	USART1_voidSendString(command);
	STK_voidSetBusyWait(7000000);
}

void ESP_voidConnectToServer(u8 *copy_u8IP, u8 *copy_returnedData)
{
	u8 i=0;
	u8 command[100] = {"AT+CIPSTART="};
	command[12]='"';
	command[13]='T';
	command[14]='C';
	command[15]='P';
	command[16]='"';
	command[17]=',';
	command[18]='"';
	while(copy_u8IP[i] != '\0')
	{
		command[19+i]=copy_u8IP[i];
		i++;
	}
	command[19+i]='"';
	i++;
	command[19+i]=',';
	i++;
	command[19+i]='8';
	i++;
	command[19+i]='0';
	i++;
	command[19+i]='\r';
	i++;
	command[19+i]='\n';

	USART1_voidSendString(command);
	STK_voidSetBusyWait(2000000);
	USART1_voidSendString("AT+CIPSEND=39\r\n");
	STK_voidSetBusyWait(100000);
	USART1_voidSendString("GET http://iot.freeoda.com/status.txt\r\n");
	for(u8 i=0;i<47;i++)
	{
		copy_returnedData[i] = USART1_u8ReceiveByte();
	}
}
