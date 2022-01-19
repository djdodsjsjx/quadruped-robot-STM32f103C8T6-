#ifndef __POSTURE_CONTROL_H
#define __POSTURE_CONTROL_H
#include "config.h"

extern float PIT_S,ROL_S,POS_X_S,POS_Z_S;
extern s16 Cal_Ges_ROL,Cal_Ges_PIT;
void POS_STAB(void);
void POS_Adjust(float ROL_goal,float PIT_goal);
void cal_ges(float ROL,float PIT,float YAW,float POS_X,float POS_Y,float POS_Z);


	
#endif
