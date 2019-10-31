#include <cstdio>
#include <cstdlib>
#include <cmath>

double IterationFunction(double x)    //迭代函数
{
	return pow(x + 1.0, 1.0 / 3);
}

double function(double x)    //原函数 f(x)
{
	return x * x*x - x - 1;
}

double derivativeFunction(double x)    //导函数 f'(x)
{
	return 3 * x*x - 1;
}

double Iteration(double x0, double e, int N)    //一般迭代算法
//输入参数： x0 初值， e 精度， N 最大迭代次数
{
	int k = 0;    //当前迭代次数
	double x1;    //终值
    printf("--------------------------一般迭代算法过程----------------------------\n");
	printf("k = %d:    x%d = %lf\n", k, k, x0);
	while (k < N)
	{
		x1 = IterationFunction(x0);
		k++;
		printf("k = %d:    x%d = %lf\n", k, k, x1);
		if (fabs(x1 - x0) < e)    //判断是否达到精度,满足要求结束程序，否则继续迭代
			return x1;
		x0 = x1;
	}
	return 0;    //迭代失败：迭代次数超过最大迭代次数，精度未达到要求
}

double AitkenAccelerate(double x0, double e, int N)    //Aitken加速算法
//输入参数： x0 初值， e 精度， N 最大迭代次数、
{
	int k = 0;
	double x1, x2, x3;
	printf("--------------------------Aitken加速算法过程----------------------------\n");
	printf("k = %d:   x%d=%lf\n", k, k, x0);
	while (k < N)
	{
		x1 = IterationFunction(x0);    //迭代
		x2 = IterationFunction(x1);    //迭代
		x3 = x2 - (x2 - x1)*(x2 - x1) / (x2 - 2 * x1 + x0);    //改进
		k++;
		printf("k = %d:   x%d(-)=%lf,   x%d(~)=%lf,   x%d=%lf\n", k, k, x1, k, x2, k, x3);
		if (fabs(x3 - x0) < e)
			return x3;
		x0 = x3;
	}
	return 0;
}

double Newton(double x0, double e, int N)    //Newton算法
{
	int k = 0;
	double x1;
	printf("---------------------------Newton算法过程---------------------------\n");
	printf("k = %d:    x%d = %lf\n", k, k, x0);
	while (k < N)
	{
		if (0 == derivativeFunction(x0))    //分母不可为0
			return -1.999999;     //导函数值为0，返回-1.999999作为错误标志
		x1 = x0 - function(x0) / derivativeFunction(x0);     //使用Newton迭代函数
		k++;
		printf("k = %d:    x%d = %lf\n", k, k, x1);
		if (fabs(x1 - x0) < e)
			return x1;
		x0 = x1;
	}
	return 0;
}


double NewtonDown(double x0, double e, int N)    //Newton下山算法
{
	int k = 0;
	double x1;
	double down = 1.0;    //下山因子
	printf("---------------------------Newton下山算法过程---------------------------\n");
	printf("k = %d:    x%d = %lf\n", k, k, x0);
	while (k < N)
	{
		if (0 == derivativeFunction(x0))    //分母不可为0
			return -1.999999;     //导函数值为0，返回-1.999999作为错误标志
		down = 1.0;
		x1 = x0 - down * function(x0) / derivativeFunction(x0);     //使用Newton迭代函数
		while (fabs(function(x1)) >= fabs(function(x0)))
		{
			down /= 2;    //下山因子减半
			x1 = x0 - down * function(x0) / derivativeFunction(x0);
		}
		k++;
		if (down <= 0.0000001)
		{
			printf("下山失败，没有找到合适的下山因子，请另选初值\n");
			return 0;
		}
		printf("k = %d:    x%d = %lf, 下山因子 = %lf\n", k, k, x1, down);
		if (fabs(x1 - x0) < e)
			return x1;
		x0 = x1;
	}
	return 0;
}

int main()
{
	double answer;
	answer = Iteration(0.6, 0.000001, 20);
	//在此将迭代次数设置尽可能大，不考虑迭代失败的情况
    printf("一般迭代算法求得最终结果： x = %lf\n\n", answer);
	answer = AitkenAccelerate(1.5, 0.000001, 10);
	printf("Aitken加速算法求得最终结果： x = %lf\n\n", answer);
	answer = Newton(0.6, 0.000001, 20);
	printf("Newton算法求得最终结果： x = %lf\n\n", answer);
	answer = NewtonDown(0.6, 0.000001, 20);
	printf("Newton算法求得最终结果： x = %lf\n\n", answer);
	return 0;
}
