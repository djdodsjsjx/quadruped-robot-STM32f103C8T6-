#include "opmv_linetracking.h"

float head_servo_output=0;
u8 CONFIRM_TIMES=2,confirm_cnt;

float avg_angle,avg_deviation;
	
void LTracking_Ctrl(void)
{
		
}



void error_confirm(void)
{
	if(confirm_cnt<CONFIRM_TIMES)
	{
		confirm_cnt++;
	}
	else
	{
		confirm_cnt=0;
	}
}

void head_servo_task(void)
{
//	WritePos(13,init_head_servo+20,0,500);
//	Delay_ms(1000);
//	WritePos(13,init_head_servo-20,0,500);
//	Delay_ms(1000);
//	WritePos(13,init_head_servo,0,500);
//	Delay_ms(2000);
	
}

void average(void)
{
	avg_angle=sum_angle/opmv_t;
	avg_deviation=sum_deviation/opmv_t;
	opmv_t=0;
	sum_angle=0;
	sum_deviation=0;
}

