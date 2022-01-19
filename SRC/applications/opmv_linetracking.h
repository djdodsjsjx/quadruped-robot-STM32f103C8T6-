#ifndef __OPMV_LINETRACKING_H
#define __OPMV_LINETRACKING_H
#include "config.h"

extern float head_servo_output;
extern float avg_angle,avg_deviation;

void head_servo_task(void);
void LTracking_Ctrl(void);
void average(void);

#endif
