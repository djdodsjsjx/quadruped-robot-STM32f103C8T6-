#include "usart.h"	  

u8 USART1_com_data;

void uart_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=NVIC_USART1_P ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = NVIC_USART1_S;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}


static u8 TxBuffer[256];
static u8 TxCounter=0;
static u8 Usart1_count=0;

void Uart1_Put_Char(unsigned char DataToSend)
{
	TxBuffer[Usart1_count++] = DataToSend;
	USART_ITConfig(USART1, USART_IT_TXE,ENABLE);
}
	
void Uart1_Put_Buf(unsigned char *DateToSend, u8 data_num)
{
	for(u8 i=0;i<data_num;i++)
		TxBuffer[Usart1_count++] = *(DateToSend+i);
	if(!(USART1->CR1 & USART_CR1_TXEIE))
	{
		USART_ITConfig(USART1, USART_IT_TXE,ENABLE);
	}
}

void USART1_IRQHandler(void)  
{
	if(USART_GetITStatus(USART1,USART_IT_ORE)!=RESET)
	{
		USART_ReceiveData(USART1);
	}
	
	//发送中断
  if(USART1->SR &(1<<7)&&(USART1->CR1&USART_CR1_TXEIE))
	{
		USART1->DR=TxBuffer[TxCounter++];
		if(TxCounter==Usart1_count)
		{
			USART1->CR1&=~USART_CR1_TXEIE;
			
		}
	}
	//接收中断
	if(USART1->SR &(1<<5))
	{
		USART1_com_data = USART1->DR;
//		Uart1_Put_Char(com_data);
	}
}


///重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USART1, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}


