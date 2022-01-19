#include "servo.h"

void pwm_servo_init(void)
{
	TIM2_PWM_Init(SERVO_TIM_ARR,SERVO_TIM_PSC);
	TIM3_PWM_Init(SERVO_TIM_ARR,SERVO_TIM_PSC);
	TIM4_PWM_Init(SERVO_TIM_ARR,SERVO_TIM_PSC);
//	TIM1_PWM_Init(SERVO_TIM_ARR,SERVO_TIM_PSC);
}

void position(u8 ID ,u16 degrees)
{ 
	u16 pulse;
	switch(ID)
	{
		case 1:
		{
			degrees = LIMIT(degrees,5,115);
			pulse = (uint16_t)(900 + degrees * 10); 
			TIM_SetCompare1(TIM2, pulse);      
			break;
		}
		case 2:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 

			TIM_SetCompare2(TIM2, pulse);  
			break;
		}
		case 3:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare3(TIM2, pulse);  
			break;
		}
		
		case 4:
		{
			degrees = LIMIT(degrees,5,115);
			pulse = (uint16_t)(900 + degrees * 10); 
			TIM_SetCompare4(TIM2, pulse);  
			break;
		}
		case 5:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare1(TIM3, pulse);  
			break;
		}
		case 6:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare2(TIM3, pulse);  
			break;
		}
		
		case 7:
		{
			degrees = LIMIT(degrees,5,115);
			pulse = (uint16_t)(900 + degrees * 10); 
			TIM_SetCompare3(TIM3, pulse);    
			break;
		}
		case 8:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare4(TIM3, pulse);    
			break;
		}
		case 9:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare1(TIM4, pulse);    
			break;
		}
		
		case 10:
		{
			degrees = LIMIT(degrees,5,115);
			pulse = (uint16_t)(900 + degrees * 10); 
			TIM_SetCompare2(TIM4, pulse);  
			break;
		}
		case 11:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare3(TIM4, pulse);   
			break;
		}
		case 12:
		{
			degrees = LIMIT(degrees,5,175);
			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare4(TIM4, pulse);    
			break;
		}
		
		case 13:
		{
//			LIMIT(degrees,5,175);
//			pulse = (uint16_t)(500 + degrees * 100/9.0); 
			TIM_SetCompare1(TIM1, pulse);   
			break;
		}
		case 14:
		{
			degrees = LIMIT(degrees,500,2500);
			TIM_SetCompare4(TIM1, degrees);    
			break;
		}
		default:;
	}
	
}
 



