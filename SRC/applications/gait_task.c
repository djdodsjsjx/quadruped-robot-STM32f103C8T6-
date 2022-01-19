#include "gait_task.h"

u8 TROT_TIMES;
void Step_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		if(Motion.faai==0.5)
		{
			Motion.xf[0] = 0;  Motion.xs[0] = 0;
			Motion.xf[1] = 0;  Motion.xs[1] = 0;
			Motion.xf[2] = 0;  Motion.xs[2] = 0;
			Motion.xf[3] = 0;  Motion.xs[3] = 0;
			trot_XZ(Motion.t); 
		}
		else if(Motion.faai==0.25)
		{
			Motion.xf[0] = 0;  Motion.xs[0] = 0;
			Motion.xf[1] = 0;  Motion.xs[1] = 0;
			Motion.xf[2] = 0;  Motion.xs[2] = 0;
			Motion.xf[3] = 0;  Motion.xs[3] = 0;
			walk_XZ(Motion.t);
		}
	}
}


void Forward_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		if(Motion.faai==0.5)
		{
			opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
			opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);
			Motion.xf[0] = 10;   Motion.xs[0] = -20;
			Motion.xf[1] = 15;   Motion.xs[1] = -15;
			Motion.xf[2] = -50;  Motion.xs[2] = -80;
			Motion.xf[3] = -35;  Motion.xs[3] = -65;

			//×óÆ«£º+      ÓÒÐ±£º+
			Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
			Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
			Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
			Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
			trot_XZ(Motion.t);  
		}
		else if(Motion.faai==0.25)
		{
			Motion.xf[0] = 0 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[0] = -30 + OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[1] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[1] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[2] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[2] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[3] = -20 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[3] = -50 + OPENMV_Angle_Kp_G*opmv.lt.angle;

			//×óÆ«£º+      ÓÒÐ±£º+
			Motion.yf[0]=OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
			Motion.yf[1]=OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
			Motion.yf[2]=-OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
			Motion.yf[3]=-OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
			walk_XZ(Motion.t);
		}
	}
}

void Shang_Po_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
		opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);
		Motion.xf[0] = 40;   Motion.xs[0] = 10;
		Motion.xf[1] = 45;   Motion.xs[1] = 15;
		Motion.xf[2] = -50;  Motion.xs[2] = -80;
		Motion.xf[3] = -35;  Motion.xs[3] = -65;

		//×óÆ«£º+      ÓÒÐ±£º+
		Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
		Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
		Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
		Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];

		trot_XZ(Motion.t); 
	}
}

void PA_PO_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
		PA_PO_Status_TIMES++;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		if(Motion.faai==0.5)
		{
			opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
			opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);

			Motion.xf[0] = 40 - IMU_POSX_12_Kp_G*Dog_ROL;   Motion.xs[0] = 10 - IMU_POSX_12_Kp_G*Dog_ROL;
			Motion.xf[1] = 20 - IMU_POSX_12_Kp_G*Dog_ROL;   Motion.xs[1] = -10 - IMU_POSX_12_Kp_G*Dog_ROL;
			Motion.xf[2] = -20 - IMU_POSX_34_Kp_G*Dog_ROL;  Motion.xs[2] = -50 - IMU_POSX_34_Kp_G*Dog_ROL;
			Motion.xf[3] = -20 - IMU_POSX_34_Kp_G*Dog_ROL;  Motion.xs[3] = -50 - IMU_POSX_34_Kp_G*Dog_ROL;

			// Motion.xf[0] = 10 - IMU_POSX_12_Kp_G*Dog_ROL;   Motion.xs[0] = -20 - IMU_POSX_12_Kp_G*Dog_ROL;
			// Motion.xf[1] = 10 - IMU_POSX_12_Kp_G*Dog_ROL;   Motion.xs[1] = -20 - IMU_POSX_12_Kp_G*Dog_ROL;
			// Motion.xf[2] = -10 - IMU_POSX_34_Kp_G*Dog_ROL;  Motion.xs[2] = -40 - IMU_POSX_34_Kp_G*Dog_ROL;
			// Motion.xf[3] = -10 - IMU_POSX_34_Kp_G*Dog_ROL;  Motion.xs[3] = -40 - IMU_POSX_34_Kp_G*Dog_ROL;

			//ÈýÆÂ
			// Motion.xf[0] = -15;   Motion.xs[0] = -55;
			// Motion.xf[1] = -15;   Motion.xs[1] = -55;
			// Motion.xf[2] = -35;  Motion.xs[2] = -65;
			// Motion.xf[3] = -35;  Motion.xs[3] = -65;


			//×óÆ«£º+      ÓÒÐ±£º+
			Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
			Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
			Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
			Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
			trot_XZ(Motion.t);  
		}
		else if(Motion.faai==0.25)
		{
			Motion.xf[0] = 0 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[0] = -30 + OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[1] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[1] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[2] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[2] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
			Motion.xf[3] = -20 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[3] = -50 + OPENMV_Angle_Kp_G*opmv.lt.angle;

			//×óÆ«£º+      ÓÒÐ±£º+
			Motion.yf[0]=OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
			Motion.yf[1]=OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
			Motion.yf[2]=-OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
			Motion.yf[3]=-OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
			walk_XZ(Motion.t);
		}
	}
}

void Back_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		TROT_TIMES++;
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		if(Motion.faai==0.5)
		{
			Motion.xf[0] = 10;  Motion.xs[0] = -30;
			Motion.xf[1] = 10;  Motion.xs[1] = -30;
			Motion.xf[2] = 0;  Motion.xs[2] = -40;
			Motion.xf[3] = 0;  Motion.xs[3] = -40;


//					yf_1=0.3*opmv.lt.angle-0.2*opmv.lt.deviation;    ys_1=0; 
//					yf_2=0.3*opmv.lt.angle-0.2*opmv.lt.deviation;    ys_2=0; 
//					yf_3=-0.3*opmv.lt.angle-0.2*opmv.lt.deviation;   ys_3=0; 
//					yf_4=-0.3*opmv.lt.angle-0.2*opmv.lt.deviation;   ys_4=0;
			
			
			Motion.yf[0] = 0;  Motion.ys[0] = 0;
			Motion.yf[1] = 0;  Motion.ys[1] = 0;
			Motion.yf[2] = 0;  Motion.ys[2] = 0;
			Motion.yf[3] = 0;  Motion.ys[3] = 0;
			

			trot_XZ(Motion.t);
		}
		else if(Motion.faai==0.25)
		{
//					Motion.xf[0]=-40;   Motion.xs[0]=0; 
//					Motion.xf[1]=-40;   Motion.xs[1]=0; 
//					Motion.xf[2]=-40;   Motion.xs[2]=0; 
//					Motion.xf[3]=-40;   Motion.xs[3]=0;  	
			walk_XZ(Motion.t);
		}
	}
}

void Turn_Left_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Turn_Left_Status_TIMES++;
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.turn_speed;
		if(Motion.faai==0.5)
		{
			Motion.yf[0] = 10;  Motion.ys[0] = -10;
			Motion.yf[1] = 10;  Motion.ys[1] = -10;
			Motion.yf[2] = -10;  Motion.ys[2] = 10;
			Motion.yf[3] = -10;  Motion.ys[3] = 10;

			trot_YZ(Motion.t);
		}
		else if(Motion.faai==0.25)
		{
			Motion.yf[0] = 15;  Motion.ys[0] = 15;
			Motion.yf[1] = 15;  Motion.ys[1] = 15;
			Motion.yf[2] = 15;  Motion.ys[2] = 15;
			Motion.yf[3] = 15;  Motion.ys[3] = 15;
			
			walk_YZ(Motion.t);
		}
	}
}

void Turn_Right_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Turn_Right_Status_TIMES++;
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.turn_speed;
		if(Motion.faai==0.5)
		{
			Motion.yf[0] = -10;  Motion.ys[0] = 10;
			Motion.yf[1] = -10;  Motion.ys[1] = 10;
			Motion.yf[2] = 10;  Motion.ys[2] = -10;
			Motion.yf[3] = 10;  Motion.ys[3] = -10;
			trot_YZ(Motion.t);
		}
		else if(Motion.faai==0.25)
		{
			Motion.yf[0] = 15;  Motion.ys[0] = 15;
			Motion.yf[1] = 15;  Motion.ys[1] = 15;
			Motion.yf[2] = 15;  Motion.ys[2] = 15;
			Motion.yf[3] = 15;  Motion.ys[3] = 15;
			walk_YZ(Motion.t);
		}
	}
}
	
void Left_Shift_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		TROT_TIMES++;
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.turn_speed;
		if(Motion.faai==0.5)
		{
			Motion.yf[0] = 10;  Motion.ys[0] = -10;
			Motion.yf[1] = 10;  Motion.ys[1] = -10;
			Motion.yf[2] = 10;  Motion.ys[2] = -10;
			Motion.yf[3] = 10;  Motion.ys[3] = -10;

			trot_YZ(Motion.t);
		}
		else if(Motion.faai==0.25)
		{
			Motion.yf[0] = 10;  Motion.ys[0] = 10;
			Motion.yf[1] = 10;  Motion.ys[1] = 10;
			Motion.yf[2] = 10;  Motion.ys[2] = 10;
			Motion.yf[3] = 10;  Motion.ys[3] = 10;
			walk_YZ(Motion.t);
		}
	}
}

void Right_Shift_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		TROT_TIMES++;
		Motion.t=0;
	}
	else
	{
		Motion.t=Motion.t+Motion.turn_speed;
		if(Motion.faai==0.5)
		{
			Motion.yf[0] = -10;  Motion.ys[0] = 10;
			Motion.yf[1] = -10;  Motion.ys[1] = 10;
			Motion.yf[2] = -10;  Motion.ys[2] = 10;
			Motion.yf[3] = -10;  Motion.ys[3] = 10;
			

			trot_YZ(Motion.t);  
		}
		else if(Motion.faai==0.25)
		{
			Motion.yf[0] = 10;  Motion.ys[0] = 10;
			Motion.yf[1] = 10;  Motion.ys[1] = 10;
			Motion.yf[2] = 10;  Motion.ys[2] = 10;
			Motion.yf[3] = 10;  Motion.ys[3] = 10;
			walk_YZ(Motion.t);
		}
	}
}

void Dog_Start(void)
{
	stand();
	PA_PO_FLAG = 1;
	Delay_ms(1000);
}



void Po_1_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
		TROT_TIMES++;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
		opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);
		Motion.xf[0] = 0 - OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[0] = -30 + OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[1] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[1] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[2] = -25 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[2] = -55 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[3] = -25 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[3] = -55 + OPENMV_Angle_Kp_G*opmv.lt.angle;

		//×óÆ«£º+      ÓÒÐ±£º+
		Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
		Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
		Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
		Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];

		trot_XZ(Motion.t); 
	}
}


void Po_2_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
		TROT_TIMES++;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
		opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);
		Motion.xf[0] = 0 - OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[0] = -30 + OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[1] = -10 + OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[1] = -40 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[2] = -45 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[2] = -75 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[3] = -35 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[3] = -65 + OPENMV_Angle_Kp_G*opmv.lt.angle;

		//×óÆ«£º+      ÓÒÐ±£º+
		Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
		Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
		Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
		Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
		trot_XZ(Motion.t); 
	}
}

void Po_3_Task(void)
{
	if (Motion.t>=Motion.Ts)
	{
		Motion.t=0;
		TROT_TIMES++;
	}
	else
	{
		Motion.t=Motion.t+Motion.trot_speed;
		opmv.lt.angle = LIMIT(opmv.lt.angle,-30,30);
		opmv.lt.deviation = LIMIT(opmv.lt.deviation,-50,50);
		Motion.xf[0] = 0 - OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[0] = -30 + OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[1] = 0 + OPENMV_Angle_Kp_G*opmv.lt.angle;   Motion.xs[1] = -30 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[2] = -25 + OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[2] = -55 - OPENMV_Angle_Kp_G*opmv.lt.angle;
		Motion.xf[3] = -25 - OPENMV_Angle_Kp_G*opmv.lt.angle;  Motion.xs[3] = -55 + OPENMV_Angle_Kp_G*opmv.lt.angle;

		//×óÆ«£º+      ÓÒÐ±£º+
		Motion.yf[0] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[0]=-Motion.yf[0]; 
		Motion.yf[1] = OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;     Motion.ys[1]=-Motion.yf[1]; 
		Motion.yf[2] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[2]=-Motion.yf[2]; 
		Motion.yf[3] = -OPENMV_Angle_Kp_G*opmv.lt.angle-OPENMV_Deviation_Kp_G*opmv.lt.deviation;    Motion.ys[3]=-Motion.yf[3];
		trot_XZ(Motion.t); 
	}
}
