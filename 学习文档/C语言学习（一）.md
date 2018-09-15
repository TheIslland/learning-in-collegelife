# C语言学习（一）

## 语言入门基础

**(1)输出函的说明**

**函数是一个黑箱子，给予一个输入会返回一个输出，函数完成了一个映射，数组是一个展开的函数。 函数比数组节省了空间，数组被称为纪录式，函数是一种计算式个数**

**（2）深度神经网络是一个计算式，深度神经网络又被称为可微分编程范式**

**(3)printf函数**

​	头文件 ：stdio.h

​	原型：int printf(const char *format, ...);

​	format :格式控制字符串

​	...:可变参数列表

​	返回值：成功读入的参数个数

​	当scanf的返回值为-1时，0相当于返回EOF（EOF的值为—1）

**(4)sprintf函数**

**字符串输出函数sprintf( fout,"%d",n),fout为输出到的数组，%后为输出的格式，n为**

**输出的参数**

## 数学运算

`=`赋值运算符

`+ - × /`基本四则运算

`%`求余运算符

`& | ^ ~`位运算符

`<< >>`只限于整形，左移是乘以2

`% / × +- &`运算速度从慢到快

`%8 = &7 %4=&3` 为什么%6！=&5

**c语言中的数学函数库<math.h>(abs在stdlib.h中)**

**log(n)是以e为底的对数**

log(n)/log2

acos（-1）= 派

如何求一个函数的立方跟pow（n，1/3）

角度值到弧度值x / 180 ×acos（-1）

## 密训

sqrt（）自我实现

二分值

```c
#include <stdio.h>
#define EPS 1e-10
double _sqrt1(double x) {
	double head = -100, tail = 100, mid;
    while (tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x)head = mid;
        else tail = mid;
    }
    return head;
}
int main() {
    double x;
    while (scanf("%lf", &x) != EOF) {
	printf("%lf\n", _sqrt1(x));
    }
    return 0;
}
```

牛顿迭代法

```c
#incldue<stdio.h>
#include<math.h>
#include <time.h>
double f1(double x, double n) {
	return x * x - n;
}
double f1_prime(double x) {
    return 2 * x;
}
double newton(double n, double (*f1)(double, double), double (*f1_prime)(double)) {
	double x = 1.0; //基础值
    #define EPS 1e-7
    while (fabs(f(x) - n) > EPS) {
		x -= f(x,n) / f_prime(x);
    }
    return x;
}
int main() {
 	double x;
    while (scanf("%lf", &x) != EOF) {
	printf("%lf\n", _sqrt1(x));
    printf("%lf\n", newton(x,f1,f1prime));
    }
	return 0;
}
```

牛顿迭代法

x0 = f（）

```c
//宏定义运行时间
#define TEST_TIME(func) ({\
	int begin = clock();\
	double ret = func;\
	int end = clock();\
	printf("%lfms\n", (end - begin) *1.0 / CLOCKS_PER_SEC * 1000);\
})
```

o(1)sqrt雷神之锤

```c
float SqrtByBisection(float n) //用二分法 
{ 
	if(n<0) //小于0的按照你需要的处理 
		return n; 
	float mid,last; 
	float low,up; 
	low=0,up=n; 
	mid=(low+up)/2; 
	do
	{
		if(mid*mid>n)
			up=mid; 
		else 
			low=mid;
		last=mid;
		mid=(up+low)/2; 
	}while(abs(mid-last) > eps);//精度控制
	return mid; 
} 
```































































