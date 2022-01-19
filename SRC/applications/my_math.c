#include "my_math.h"

u8 my_len(s16 num)
{
	u8 len=0;
	if(num<0)num=-num;
	while(num)
	{
		len++;
		num/=10;
	}
	return len;
}

//m^n
u32 my_pows(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}	

float LIMIT_two(float x1,float x2,u8 d)
{
	if(x1 - x2 > d){
		x1 = x2 + d;
	}else if(x1 - x2 < -d){
		x1 = x2 - d;
	}
	return x1;
}
