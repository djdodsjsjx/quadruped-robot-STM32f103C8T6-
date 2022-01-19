#ifndef __FILTER_H
#define __FILTER_H

#include "config.h"
#define PI 3.14159265

extern s16 Dog_ROL,Dog_PIT;
float Kalman_Filter(float Accel,float Gyro);	
void Filter_Get_Angle(void);

#endif
