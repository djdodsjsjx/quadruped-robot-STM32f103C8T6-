#ifndef __CONFIG_H
#define __CONFIG_H

#include "stm32f10x.h"
#include "usart.h"
#include "usart3.h"
#include "pwm.h"
#include "servo.h"
#include "gait.h" 
#include "openmv.h"
#include "calculate.h"
#include "control.h"
#include "math.h"
#include "stdlib.h"
#include "DT.h"
#include "Scheduler.h"
#include "time.h"
#include "filter.h"
#include "mpu6050.h"
#include "mpu9250.h"
#include "mpuiic.h"
#include "oled.h"
#include "show.h"
#include "oled_spi.h"
#include "my_math.h"
#include "led.h"
#include "Posture_control.h"
#include "STABLIZE.h"
#include "opmv_linetracking.h"
#include "gait_task.h"



#define NVIC_TIME_P       2					  
#define NVIC_TIME_S       2

#define NVIC_USART1_P       0					
#define NVIC_USART1_S       1

#define NVIC_USART3_P       1					
#define NVIC_USART3_S       2


#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

typedef struct
{
	float x[4];
	float y[4];
	float z[4];
}leg_XYZ;


extern leg_XYZ pos_leg_XYZ;
extern leg_XYZ trot_leg_XYZ;
extern leg_XYZ mix_leg_XYZ;

typedef struct
{
	float alfa[4];
	float beta[4];
	float gamma[4];
}leg_angle;

extern leg_angle angle_output;
extern leg_angle Last_leg_rotation_Angle;
extern leg_angle leg_rotation_Angle;
extern leg_angle init_leg_angle;

typedef struct
{
	float l1_12;
	float l1_34;
	float l2_12;
	float l2_34;
	float l3;
	float b;
	float l;
	float w;
	float h;
}Body_parameters;

extern Body_parameters Body;

typedef struct
{
	u8 start;
	float trot_speed;
	float turn_speed;
	float faai;
	float t;
	float h;
	float h_1;
	float h_2;
	float h_3;
	float h_4;
	float Ts;
	float xs[4];
	float xf[4];
	float ys[4];
	float yf[4];
}Motion_parameters;
extern Motion_parameters Motion;

extern float IMU_ROL_Kp_G,IMU_PIT_Kp_G,IMU_POSX_12_Kp_G,IMU_POSX_34_Kp_G,OPENMV_Angle_Kp_G,OPENMV_Deviation_Kp_G;
extern float init_head_servo;
extern float prep_time,launch_time,fall_time,stance_height,jump_extension,fall_extension,x_jump;
extern u8 pit_max_ang,rol_max_ang;
extern u8 PA_PO_FLAG,PA_PO_Status_TIMES,Turn_Left_FLAG,Turn_Left_Status_TIMES,Turn_Right_FLAG,Turn_Right_Status_TIMES;

void data_config(void);
void init_config(void);
#endif

