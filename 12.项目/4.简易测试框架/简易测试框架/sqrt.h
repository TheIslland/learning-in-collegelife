/*************************************************************************
	> File Name: sqrt.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 18时16分20秒
 ************************************************************************/

#ifndef _SQRT_H
#define _SQRT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double newton_sqrt (double n)
{
    double x = 1.0;//设置初值
    double p = 1e-6;//设置精度
    while(fabs(x*x - n) > p)
    {
        x -= (x * x - n) / (2.0 * x);
    }
    return x;
}
#endif
