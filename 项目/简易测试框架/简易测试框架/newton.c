/*************************************************************************
	> File Name: newton.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 16时35分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


double newton (double n)
{
    double x = 1.0;//设置初值
    double p = 1e-6;//设置精度
    while(fabs(x * x - n) > p)
    {
        x -= (x * x - n) / (2.0 * x);
    }
    return x;
}
