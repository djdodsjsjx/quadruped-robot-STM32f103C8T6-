#include "gait.h" 

float sigma,zep,zep_1,zep_2,zep_3,zep_4,xep_b,xep_z,xep_z1,xep_z2,xep_z3,yep_b,yep_z,yep_z1,yep_z2,yep_z3,
			xep_b_1,xep_b_2,xep_z_1,xep_z_2,xep_b_3,xep_b_4,xep_z_3,xep_z_4,
			yep_b_1,yep_b_2,yep_z_1,yep_z_2,yep_b_3,yep_b_4,yep_z_3,yep_z_4;


void walk_XZ(float t)
{	
	if (t<=Motion.Ts*Motion.faai)
	{
//		if(t==trot_speed)
//		{
//			Delay_ms(1000);
//		}
			sigma=2*MY_PI*t/(Motion.faai*Motion.Ts);
			xep_b=(Motion.xf[0]-Motion.xs[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[0];
			xep_z1=((Motion.xs[3]-Motion.xf[3])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[3];
			xep_z2=((Motion.xs[2]-Motion.xf[2])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xf[2]+Motion.xs[2])/3; 
			xep_z3=((Motion.xs[1]-Motion.xf[1])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xs[1]+Motion.xf[1])/3;
			zep=Motion.h*(1-cos(sigma))/2;

			contorl_1_leg(xep_b, 0,zep);
			contorl_2_leg(xep_z3,0,0);
			contorl_3_leg(xep_z2,0,0);
			contorl_4_leg(xep_z1,0,0);
//		}
//		else
//		{
//			t=t-trot_speed;
//		}
	}

	if (t>Motion.Ts*Motion.faai && t<Motion.Ts/2)
	{
//		if((t-Ts*faai)<=trot_speed)
//		{
//			Delay_ms(1000);
//		}
			sigma=2*MY_PI*(t-Motion.Ts*Motion.faai)/(Motion.faai*Motion.Ts);
			xep_b=(Motion.xf[1]-Motion.xs[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[1];
			xep_z1=((Motion.xs[0]-Motion.xf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[0];
			xep_z2=((Motion.xs[3]-Motion.xf[3])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xf[3]+Motion.xs[3])/3; 
			xep_z3=((Motion.xs[2]-Motion.xf[2])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xs[2]+Motion.xf[2])/3;
			zep=Motion.h*(1-cos(sigma))/2;
		
			contorl_1_leg(xep_z1,0,0);
			contorl_2_leg(xep_b, 0,zep);
			contorl_3_leg(xep_z3,0,0);
			contorl_4_leg(xep_z2,0,0);
		
	}

	if (t>Motion.Ts/2 && t<Motion.Ts*3/4)
	{
//		if((t-Ts/2)<=trot_speed)
//		{
//			Delay_ms(1000);
//		}
			sigma=2*MY_PI*(t-Motion.Ts/2)/(Motion.faai*Motion.Ts);
			xep_b=(Motion.xf[2]-Motion.xs[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[2];
			xep_z1=((Motion.xs[1]-Motion.xf[1])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[1];
			xep_z2=((Motion.xs[0]-Motion.xf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xf[0]+Motion.xs[0])/3; 
			xep_z3=((Motion.xs[3]-Motion.xf[3])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xs[3]+Motion.xf[3])/3;
			zep=Motion.h*(1-cos(sigma))/2;
		
			contorl_1_leg(xep_z2,0,0);
			contorl_2_leg(xep_z1,0,0);
			contorl_3_leg(xep_b, 0,zep);
			contorl_4_leg(xep_z3,0,0);
    
	}

	if (t>Motion.Ts*3/4 && t<Motion.Ts)
	{
//		if((t-Ts*3/4)<=trot_speed)
//		{
//			Delay_ms(1000);
//		}
			sigma=2*MY_PI*(t-Motion.Ts*3/4)/(Motion.faai*Motion.Ts);
			xep_b=(Motion.xf[3]-Motion.xs[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[3];
			xep_z1=((Motion.xs[2]-Motion.xf[2])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[2];
			xep_z2=((Motion.xs[1]-Motion.xf[1])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xf[1]+Motion.xs[1])/3; 
			xep_z3=((Motion.xs[0]-Motion.xf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.xs[0]+Motion.xf[0])/3;
			zep=Motion.h*(1-cos(sigma))/2;
			
			contorl_1_leg(xep_z3,0,0);
			contorl_2_leg(xep_z2,0,0);
			contorl_3_leg(xep_z1,0,0);
			contorl_4_leg(xep_b, 0,zep);
	}
 
}


void trot_XZ(float t)
{
	// Motion.h_12 = 30 - 0.6f*Dog_ROL;
	// Motion.h_34 = 30 + 0.2f*Dog_ROL;

	Motion.h_1 = 20 - 0.5f*Dog_ROL;
	Motion.h_2 = 20 - 0.5f*Dog_ROL;
	Motion.h_3 = 20 + 0.35f*Dog_ROL;
	Motion.h_4 = 20 + 0.35f*Dog_ROL;

	// Motion.h_1 = 20 - (Body.h + pos_leg_XYZ.z[0]);
	// Motion.h_2 = 20 - (Body.h + pos_leg_XYZ.z[1]);
	// Motion.h_3 = 30 - (Body.h + pos_leg_XYZ.z[2]);
	// Motion.h_4 = 30 - (Body.h + pos_leg_XYZ.z[3]);
	// printf("Motion.h_1:%f,Motion.h_2:%f,Motion.h_3:%f,Motion.h_4:%f\n",Motion.h_1,Motion.h_2,Motion.h_3,Motion.h_4);

	if (t<=Motion.Ts*Motion.faai)
	{
		if(ABS(t)==Motion.trot_speed)
		{
			// Sucker1234_on();
			// Delay_ms(100);
			// Sucker24_on();
			// Delay_ms(50);
			Delay_ms(100);
		}
		sigma=2*3.14*t/(Motion.faai*Motion.Ts);
		zep_1=Motion.h_1*(1-cos(sigma))/2;
		zep_2=Motion.h_2*(1-cos(sigma))/2;
		zep_3=Motion.h_3*(1-cos(sigma))/2;
		zep_4=Motion.h_4*(1-cos(sigma))/2;
		xep_b_1=(Motion.xf[0]-Motion.xs[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[0];
		xep_z_1=(Motion.xs[0]-Motion.xf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[0];
		xep_b_2=(Motion.xf[1]-Motion.xs[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[1];
		xep_z_2=(Motion.xs[1]-Motion.xf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[1];
		xep_b_3=(Motion.xf[2]-Motion.xs[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[2];
		xep_z_3=(Motion.xs[2]-Motion.xf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[2];
		xep_b_4=(Motion.xf[3]-Motion.xs[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[3];
		xep_z_4=(Motion.xs[3]-Motion.xf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[3];
		
		yep_b_1=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z_1=(Motion.ys[0]-Motion.yf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_b_2=(Motion.yf[1]-Motion.ys[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[1];
		yep_z_2=(Motion.ys[1]-Motion.yf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[1];
		yep_b_3=(Motion.yf[2]-Motion.ys[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[2];
		yep_z_3=(Motion.ys[2]-Motion.yf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[2];
		yep_b_4=(Motion.yf[3]-Motion.ys[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[3];
		yep_z_4=(Motion.ys[3]-Motion.yf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[3];

		contorl_1_leg(xep_b_1,yep_b_1,zep_1);
		contorl_2_leg(xep_z_2,yep_z_2,-5);
		contorl_3_leg(xep_b_3,yep_b_3,zep_3);
		contorl_4_leg(xep_z_4,yep_z_4,-5);

		
	}
	if (t>Motion.Ts*Motion.faai && t<Motion.Ts)
	{
		if(ABS(t-Motion.Ts*Motion.faai)<=Motion.trot_speed)
		{
			// Sucker1234_on();
			// Delay_ms(100);
			// Sucker13_on();
			// Delay_ms(50);
			Delay_ms(100);
		}
		sigma=2*MY_PI*(t-Motion.Ts*Motion.faai)/(Motion.faai*Motion.Ts);
		zep_1=Motion.h_1*(1-cos(sigma))/2;
		zep_2=Motion.h_2*(1-cos(sigma))/2;
		zep_3=Motion.h_3*(1-cos(sigma))/2;
		zep_4=Motion.h_4*(1-cos(sigma))/2;
		xep_b_1=(Motion.xf[0]-Motion.xs[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[0];
		xep_z_1=(Motion.xs[0]-Motion.xf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[0];
		xep_b_2=(Motion.xf[1]-Motion.xs[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[1];
		xep_z_2=(Motion.xs[1]-Motion.xf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[1];
		xep_b_3=(Motion.xf[2]-Motion.xs[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[2];
		xep_z_3=(Motion.xs[2]-Motion.xf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[2];
		xep_b_4=(Motion.xf[3]-Motion.xs[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xs[3];
		xep_z_4=(Motion.xs[3]-Motion.xf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.xf[3];
		
		yep_b_1=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z_1=(Motion.ys[0]-Motion.yf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_b_2=(Motion.yf[1]-Motion.ys[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[1];
		yep_z_2=(Motion.ys[1]-Motion.yf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[1];
		yep_b_3=(Motion.yf[2]-Motion.ys[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[2];
		yep_z_3=(Motion.ys[2]-Motion.yf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[2];
		yep_b_4=(Motion.yf[3]-Motion.ys[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[3];
		yep_z_4=(Motion.ys[3]-Motion.yf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[3];
		
		contorl_1_leg(xep_z_1,yep_z_1,-3);
		contorl_2_leg(xep_b_2,yep_b_2,zep_2);
		contorl_3_leg(xep_z_3,yep_z_3,-3);
		contorl_4_leg(xep_b_4,yep_b_4,zep_4);

	}
	
//	DT_SendF1(xep_b_1,
//	          xep_b_3,
//						leg_rotation_Angle.alfa [2],leg_rotation_Angle.beta [2],0,0);
//	

}


void walk_YZ(float t)
{	
	if (t<=Motion.Ts*Motion.faai)
	{		
		sigma=2*MY_PI*t/(Motion.faai*Motion.Ts);
		yep_b=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z1=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_z2=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.yf[0]+Motion.ys[0])/3; 
		yep_z3=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.ys[0]+Motion.yf[0])/3;
		zep=Motion.h*(1-cos(sigma))/2;
	
		contorl_1_leg(0,yep_b,zep);
		contorl_2_leg(0,yep_z2,0);
		contorl_3_leg(-20,yep_z3,0);
		contorl_4_leg(-20,yep_z1,0);

	}

	if (t>Motion.Ts*Motion.faai && t<Motion.Ts/2)
	{
		sigma=2*MY_PI*(t-Motion.Ts*Motion.faai)/(Motion.faai*Motion.Ts);
		yep_b=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z1=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_z2=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.yf[0]+Motion.ys[0])/3; 
		yep_z3=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.ys[0]+Motion.yf[0])/3;
		zep=Motion.h*(1-cos(sigma))/2;
	
		contorl_1_leg(0,yep_z1,0);
		contorl_2_leg(0,yep_z3,0);
		contorl_3_leg(-20,yep_b,zep);
		contorl_4_leg(-20,yep_z2,0);

	}

	if (t>Motion.Ts/2 && t<Motion.Ts*3/4)
	{
		sigma=2*MY_PI*(t-Motion.Ts/2)/(Motion.faai*Motion.Ts);
		yep_b=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z1=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_z2=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.yf[0]+Motion.ys[0])/3; 
		yep_z3=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.ys[0]+Motion.yf[0])/3;
		zep=Motion.h*(1-cos(sigma))/2;

		contorl_1_leg(0,yep_z2,0);
		contorl_2_leg(0,yep_b,zep);
		contorl_3_leg(-20,yep_z1,0);
		contorl_4_leg(-20,yep_z3,0);
	
	}

	if (t>Motion.Ts*3/4 && t<Motion.Ts)
	{
		sigma=2*MY_PI*(t-Motion.Ts*3/4)/(Motion.faai*Motion.Ts);
		yep_b=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z1=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_z2=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.yf[0]+Motion.ys[0])/3; 
		yep_z3=((Motion.ys[0]-Motion.yf[0])/3)*((sigma-sin(sigma))/(2*MY_PI))+(2*Motion.ys[0]+Motion.yf[0])/3;
		zep=Motion.h*(1-cos(sigma))/2;
	
		contorl_1_leg(0,yep_z3,0);
		contorl_2_leg(0,yep_z1,0);
		contorl_3_leg(-20,yep_z2,0);
		contorl_4_leg(-20,yep_b,zep);

		
	}
	
}

void trot_YZ(float t)
{
	if (t<=Motion.Ts*Motion.faai)
	{
		sigma=2*MY_PI*t/(Motion.faai*Motion.Ts);
		zep=Motion.h*(1-cos(sigma))/2;
		yep_b_1=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z_1=(Motion.ys[0]-Motion.yf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_b_2=(Motion.yf[1]-Motion.ys[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[1];
		yep_z_2=(Motion.ys[1]-Motion.yf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[1];
		yep_b_3=(Motion.yf[2]-Motion.ys[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[2];
		yep_z_3=(Motion.ys[2]-Motion.yf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[2];
		yep_b_4=(Motion.yf[3]-Motion.ys[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[3];
		yep_z_4=(Motion.ys[3]-Motion.yf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[3];
	
		contorl_1_leg(0,yep_b_1,zep);
		contorl_2_leg(0,yep_z_2,0);
		contorl_3_leg(-20,yep_b_3,zep);
		contorl_4_leg(-20,yep_z_4,0);
		
		
		
	}
	if (t>Motion.Ts*Motion.faai && t<Motion.Ts)
	{
		sigma=2*MY_PI*(t-Motion.Ts*Motion.faai)/(Motion.faai*Motion.Ts);
		zep=Motion.h*(1-cos(sigma))/2;
		yep_b_1=(Motion.yf[0]-Motion.ys[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[0];
		yep_z_1=(Motion.ys[0]-Motion.yf[0])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[0];
		yep_b_2=(Motion.yf[1]-Motion.ys[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[1];
		yep_z_2=(Motion.ys[1]-Motion.yf[1])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[1];
		yep_b_3=(Motion.yf[2]-Motion.ys[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[2];
		yep_z_3=(Motion.ys[2]-Motion.yf[2])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[2];
		yep_b_4=(Motion.yf[3]-Motion.ys[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.ys[3];
		yep_z_4=(Motion.ys[3]-Motion.yf[3])*((sigma-sin(sigma))/(2*MY_PI))+Motion.yf[3];
		
		contorl_1_leg(0,yep_z_1,0);
		contorl_2_leg(0,yep_b_2,zep);
		contorl_3_leg(-40,yep_z_3,0);
		contorl_4_leg(-40,yep_b_4,zep);
	
	}
	
}



void contorl_1_leg(float x,float y,float z)
{
	
	trot_leg_XYZ.z[0]=z;
	trot_leg_XYZ.x[0]=x;	
	trot_leg_XYZ.y[0]=y;

}

void contorl_2_leg(float x,float y,float z)
{
	
	trot_leg_XYZ.z[1]=z;
	trot_leg_XYZ.x[1]=x;	
	trot_leg_XYZ.y[1]=y;

}

void contorl_3_leg(float x,float y,float z)
{
	
	trot_leg_XYZ.z[2]=z;
	trot_leg_XYZ.x[2]=x;	
	trot_leg_XYZ.y[2]=y;

}

void contorl_4_leg(float x,float y,float z)
{
	
	trot_leg_XYZ.z[3]=z;
	trot_leg_XYZ.x[3]=x;	
	trot_leg_XYZ.y[3]=y;

}



//=============   站立   ============
void stand(void)
{
	contorl_1_leg(-30,0,0);
	contorl_2_leg(-30,0,0);
	contorl_3_leg(-40,0,0);
	contorl_4_leg(-40,0,0);
	POS_Adjust(0,0);
	//========   步态融合+逆解   ========
	Get_Position();
		
	//=========   舵机输出   ==========
	servo_output();
}
