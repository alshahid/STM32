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

static u8 ESP_u8CheckResponse(void);

void ESP_voidInit(void)
{

	u8 local_u8Result = 0;
	u8 count = 0;
	while(local_u8Result != 1 && count < 3)
	{
		/* disable ecco */
		USART1_voidSendString("ATE0\r\n");
		local_u8Result=ESP_u8CheckResponse();
		count++;
	}
	count = 0;
	local_u8Result = 0;

	while(local_u8Result != 1 && count < 3)
	{
		/* select wifi mode */
		USART1_voidSendString("AT+CWMODE=1\r\n");
		local_u8Result=ESP_u8CheckResponse();
		count++;
	}
}

static u8 ESP_u8CheckResponse(void)
{
	u8 i=0;
	u8 local_u8Response[60]={0};
	u8 local_u8Result = 0;

	/* put response in array */
	local_u8Response[i] = USART1_u8ReceiveByte();
	while(local_u8Response[i] != 255)
	{
		i++;
		local_u8Response[i] = USART1_u8ReceiveByte();
	}

	/* check OK */
	if(local_u8Response[2] == 'O' && local_u8Response[3] == 'K')      /* for command:ATE0 */
	{
		local_u8Result = 1;
	}
	else if(local_u8Response[3] == 'O' && local_u8Response[4] == 'K')   /* for command:AT+CWMODE=1 */
	{
		local_u8Result = 1;
	}
	else if(local_u8Response[12] == 'O' && local_u8Response[13] == 'K') /* for command: AT+CIPSTART and command: AT+CIPSEND=39*/
	{
		local_u8Result = 1;
	}
	else if(local_u8Response[24] == 'O' && local_u8Response[25] == 'K') /* for command: GET http://iot.freeoda.com/status.txt */
	{
		local_u8Result = 1;
	}
	return local_u8Result;
}

void ESP_voidConnectToWIFI(u8 *copy_u8Name ,u8 *copy_u8Password)
{
	u8 i = 0;
	u8 j = 0;
	u8 command[100]={"AT+CWJAP_CUR="};

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

	u8 local_u8Result = 0;
	u8 count = 0;
	while(local_u8Result != 1 && count < 3)
	{
		/* disable ecco */
		USART1_voidSendString(command);
		local_u8Result=ESP_u8CheckResponse();
		count++;
	}




	local_u8Result = 0;
	count = 0;
	while(local_u8Result != 1 && count < 3)
	{
		/* disable ecco */
		USART1_voidSendString("AT+CIPSEND=39\r\n");
		local_u8Result=ESP_u8CheckResponse();
		count++;
	}

#if(0)

	local_u8Result = 0;
	count = 0;
	while(local_u8Result != 1 && count < 3)
	{
		/* disable ecco */
		USART1_voidSendString("GET http://iot.freeoda.com/status.txt\r\n");
		local_u8Result=ESP_u8CheckResponse();
		count++;
	}
#endif
	/* put response in array */
	i=0;
	USART1_voidSendString("GET http://iot.freeoda.com/status.txt\r\n");
	copy_returnedData[i] = USART1_u8ReceiveByte();
	while(copy_returnedData[i] != 255)
	{
		i++;
		copy_returnedData[i] = USART1_u8ReceiveByte();
	}

}
