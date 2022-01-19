#include "led.h"

void LED_Init(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);	 
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//失能JTAG

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	    		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);	  		


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	    		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);	  				 						 
}
 
void LED_demo(void)
{
	Sucker13_on();
	Delay_ms(2000);
	Sucker24_on();
	Delay_ms(2000);
	
}

//2*二位三通
void Sucker13_on(void)
{
	Air_pump_on
	Electromagnetic_valve1_Inhale
	Electromagnetic_valve2_Deflation
}

void Sucker13_off(void)
{
	Air_pump_on
	Electromagnetic_valve1_Deflation
}

void Sucker24_on(void)
{
	Air_pump_on
	Electromagnetic_valve1_Deflation
	Electromagnetic_valve2_Inhale
}

void Sucker24_off(void)
{
	Air_pump_on
	Electromagnetic_valve2_Deflation
}

void Sucker1234_on(void)
{
	Air_pump_on
	Electromagnetic_valve1_Inhale
	Electromagnetic_valve2_Inhale
}


// //二位三通+2*二位二通
// void Sucker13_on(void)
// {
// 	Air_pump_on
// 	Electromagnetic_valve1_Inhale
// 	Electromagnetic_valve2_disconnect
// 	Electromagnetic_valve3_disconnect
// }

// void Sucker13_off(void)
// {
// 	Air_pump_on
// 	Electromagnetic_valve1_Deflation
// 	Electromagnetic_valve2_disconnect
// 	Electromagnetic_valve3_disconnect
// }

// void Sucker24_on(void)
// {
// 	Air_pump_on
// 	Electromagnetic_valve1_Deflation
// 	Electromagnetic_valve2_disconnect
// 	Electromagnetic_valve3_connect
// }

// void Sucker24_off(void)
// {
// 	Air_pump_on
// 	Electromagnetic_valve1_Deflation
// 	Electromagnetic_valve2_connect
// 	Electromagnetic_valve3_connect
// }


