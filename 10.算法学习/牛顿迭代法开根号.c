/*************************************************************************
	> File Name: 牛顿迭代法开根号.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月14日 星期五 16时34分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-10
double f (double x, double n) {
    return x * x - n;
}
double f1 (double x) {
    return 2 * x;
}
double newton (double n, double (*f)(double , double), double (*f1)(double)) {
    double x = 0x5f3759df; //0x5f37642f
    while (fabs(f(x,n)) > EPS) {
        x -= f(x,n) / f1(x);
    }
    return x;
}
int main() {
    double n, ans;
    scanf("%lf", &n);
    ans = newton (n, f, f1);
    printf("%lf\n", ans);
return 0;
}
