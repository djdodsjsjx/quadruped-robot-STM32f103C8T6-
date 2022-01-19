#ifndef __OLED_SPI_H
#define __OLED_SPI_H
#include "config.h"

//=============   软件spi   ===========
#define OLED_RST_Clr() PBout(4)=0   //RST
#define OLED_RST_Set() PBout(4)=1   //RST

#define OLED_DC_Clr() PBout(3)=0    //DC
#define OLED_DC_Set() PBout(3)=1    //DC

#define OLED_SCL_Clr()  PBout(13)=0  //SCL
#define OLED_SCL_Set()  PBout(13)=1   //SCL

#define OLED_SDA_Clr()  PBout(15)=0   //SDA
#define OLED_SDA_Set()  PBout(15)=1   //SDA



////============   硬件spi   ===============

//#define OLED_RESET_LOW()					GPIO_ResetBits(SPI_RES_GPIOX, SPI_RES_PIN)	//低电平复位
//#define OLED_RESET_HIGH()					GPIO_SetBits(SPI_RES_GPIOX, SPI_RES_PIN)
// 
//#define OLED_CMD_MODE()						GPIO_ResetBits(SPI_DC_GPIOX, SPI_DC_PIN) 		//命令模式
//#define OLED_DATA_MODE()					GPIO_SetBits(SPI_DC_GPIOX, SPI_DC_PIN)			//数据模式

//#define OLED_CS_HIGH()   					GPIO_SetBits(SPI_CS_GPIOX, SPI_CS_Pin_X)
//#define OLED_CS_LOW()  		  			GPIO_ResetBits(SPI_CS_GPIOX, SPI_CS_Pin_X)

////===============DC->PB0  RES->PB1  SDA->PB15  SCL->PB13

//#define SPIX                      SPI2
////使能SPI2时钟
//#define SPI_RCC_APB1Periph_SPIX   RCC_APB1Periph_SPI2
////使能gpio时钟
//#define SPI_RCC_APB2Periph_GPIOX	RCC_APB2Periph_GPIOB	
////CS片选（软件片选）
//#define SPI_CS_Pin_X              GPIO_Pin_12
//#define SPI_CS_GPIOX							GPIOB
////SPI2 时钟、mosi、miso引脚
//#define SPI_HW_ALL_PINS          	(GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15) 
//#define SPI_HW_ALL_GPIOX					GPIOB
////复位引脚
//#define SPI_RES_PIN 							GPIO_Pin_1
//#define SPI_RES_GPIOX							GPIOB
////控制引脚
//#define SPI_DC_PIN 								GPIO_Pin_0
//#define SPI_DC_GPIOX							GPIOB


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

void OLED_SPI_Init(void);
void SPI_Configuration(void);
void SPI_WriterByte(unsigned char dat);
void WriteCmd(unsigned char cmd);
void WriteDat(unsigned char dat);
void OLED_WR_Byte(u8 dat,u8 cmd);

#endif
