#ifndef __GAIT_TASK_H
#define __GAIT_TASK_H

#include "config.h"


extern u8 TROT_TIMES;

void Step_Task(void);       //踏步
void Forward_Task(void);   //前进
void Back_Task(void);       //后退
void Turn_Left_Task(void);  //左转
void Turn_Right_Task(void); //右转
void Left_Shift_Task(void); //左移
void Right_Shift_Task(void);//右移
void Dog_Start(void);  //起步
void PA_PO_Task(void);
void Po_1_Task(void);
void Po_2_Task(void);
void Po_3_Task(void);
void Shang_Po_Task(void);
	
#endif
