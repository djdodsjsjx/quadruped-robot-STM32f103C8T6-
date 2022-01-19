#ifndef __MY_MATH_H
#define __MY_MATH_H
#include "config.h"

#define MY_PI   3.14159f

#define my_pow(a) ( (a)*(a) )
#define ABS(x) ( (x)>0?(x):-(x) )
#define LIMIT( x,min,max ) ( ((x) <= (min)) ? (min) : ( ((x) > (max))? (max) : (x) ) )
#define DELTA_LIMIT(x,dl,y) (y) += (LIMIT(((x) - (y)),-dl,dl))
#define _MIN(a, b) ((a) < (b) ? (a) : (b))
#define _MAX(a, b) ((a) > (b) ? (a) : (b))

u8 my_len(s16 num);
u32 my_pows(u8 m,u8 n);
float LIMIT_two(float x1,float x2,u8 d);
#endif
