#ifndef __SERVO_H
#define __SERVO_H
#include "config.h"

// #define SERVO_TIM_ARR  19999
// #define SERVO_TIM_PSC  71

#define SERVO_TIM_ARR  19999
#define SERVO_TIM_PSC  71

#define MOTOR_TIM_ARR  2499
#define MOTOR_TIM_PSC  71

void pwm_servo_init(void);
void position(u8 ID ,u16 degrees);

#endif
