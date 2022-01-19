#ifndef __DT_H
#define __DT_H
#include "config.h"


	

#define BYTE0(dwTemp)     (*(char*)(&dwTemp))
#define BYTE1(dwTemp)     (*((char*)(&dwTemp)+1))
#define BYTE2(dwTemp)     (*((char*)(&dwTemp)+2))
#define BYTE3(dwTemp)     (*((char*)(&dwTemp)+3))
	
void DT_SendF1(s16 a_1, s16 a_2,s16 a_3,s16 a_4,s16 a_5,s16 a_6);
void DT_Send01(s16 acc_x, s16 acc_y,s16 acc_z,s16 gyrox,s16 gyroy,s16 gyroz, u8 sta);
void DT_Send03(s16 rol, s16 pit,s16 yaw, u8 sta);
#endif


