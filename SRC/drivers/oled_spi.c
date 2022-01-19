#include "oled_spi.h"

//================模拟spi===============

void OLED_SPI_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
		

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);	 
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//失能JTAG
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_13|GPIO_Pin_15;//端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;     //2M
  GPIO_Init(GPIOB, &GPIO_InitStructure);					      //根据设定参数初始化GPIO 
			
	
	OLED_RST_Clr();
	Delay_ms(100);
	OLED_RST_Set(); 
}

//向OLED写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat,u8 cmd)
{	
	u8 i;			  
	if(cmd)
	  OLED_DC_Set();
	else 
	  OLED_DC_Clr();		  
	for(i=0;i<8;i++)
	{			  
		OLED_SCL_Clr();
		if(dat&0x80)
		   OLED_SDA_Set();
		else 
		   OLED_SDA_Clr();
		OLED_SCL_Set();
		dat<<=1;   
	}				 		  
	OLED_DC_Set();   	  
} 


////=============   硬件spi  可用   ==============
//void SPI_Configuration(void)
//{
//	SPI_InitTypeDef  SPI_InitStructure;
//	GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB1PeriphClockCmd(SPI_RCC_APB1Periph_SPIX, ENABLE);
//	RCC_APB2PeriphClockCmd(SPI_RCC_APB2Periph_GPIOX|RCC_APB2Periph_AFIO,ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = SPI_CS_Pin_X;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(SPI_CS_GPIOX, &GPIO_InitStructure);  
//	OLED_CS_HIGH();
//	
//	GPIO_InitStructure.GPIO_Pin = SPI_HW_ALL_PINS;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_Init(SPI_HW_ALL_GPIOX, &GPIO_InitStructure);   
//	
//	
//	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;//SPI_Direction_1Line_Tx; 
//	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;	 			
//	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;	 	
//	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		 	
//	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;		
//	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		  
//	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
//	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;  			
//	SPI_InitStructure.SPI_CRCPolynomial = 7;
//	
//	SPI_Init(SPIX, &SPI_InitStructure);  
//	SPI_Cmd(SPIX, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = SPI_RES_PIN;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(SPI_RES_GPIOX, &GPIO_InitStructure);  
//	GPIO_InitStructure.GPIO_Pin = SPI_DC_PIN;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_Init(SPI_DC_GPIOX, &GPIO_InitStructure);  
//	OLED_DATA_MODE();
//	
//	OLED_RESET_HIGH();
//	Delay_ms(100);
//	OLED_RESET_LOW();
//	Delay_ms(100);
//	OLED_RESET_HIGH();
//}

//void SPI_WriterByte(unsigned char dat)
//{

//	while (SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_TXE) == RESET ){}; //检查指定的SPI标志位设置与否:发送缓存空标志位	  
//		SPI_I2S_SendData(SPIX, dat); //通过外设SPIx发送一个数据
//	while (SPI_I2S_GetFlagStatus(SPIX, SPI_I2S_FLAG_RXNE) == RESET){};//检查指定的SPI标志位设置与否:接受缓存非空标志位  						    
//	  SPI_I2S_ReceiveData(SPIX); //返回通过SPIx最近接收的数据	

//}
//void WriteCmd(unsigned char cmd)
//{
//	OLED_CMD_MODE();
//	OLED_CS_LOW();
//	SPI_WriterByte(cmd);
//	OLED_CS_HIGH();
//	OLED_DATA_MODE();
//}

//void WriteDat(unsigned char dat)
//{
//	OLED_DATA_MODE();
//	OLED_CS_LOW();
//	SPI_WriterByte(dat);
//	OLED_CS_HIGH();
//	OLED_DATA_MODE();
//}

//void OLED_WR_Byte(u8 dat,u8 cmd)
//{
//	if(cmd)
//	{
//		WriteDat(dat);
//	}
//	else
//	{
//		WriteCmd(dat);
//	}
//}

