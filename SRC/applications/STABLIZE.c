#include "STABLIZE.h"

float Sta_Pitch=0,Sta_Rol=0,recover_node=0,recover_node_1=0;
u8 Sta_flag=0;

//==========   µøµ¹»Ø¸´Æ½ºâ   ============
void recover()
{
	static u32 time_begin=0;
	if(time_begin==0)
	{
		time_begin=SysTick_GetTick();
	}
	if(Sta_flag==1)
	{
		mix_leg_XYZ.z[0]=80;     mix_leg_XYZ.z[1]=20;     mix_leg_XYZ.z[2]=20;     mix_leg_XYZ.z[3]=80;
		mix_leg_XYZ.x[0]=-60;    mix_leg_XYZ.x[1]=0;      mix_leg_XYZ.x[2]=0;      mix_leg_XYZ.x[3]=-60;
	}
	else if(Sta_flag==2)
	{
		mix_leg_XYZ.z[0]=20;     mix_leg_XYZ.z[1]=80;     mix_leg_XYZ.z[2]=80;     mix_leg_XYZ.z[3]=20;	
		mix_leg_XYZ.x[0]=0;      mix_leg_XYZ.x[1]=-60;    mix_leg_XYZ.x[2]=-60;    mix_leg_XYZ.x[3]=0;
	}
	
	if(SysTick_GetTick()-time_begin>1000)
	{
		mix_leg_XYZ.z[0]=50;     mix_leg_XYZ.z[1]=50;     mix_leg_XYZ.z[2]=50;     mix_leg_XYZ.z[3]=50;	
		mix_leg_XYZ.x[0]=0;      mix_leg_XYZ.x[1]=0;      mix_leg_XYZ.x[2]=0;      mix_leg_XYZ.x[3]=0;
	}
	if(SysTick_GetTick()-time_begin>2000)
	{
		mix_leg_XYZ.z[0]=0;      mix_leg_XYZ.z[1]=0;      mix_leg_XYZ.z[2]=0;        mix_leg_XYZ.z[3]=0;	
		mix_leg_XYZ.x[0]=0;      mix_leg_XYZ.x[1]=0;      mix_leg_XYZ.x[2]=0;   	 mix_leg_XYZ.x[3]=0;
	}
	if(SysTick_GetTick()-time_begin>3000)
	{
		time_begin=0;
		Sta_flag=0;
		Motion.t=0;
		recover_node=0;
		recover_node_1=0;
		Sta_Pitch=0;
		Sta_Rol=0;
		PIT_S=0;
		ROL_S=0;
	}

}
//===========   ï¿½ï¿½ï¿½ï¿½   ==========
void stab(void)
{
	if (ABS(Dog_PIT)>3)
		Sta_Pitch-=Dog_PIT*0.05;
	Sta_Pitch = LIMIT(Sta_Pitch,-pit_max_ang,pit_max_ang);
	
	if (ABS(Dog_ROL)>3)
		Sta_Rol-=Dog_ROL*0.05;
	Sta_Rol = LIMIT(Sta_Rol,-rol_max_ang,rol_max_ang);
	
//	if (Dog_PIT<=-50)
//		recover_node=recover_node+0.1;
//	else if (Dog_PIT>=50)
//		recover_node_1=recover_node_1+0.1;
//	else
//	{
//		recover_node=0;
//		recover_node_1=0;
//	}
//	
//	if (recover_node>=5)
//	{
//		Sta_flag=1;
//		recover();
//	}
//	else if (recover_node_1>=5)
//	{
//		Sta_flag=2;
//		recover();
//	}
	
	if(Sta_flag==0)	cal_ges(Sta_Rol,Sta_Pitch,0,0,0,0);
}

