#include "calculate.h"

u8 rotation_Angle_LIMIT_value = 5;

leg_angle rotation_Angle_LIMIT(leg_angle *Angle){

	Angle->gamma[0] = LIMIT_two(Angle->gamma[0],Last_leg_rotation_Angle.gamma[0],rotation_Angle_LIMIT_value);
	Angle->beta[0] = LIMIT_two(Angle->beta[0],Last_leg_rotation_Angle.beta[0],rotation_Angle_LIMIT_value);
	Angle->alfa[0] = LIMIT_two(Angle->alfa[0],Last_leg_rotation_Angle.alfa[0],rotation_Angle_LIMIT_value);
	Angle->gamma[1] = LIMIT_two(Angle->gamma[1],Last_leg_rotation_Angle.gamma[1],rotation_Angle_LIMIT_value);
	Angle->beta[1] = LIMIT_two(Angle->beta[1],Last_leg_rotation_Angle.beta[1],rotation_Angle_LIMIT_value);
	Angle->alfa[1] = LIMIT_two(Angle->alfa[1],Last_leg_rotation_Angle.alfa[1],rotation_Angle_LIMIT_value);
	Angle->gamma[0] = LIMIT_two(Angle->gamma[2],Last_leg_rotation_Angle.gamma[2],rotation_Angle_LIMIT_value);
	Angle->beta[0] = LIMIT_two(Angle->beta[2],Last_leg_rotation_Angle.beta[2],rotation_Angle_LIMIT_value);
	Angle->alfa[0] = LIMIT_two(Angle->alfa[2],Last_leg_rotation_Angle.alfa[2],rotation_Angle_LIMIT_value);
	Angle->gamma[0] = LIMIT_two(Angle->gamma[3],Last_leg_rotation_Angle.gamma[3],rotation_Angle_LIMIT_value);
	Angle->beta[0] = LIMIT_two(Angle->beta[3],Last_leg_rotation_Angle.beta[3],rotation_Angle_LIMIT_value);
	Angle->alfa[0] = LIMIT_two(Angle->alfa[3],Last_leg_rotation_Angle.alfa[3],rotation_Angle_LIMIT_value);

	Last_leg_rotation_Angle.gamma[0] = Angle->gamma[0];
	Last_leg_rotation_Angle.beta[0] = Angle->beta[0];
	Last_leg_rotation_Angle.alfa[0] = Angle->alfa[0];

	Last_leg_rotation_Angle.gamma[1] = Angle->gamma[1];
	Last_leg_rotation_Angle.beta[1] = Angle->beta[1];
	Last_leg_rotation_Angle.alfa[1] = Angle->alfa[1];

	Last_leg_rotation_Angle.gamma[2] = Angle->gamma[2];
	Last_leg_rotation_Angle.beta[2] = Angle->beta[2];
	Last_leg_rotation_Angle.alfa[2] = Angle->alfa[2];

	Last_leg_rotation_Angle.gamma[3] = Angle->gamma[3];
	Last_leg_rotation_Angle.beta[3] = Angle->beta[3];
	Last_leg_rotation_Angle.alfa[3] = Angle->alfa[3];
	
	return *Angle;
}

//============   Äæ½â   ==============
void caculate(void)
{
	float lxz[4],dyz[4],lyz[4];
		
	dyz[0]=sqrt(my_pow(mix_leg_XYZ.y[0])+my_pow(mix_leg_XYZ.z[0]));
	lyz[0]=sqrt(my_pow(dyz[0])-my_pow(Body.l3));
	lxz[0]=sqrt(my_pow(lyz[0])+my_pow(mix_leg_XYZ.x[0]));
	leg_rotation_Angle.gamma [0]=atan(lyz[0]/Body.l3)+atan(mix_leg_XYZ.z[0]/mix_leg_XYZ.y[0]);
	leg_rotation_Angle.beta [0]=MY_PI-acos((my_pow(Body.l1_12)+my_pow(Body.l2_12)-my_pow(lxz[0]))/(2*Body.l1_12*Body.l2_12));
	leg_rotation_Angle.alfa [0]=acos((my_pow(Body.l1_12)+my_pow(lxz[0])-my_pow(Body.l2_12))/(2*Body.l1_12*lxz[0]))-atan(mix_leg_XYZ.x[0]/lyz[0]);
	leg_rotation_Angle.gamma [0]=180*leg_rotation_Angle.gamma [0]/MY_PI;
	leg_rotation_Angle.beta [0]=180*leg_rotation_Angle.beta [0]/MY_PI;
	leg_rotation_Angle.alfa [0]=180*leg_rotation_Angle.alfa [0]/MY_PI;
	
	dyz[1]=sqrt(my_pow(mix_leg_XYZ.y[1])+my_pow(mix_leg_XYZ.z[1]));
	lyz[1]=sqrt(my_pow(dyz[1])-my_pow(Body.l3));
	lxz[1]=sqrt(my_pow(lyz[1])+my_pow(mix_leg_XYZ.x[1]));
	leg_rotation_Angle.gamma [1]=atan(lyz[1]/Body.l3)-atan(mix_leg_XYZ.z[1]/mix_leg_XYZ.y[1]);
	leg_rotation_Angle.beta [1]=MY_PI-acos((my_pow(Body.l1_12)+my_pow(Body.l2_12)-my_pow(lxz[1]))/(2*Body.l1_12*Body.l2_12));
	leg_rotation_Angle.alfa [1]=acos((my_pow(Body.l1_12)+my_pow(lxz[1])-my_pow(Body.l2_12))/(2*Body.l1_12*lxz[1]))-atan(mix_leg_XYZ.x[1]/lyz[1]);
	leg_rotation_Angle.gamma [1]=180*leg_rotation_Angle.gamma [1]/MY_PI;
	leg_rotation_Angle.beta [1]=180*leg_rotation_Angle.beta [1]/MY_PI;
	leg_rotation_Angle.alfa [1]=180*leg_rotation_Angle.alfa [1]/MY_PI;
	
	dyz[2]=sqrt(my_pow(mix_leg_XYZ.y[2])+my_pow(mix_leg_XYZ.z[2]));
	lyz[2]=sqrt(my_pow(dyz[2])-my_pow(Body.l3));
	lxz[2]=sqrt(my_pow(lyz[2])+my_pow(mix_leg_XYZ.x[2]));
	leg_rotation_Angle.gamma [2]=atan(lyz[2]/Body.l3)-atan(mix_leg_XYZ.z[2]/mix_leg_XYZ.y[2]);
	leg_rotation_Angle.beta [2]=MY_PI-acos((my_pow(Body.l1_34)+my_pow(Body.l2_34)-my_pow(lxz[2]))/(2*Body.l1_34*Body.l2_34));
	leg_rotation_Angle.alfa [2]=acos((my_pow(Body.l1_34)+my_pow(lxz[2])-my_pow(Body.l2_34))/(2*Body.l1_34*lxz[2]))-atan(mix_leg_XYZ.x[2]/lyz[2]);
	leg_rotation_Angle.gamma [2]=180*leg_rotation_Angle.gamma [2]/MY_PI;
	leg_rotation_Angle.beta [2]=180*leg_rotation_Angle.beta [2]/MY_PI;
	leg_rotation_Angle.alfa [2]=180*leg_rotation_Angle.alfa [2]/MY_PI;
	
	dyz[3]=sqrt(my_pow(mix_leg_XYZ.y[3])+my_pow(mix_leg_XYZ.z[3]));
	lyz[3]=sqrt(my_pow(dyz[3])-my_pow(Body.l3));
	lxz[3]=sqrt(my_pow(lyz[3])+my_pow(mix_leg_XYZ.x[3]));
	leg_rotation_Angle.gamma [3]=atan(lyz[3]/Body.l3)+atan(mix_leg_XYZ.z[3]/mix_leg_XYZ.y[3]);
	leg_rotation_Angle.beta [3]=MY_PI-acos((my_pow(Body.l1_34)+my_pow(Body.l2_34)-my_pow(lxz[3]))/(2*Body.l1_34*Body.l2_34));
	leg_rotation_Angle.alfa [3]=acos((my_pow(Body.l1_34)+my_pow(lxz[3])-my_pow(Body.l2_34))/(2*Body.l1_34*lxz[3]))-atan(mix_leg_XYZ.x[3]/lyz[3]);	
	leg_rotation_Angle.gamma [3]=180*leg_rotation_Angle.gamma [3]/MY_PI;
	leg_rotation_Angle.beta [3]=180*leg_rotation_Angle.beta [3]/MY_PI;
	leg_rotation_Angle.alfa [3]=180*leg_rotation_Angle.alfa [3]/MY_PI;
	

//	leg_rotation_Angle = rotation_Angle_LIMIT(&leg_rotation_Angle);

	// DT_SendF1(leg_rotation_Angle.alfa [0],
	//           leg_rotation_Angle.beta [0],
	// 		 leg_rotation_Angle.alfa [1],leg_rotation_Angle.beta [1],0,0);
	

}


//=============   ¶æ»úÊä³ö   ==================
void servo_output(void)
{	
	
	position(1,init_leg_angle.gamma[0]+leg_rotation_Angle.gamma [0]);
	position(2,init_leg_angle.alfa[0]-(90-leg_rotation_Angle.alfa [0])); 
	position(3,init_leg_angle.beta[0]-(90-leg_rotation_Angle.beta [0]));  
	
	position(4,init_leg_angle.gamma[1]-leg_rotation_Angle.gamma [1]);
	position(5,init_leg_angle.alfa[1]+(90-leg_rotation_Angle.alfa [1]));
	position(6,init_leg_angle.beta[1]+(90-leg_rotation_Angle.beta [1])); 
	
	position(7,init_leg_angle.gamma[2]+leg_rotation_Angle.gamma [2]);
	position(8,init_leg_angle.alfa[2]+(90-leg_rotation_Angle.alfa [2]));
	position(9,init_leg_angle.beta[2]+(90-leg_rotation_Angle.beta [2]));  
	
	position(10,init_leg_angle.gamma[3]-leg_rotation_Angle.gamma [3]);
	position(11,init_leg_angle.alfa[3]-(90-leg_rotation_Angle.alfa [3]));
	position(12,init_leg_angle.beta[3]-(90-leg_rotation_Angle.beta [3]));

}


