#include "Posture_control.h"

float PIT_S,ROL_S,POS_X_S,POS_Z_S;

s16 Cal_Ges_ROL,Cal_Ges_PIT;

//自稳
void POS_STAB(void)
{
	Cal_Ges_ROL = LIMIT(Dog_ROL,-rol_max_ang,rol_max_ang);
	Cal_Ges_PIT = LIMIT(Dog_PIT,-pit_max_ang,pit_max_ang);
	cal_ges(IMU_ROL_Kp_G*Cal_Ges_ROL-5,IMU_PIT_Kp_G*Cal_Ges_PIT,0,0,0,0);     //1.9ms
	// if (ABS(Cal_Ges_ROL)>3 || ABS(Cal_Ges_PIT)>3){
	// 	cal_ges(IMU_ROL_Kp_G*Cal_Ges_ROL,IMU_PIT_Kp_G*Cal_Ges_PIT,0,0,0,0);     //1.9ms
	// }
	
}

//============   姿态调节   =============
void POS_Adjust(float ROL_goal,float PIT_goal)
{
	if (PIT_goal>PIT_goal)
		PIT_S=PIT_S-ABS(PIT_S-PIT_goal)*IMU_PIT_Kp_G;
	else if (PIT_S<PIT_goal)
		PIT_S=PIT_S+ABS(PIT_S-PIT_goal)*IMU_PIT_Kp_G;

	if (ROL_S>ROL_goal)
		ROL_S=ROL_S-ABS(ROL_S-ROL_goal)*IMU_ROL_Kp_G;
	else if (ROL_S<ROL_goal)
		ROL_S=ROL_S+ABS(ROL_S-ROL_goal)*IMU_ROL_Kp_G;
		
	cal_ges(ROL_S,PIT_S,0,0,0,0);
	
}

//===========   姿态控制   ==============
void cal_ges(float ROL,float PIT,float YAW,float POS_X,float POS_Y,float POS_Z)
{
	float P=PIT*MY_PI/180;
	float R=ROL*MY_PI/180;
	float Y=YAW*MY_PI/180;

	pos_leg_XYZ.x[0]=-POS_X  -  (Body.l*cos(R)*cos(Y))/2 + (Body.b*cos(R)*sin(Y))/2 + Body.l/2;
	pos_leg_XYZ.y[0]=-POS_Y  -  (Body.l*(cos(P)*sin(Y) + cos(Y)*sin(P)*sin(R)))/2 - (Body.b*(cos(P)*cos(Y) - sin(P)*sin(R)*sin(Y)))/2 +  Body.w/2;
	pos_leg_XYZ.z[0]=-POS_Z  -  (Body.l*(sin(P)*sin(Y) - cos(P)*cos(Y)*sin(R)))/2 - (Body.b*(cos(Y)*sin(P) + cos(P)*sin(R)*sin(Y)))/2 -  Body.h;

	pos_leg_XYZ.x[1]=-POS_X  -  (Body.l*cos(R)*cos(Y))/2 - (Body.b*cos(R)*sin(Y))/2 + Body.l/2;
	pos_leg_XYZ.y[1]=-POS_Y  -  (Body.l*(cos(P)*sin(Y) + cos(Y)*sin(P)*sin(R)))/2 + (Body.b*(cos(P)*cos(Y) - sin(P)*sin(R)*sin(Y)))/2 -  Body.w/2;
	pos_leg_XYZ.z[1]=-POS_Z  -  (Body.l*(sin(P)*sin(Y) - cos(P)*cos(Y)*sin(R)))/2 + (Body.b*(cos(Y)*sin(P) + cos(P)*sin(R)*sin(Y)))/2 -  Body.h;

	pos_leg_XYZ.x[2]=-POS_X  +  (Body.l*cos(R)*cos(Y))/2 - (Body.b*cos(R)*sin(Y))/2 - Body.l/2;
	pos_leg_XYZ.y[2]=-POS_Y  +  (Body.l*(cos(P)*sin(Y) + cos(Y)*sin(P)*sin(R)))/2 + (Body.b*(cos(P)*cos(Y) - sin(P)*sin(R)*sin(Y)))/2 -  Body.w/2;
	pos_leg_XYZ.z[2]=-POS_Z  +  (Body.l*(sin(P)*sin(Y) - cos(P)*cos(Y)*sin(R)))/2 + (Body.b*(cos(Y)*sin(P) + cos(P)*sin(R)*sin(Y)))/2 -  Body.h;

	pos_leg_XYZ.x[3]=-POS_X  +  (Body.l*cos(R)*cos(Y))/2 + (Body.b*cos(R)*sin(Y))/2 - Body.l/2;
	pos_leg_XYZ.y[3]=-POS_Y  +  (Body.l*(cos(P)*sin(Y) + cos(Y)*sin(P)*sin(R)))/2 - (Body.b*(cos(P)*cos(Y) - sin(P)*sin(R)*sin(Y)))/2 +  Body.w/2;
	pos_leg_XYZ.z[3]=-POS_Z  +  (Body.l*(sin(P)*sin(Y) - cos(P)*cos(Y)*sin(R)))/2 - (Body.b*(cos(Y)*sin(P) + cos(P)*sin(R)*sin(Y)))/2 -  Body.h;
	

}

