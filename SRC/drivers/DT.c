#include "DT.h"


u8 DataToSend[100];
//×Ô¶¨ÒåÖ¡
void DT_SendF1(s16 a_1, s16 a_2,s16 a_3,s16 a_4,s16 a_5,s16 a_6)
{
	u8 _cnt = 0;
	
	DataToSend[_cnt++] = 0XAA;
	DataToSend[_cnt++] = 0XFF;
	DataToSend[_cnt++] = 0XF1;
	DataToSend[_cnt++] = 0;
	
	DataToSend[_cnt++] = BYTE0(a_1);
	DataToSend[_cnt++] = BYTE1(a_1);
	
	DataToSend[_cnt++] = BYTE0(a_2);
	DataToSend[_cnt++] = BYTE1(a_2);
	
	DataToSend[_cnt++] = BYTE0(a_3);
	DataToSend[_cnt++] = BYTE1(a_3);
	
	DataToSend[_cnt++] = BYTE0(a_4);
	DataToSend[_cnt++] = BYTE1(a_4);
	
	DataToSend[_cnt++] = BYTE0(a_5);
	DataToSend[_cnt++] = BYTE1(a_5);
	
	DataToSend[_cnt++] = BYTE0(a_6);
	DataToSend[_cnt++] = BYTE1(a_6);

	DataToSend[3] = _cnt-4;
	
	u8 sc = 0;
	u8 ac = 0;
	for(u8 i=0; i<DataToSend[3]+4; i++)
	{
		sc += DataToSend[i];
		ac += sc;
	}
	
	DataToSend[_cnt++] = sc;
	DataToSend[_cnt++] = ac;

	Uart1_Put_Buf(DataToSend,_cnt);
}

//mpu6050

void DT_Send01(s16 acc_x, s16 acc_y,s16 acc_z,s16 gyrox,s16 gyroy,s16 gyroz, u8 sta)
{
	u8 _cnt = 0;
	
	DataToSend[_cnt++] = 0XAA;
	DataToSend[_cnt++] = 0XFF;
	DataToSend[_cnt++] = 0X01;
	DataToSend[_cnt++] = 0;
	
	DataToSend[_cnt++] = BYTE0(acc_x);
	DataToSend[_cnt++] = BYTE1(acc_x);
	
	DataToSend[_cnt++] = BYTE0(acc_y);
	DataToSend[_cnt++] = BYTE1(acc_y);
	
	DataToSend[_cnt++] = BYTE0(acc_z);
	DataToSend[_cnt++] = BYTE1(acc_z);
	
	DataToSend[_cnt++] = BYTE0(gyrox);
	DataToSend[_cnt++] = BYTE1(gyrox);
	
	DataToSend[_cnt++] = BYTE0(gyroy);
	DataToSend[_cnt++] = BYTE1(gyroy);
	
	DataToSend[_cnt++] = BYTE0(gyroz);
	DataToSend[_cnt++] = BYTE1(gyroz);
	
	DataToSend[_cnt++] = sta;

	DataToSend[3] = _cnt-4;
	
	u8 sc = 0;
	u8 ac = 0;
	for(u8 i=0; i<DataToSend[3]+4; i++)
	{
		sc += DataToSend[i];
		ac += sc;
	}
	
	DataToSend[_cnt++] = sc;
	DataToSend[_cnt++] = ac;

	Uart1_Put_Buf(DataToSend,_cnt);
}


void DT_Send03(s16 rol, s16 pit,s16 yaw, u8 sta)
{
	rol=rol*100;
	pit=pit*100;
	yaw=yaw*100;
	u8 _cnt = 0;
	
	DataToSend[_cnt++] = 0XAA;
	DataToSend[_cnt++] = 0XFF;
	DataToSend[_cnt++] = 0X03;
	DataToSend[_cnt++] = 0;
	
	DataToSend[_cnt++] = BYTE0(rol);
	DataToSend[_cnt++] = BYTE1(rol);
	
	DataToSend[_cnt++] = BYTE0(pit);
	DataToSend[_cnt++] = BYTE1(pit);
	
	DataToSend[_cnt++] = BYTE0(yaw);
	DataToSend[_cnt++] = BYTE1(yaw);
	
	DataToSend[_cnt++] = sta;

	DataToSend[3] = _cnt-4;
	
	u8 sc = 0;
	u8 ac = 0;
	for(u8 i=0; i<DataToSend[3]+4; i++)
	{
		sc += DataToSend[i];
		ac += sc;
	}
	
	DataToSend[_cnt++] = sc;
	DataToSend[_cnt++] = ac;

	Uart1_Put_Buf(DataToSend,_cnt);
}
