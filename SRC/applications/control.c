#include "control.h"


void Get_Position(void)
{
	
	mix_leg_XYZ.x[0]=trot_leg_XYZ.x[0]+pos_leg_XYZ.x[0];
	mix_leg_XYZ.y[0]=trot_leg_XYZ.y[0]+pos_leg_XYZ.y[0];
	mix_leg_XYZ.z[0]=trot_leg_XYZ.z[0]+pos_leg_XYZ.z[0];

	mix_leg_XYZ.x[1]=trot_leg_XYZ.x[1]+pos_leg_XYZ.x[1];
	mix_leg_XYZ.y[1]=trot_leg_XYZ.y[1]+pos_leg_XYZ.y[1];
	mix_leg_XYZ.z[1]=trot_leg_XYZ.z[1]+pos_leg_XYZ.z[1];

	mix_leg_XYZ.x[2]=trot_leg_XYZ.x[2]+pos_leg_XYZ.x[2];
	mix_leg_XYZ.y[2]=trot_leg_XYZ.y[2]+pos_leg_XYZ.y[2];
	mix_leg_XYZ.z[2]=trot_leg_XYZ.z[2]+pos_leg_XYZ.z[2];

	mix_leg_XYZ.x[3]=trot_leg_XYZ.x[3]+pos_leg_XYZ.x[3];
	mix_leg_XYZ.y[3]=trot_leg_XYZ.y[3]+pos_leg_XYZ.y[3];
	mix_leg_XYZ.z[3]=trot_leg_XYZ.z[3]+pos_leg_XYZ.z[3];

	caculate();
	
}



// TX->TX(PA2),RX->RX(PA3)
void DOG_CONTROL(void)
{
	if(Motion.start==1)
	{
		position(1,init_leg_angle.gamma[0]);
		position(2,init_leg_angle.alfa[0]); 
		position(3,init_leg_angle.beta[0]);  

		position(4,init_leg_angle.gamma[1]);
		position(5,init_leg_angle.alfa[1]);
		position(6,init_leg_angle.beta[1]); 

		position(7,init_leg_angle.gamma[2]);
		position(8,init_leg_angle.alfa[2]);
		position(9,init_leg_angle.beta[2]);  

		position(10,init_leg_angle.gamma[3]);
		position(11,init_leg_angle.alfa[3]);
		position(12,init_leg_angle.beta[3]);
		
//		position(13,init_head_servo);
	}
	else
	{


		State_Detection();

		// demo();
		// PA_PO_Task();
		
		POS_STAB();
		Get_Position();
		servo_output();	
  	}	
}
u8 opmv_sta_times = 10;         //¼ì²â´ÎÊý
u8 Turn_Left_Right_TIMES = 6;   //×ª½ÇÖÜÆÚ
void State_Detection(void)
{
	if(PA_PO_FLAG == 1)
	{
		switch (opmv.lt.sta)
		{
			case 2: {                          //×ó×ªÅÐ¶Ï
				while(opmv_sta_times > 0)
				{
					Delay_us(50);
					if(opmv.lt.sta != 2) break;
					opmv_sta_times--;
				}
				if(opmv_sta_times == 0)
				{
					Turn_Left_FLAG = 1;
					Turn_Left_Status_TIMES = 0;
					PA_PO_FLAG = 0;
					PA_PO_Status_TIMES = 0;
				}
				break; 
			}
			case 3:{                          //ÓÒ×ªÅÐ¶Ï
				while(opmv_sta_times > 0)
				{
					Delay_us(50);
					if(opmv.lt.sta != 3) break;
					opmv_sta_times--;
				}
				if(opmv_sta_times == 0)
				{
					Turn_Right_FLAG = 1;
					Turn_Right_Status_TIMES = 0;
					PA_PO_FLAG = 0;
					PA_PO_Status_TIMES = 0;
				}
				break; 
			}
			default:{
				PA_PO_FLAG = 1;
				break;
			} 
		}
	}
	//ÅÀÆÂ»ò×ªÍä->ÅÀÆÂ
	if(PA_PO_FLAG == 1 || Turn_Left_Status_TIMES > Turn_Left_Right_TIMES || Turn_Right_Status_TIMES > Turn_Left_Right_TIMES){
		PA_PO_Task();         
		Turn_Left_FLAG = 0;
		Turn_Right_FLAG = 0;
		PA_PO_FLAG = 1;
	}
	//×ó×ª
	if(Turn_Left_FLAG == 1 & Turn_Left_Status_TIMES <= Turn_Left_Right_TIMES){
		if(PA_PO_Status_TIMES < 4){            //ÑÓ³Ù
			PA_PO_Task();
		}
		else{
			Turn_Left_Task();
		}
		
	}
	//ÓÒ×ª
	if(Turn_Right_FLAG == 1 & Turn_Right_Status_TIMES <= Turn_Left_Right_TIMES){
		if(PA_PO_Status_TIMES < 4){
			PA_PO_Task();
		}
		else{
			Turn_Right_Task();
		}
	}
	
}

void demo(void)
{
	position(11,20);
	Delay_ms(1000);
	position(11,50);
	Delay_ms(1000);
}

void TIM1_UP_IRQHandler(void)
{

	if(TIM_GetITStatus(TIM1,TIM_IT_Update))
	{
		// Filter_Get_Angle();   //4.7ms
		
//		AHRS_Get_Angle();     //2.8ms

	}
	
	TIM_ClearITPendingBit(TIM1,TIM_IT_Update|TIM_IT_CC1);
}

void lanya(u8 data)
{
	switch(data)
	{
		case 1:  break;
		case 2: Turn_Left_Task(); break;
		case 3: Forward_Task();  break;
		case 4: Turn_Right_Task(); break;
		case 5:  break;
		case 6: Left_Shift_Task(); break;
		case 7: stand();  break;
		case 8: Right_Shift_Task(); break;
		case 9:  break;
		case 10:  break;
		case 11: Back_Task(); break;
		case 12:  break;
		default:stand();
	}
}

