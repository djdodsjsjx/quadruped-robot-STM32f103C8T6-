#include "config.h"

float prep_time,launch_time,fall_time,stance_height,jump_extension,fall_extension,x_jump;
float IMU_ROL_Kp_G,IMU_PIT_Kp_G,IMU_POSX_12_Kp_G,IMU_POSX_34_Kp_G,OPENMV_Angle_Kp_G,OPENMV_Deviation_Kp_G;
float init_head_servo;
u8 pit_max_ang,rol_max_ang;
u8 PA_PO_FLAG,PA_PO_Status_TIMES,Turn_Left_FLAG,Turn_Left_Status_TIMES,Turn_Right_FLAG,Turn_Right_Status_TIMES;
leg_XYZ pos_leg_XYZ;
leg_XYZ trot_leg_XYZ;
leg_XYZ mix_leg_XYZ;
leg_angle angle_output;
leg_angle leg_rotation_Angle;
leg_angle init_leg_angle;
leg_angle Last_leg_rotation_Angle;
Body_parameters Body;
Motion_parameters Motion;

void data_config()
{
	Motion.start=0;   // 1->校准     0->运行
	Motion.faai=0.5;  	//0.25->walk步态     0.5->trot步态
	
	Body.l1_12 = 70;
	Body.l1_34 = 80;
	Body.l2_12=57;
	Body.l2_34=80;
	Body.l3=35;
	Body.b=85;     //两前足基座原点之间的距离
	Body.l=183;    //足端在长度方向距离
	Body.h=85;
	Body.w=Body.b+2*Body.l3;    //足端在宽度方向距离
	
	
	Motion.trot_speed=0.014;   //步频  
	Motion.turn_speed=0.01;
	Motion.t=0;           //时间
	Motion.Ts=1;        //周期
	Motion.h=45;
	// Motion.h_12=10;       //抬腿高度
	// Motion.h_34=40;
	
	IMU_ROL_Kp_G=1;         //姿态控制比例系数
	IMU_PIT_Kp_G=0;
	IMU_POSX_12_Kp_G=1.5;
	IMU_POSX_34_Kp_G=1.2;
	OPENMV_Angle_Kp_G=0.3;
	OPENMV_Deviation_Kp_G=0.1;

	pit_max_ang=15;    //横滚角极限值
	rol_max_ang=25;    //俯仰角极限值
	
	init_head_servo=90;   //头部舵机初始值
	
	init_leg_angle.gamma[0]=65;      // 大->上   小->下
	init_leg_angle.alfa[0]=160;      //	小->下   大->上
	init_leg_angle.beta[0]=80;       // 小->右   大->左 
	
	init_leg_angle.gamma[1]=60;	    //   大->下  小->上
	init_leg_angle.alfa[1]=10;      //   小->上  大->下
	init_leg_angle.beta[1]=100;      //   小->左  大->右	

	init_leg_angle.gamma[2]=53;     //   大->上  小->下
	init_leg_angle.alfa[2]=18;			//   小->上  大->下
	init_leg_angle.beta[2]=90;		  //   小->左  大->右	

	init_leg_angle.gamma[3]=50;     //   大->下  小->上
	init_leg_angle.alfa[3]=168;			//   小->下  大->上
	init_leg_angle.beta[3]=88;			//   小->右  大->左			
	

	//跳跃参数设置
	prep_time = 0.3;      //跳跃准备时间
	launch_time = 0.5;    //跳跃持续时间
	fall_time = 0.4;      //下降持续时间
	stance_height = -60;   //跳前收腿长度(mm)
	jump_extension = -140; //跳时腿伸张长度(mm)
	fall_extension = -60;  //下降时腿长度(mm)
	x_jump=-10;           //x初始起跳位置

}

void init_config(void)
{  
	SysTick_Configuration();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(500000); 	
	Usart3_Init(500000);
	Scheduler_Setup();
	pwm_servo_init();	
	LED_Init();	
	OLED_Init();
	MPU6050_initialize();
	TIM_INIT();
//	
//	MPU9250_INIT();
	Dog_Start();
}
