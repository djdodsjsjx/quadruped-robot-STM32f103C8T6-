#ifndef __GAIT_H
#define __GAIT_H

#include "config.h"

extern float sigma,zep,xep_b,xep_z,xep_z1,xep_z2,xep_z3,yep_b,yep_z,yep_z1,yep_z2,yep_z3,
							xep_b_1,xep_b_2,xep_z_1,xep_z_2,xep_b_3,xep_b_4,xep_z_3,xep_z_4,
							yep_b_1,yep_b_2,yep_z_1,yep_z_2,yep_b_3,yep_b_4,yep_z_3,yep_z_4;

void contorl_1_leg(float x,float y,float z);
void contorl_2_leg(float x,float y,float z);
void contorl_3_leg(float x,float y,float z);
void contorl_4_leg(float x,float y,float z);
void walk_XZ(float t);
void trot_XZ(float t);
void walk_YZ(float t);
void trot_YZ(float t);
void stand(void);


#endif
