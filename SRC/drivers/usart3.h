#ifndef __USART3_H
#define __USART3_H

#include "config.h"
extern u8 OPENMV_com_data;
//´®¿Ú3³õÊ¼»¯
void Usart3_Init(u32 bound);
void Uart3_Put_Char(unsigned char DataToSend);
void Uart3_Put_Buf(unsigned char *DateToSend, u8 data_num);
void Usart3_SendByte(uint8_t data);
void Usart3_SendWord(uint16_t data);
void Openmv_Receive_Data(int16_t data);
void USART3_Rx_Task(void);
#endif

