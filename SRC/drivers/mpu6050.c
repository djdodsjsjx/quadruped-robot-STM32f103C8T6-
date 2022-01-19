#include "mpu6050.h"

uint8_t buffer[14];

void MPU6050_setClockSource(uint8_t source){
    MPU_IICwriteBits(0x68, 0x6B, 2, 3, source);
}

void MPU6050_setFullScaleGyroRange(uint8_t range) {
    MPU_IICwriteBits(0x68, 0x1B, 4, 2, range);
}

void MPU6050_setFullScaleAccelRange(uint8_t range) {
    MPU_IICwriteBits(0x68, 0x1C, 4, 2, range);
}


void MPU6050_resetEnabled(uint8_t enabled) {
    MPU_IICwriteBit(0x68, 0x6B, 7, enabled);
	Delay_ms(100);
}


void MPU6050_set_Gyro_Accel_outRange(uint8_t range) {
    MPU_IICwriteBits(0x68, 0x6C, 5, 6, range);
}

void MPU6050_set_SMPRT_DIV(uint8_t range) {
	  MPU_IICwriteByte(0x68,0x19,range);
}

void MPU6050_set_Gyro_DLPF_outRange(uint8_t range) {
    MPU_IICwriteBits(0x68, 0x1A, 2, 3, range);
}


void MPU6050_INT_Disabled(uint8_t enabled) {
    MPU_IICwriteBit(0x68, 0x38, 0, enabled);
}


void MPU6050_setSleepEnabled(uint8_t enabled) {
    MPU_IICwriteBit(0x68, 0x6B, 6, enabled);
}


void MPU6050_testConnection(void) {
	u8 mpu_test_i;
   while(buffer[0] != 0x68 && mpu_test_i < 10){
			MPU_IICreadBytes(0x68, 0x75, 1, buffer);
		 mpu_test_i++;
	 };
		if(mpu_test_i >= 10) printf("Could not connect to MPU6050 \n\r");
//	 while(1);
}

void MPU6050_setI2CMasterModeEnabled(uint8_t enabled) {
    MPU_IICwriteBit(0x68, 0x6A, 5, enabled);
}

void MPU6050_setI2CBypassEnabled(uint8_t enabled) {
    MPU_IICwriteBit(0x68, 0x37, 1, enabled);
}


void MPU6050_initialize(void) {
		Delay_ms(100);
		MPU_IIC_Init();             //IIC初始化
		MPU6050_testConnection();     //检测MPU6050 是否已经连接
		MPU6050_resetEnabled(1);   //复位mpu6050  需延时100ms
	  MPU6050_setSleepEnabled(0); //进入工作状态
    MPU6050_setClockSource(2); //设置时钟
		MPU6050_set_Gyro_Accel_outRange(0);  // 设置输出三轴陀螺仪和三轴加速度数据
		MPU6050_INT_Disabled(0);    //禁止中断
		MPU6050_set_SMPRT_DIV(0);   //采样分频
    MPU6050_setFullScaleGyroRange(3);//陀螺仪最大量程 +-1000度每秒
    MPU6050_setFullScaleAccelRange(0);	//加速度度最大量程 +-2G
  	MPU6050_set_Gyro_DLPF_outRange(2);  //设置陀螺仪和加速度计的低通滤波器
	  MPU6050_setI2CMasterModeEnabled(0);	 //不让MPU6050 控制AUXI2C
	  MPU6050_setI2CBypassEnabled(1);	 //主控制器的I2C与	MPU6050的AUXI2C	直通。控制器可以直接访问HMC5883L
}

