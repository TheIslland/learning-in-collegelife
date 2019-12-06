#include<cstdio>
#include<cstdlib>
#include<cmath>
// f（x） =  2x^3 -4x^2 +3x - 6 = 0 在1.5处的根
// f'(x) =  6x^2 - 8x + 3
double fun(double x)
{
	x = 2 * x*x*x - 4 * x*x + 3 * x - 6;
	return x;
}
double fun1(double x)
{
	x = 6 * x*x - 8 * x + 3;
	return x;
}
double root(double(*f)(double), double(*f1)(double),double x, double eps)
{
	double x0;
	while (1)
	{
		x0 = x;
		x = x0 - (*f)(x) / (*f1)(x);
		if (fabs((*f)(x)) < eps && fabs(x - x0) < eps)
		{
			break;
		}
	}
	return x;
}
int main()
{
	double x, eps;
	x = 1.5;
	scanf("%lf", &eps);
	x = root(fun,fun1,x, eps);
	printf("%lf", x);
	return 0;
}