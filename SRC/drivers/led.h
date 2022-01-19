#ifndef __LED_H
#define __LED_H	 
#include "config.h"
 

#define Air_pump_on   PBout(12) = 1;   //气泵开
#define Air_pump_off  PBout(12) = 0;   //气泵关

//二位三通
#define Electromagnetic_valve1_Inhale   PBout(14) = 0;   //气泵->吸盘
#define Electromagnetic_valve1_Deflation   PBout(14) = 1;   //气泵->空气

#define Electromagnetic_valve2_Inhale   PAout(12) = 0;   //气泵->吸盘
#define Electromagnetic_valve2_Deflation   PAout(12) = 1;   //气泵->空气

#define Electromagnetic_valve3_Inhale   PAout(15) = 0;   //气泵->吸盘
#define Electromagnetic_valve3_Deflation   PAout(15) = 1;   //气泵->空气

//二位二通  常闭
//气泵接空气
#define Electromagnetic_valve2_connect   PBout(14) = 0;   //电磁阀导通   
#define Electromagnetic_valve2_disconnect   PBout(14) = 1;   //电磁阀断开

#define Electromagnetic_valve3_connect   PBout(15) = 0;   //电磁阀导通   
#define Electromagnetic_valve3_disconnect   PBout(15) = 1;   //电磁阀断开   

void LED_Init(void);//初始化
void LED_demo(void);
void Sucker13_on(void);
void Sucker13_off(void);
void Sucker24_on(void);
void Sucker24_off(void);	
void Sucker1234_on(void);	 				    
#endif
