/*************************************************************************
	> File Name: half_sqrt.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月07日 星期日 16时50分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-6

double half_sqrt(double n) {
    double max,min,mid;
    max=1000;
    min=-1000;
    while(max - min > EPS)
    {
        mid=(min+max)/2;
        if(mid*mid>n) max=mid;
        else min=mid;
    }
    return min;
} 
