/*************************************************************************
	> File Name: 解方程.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月09日 星期六 18时52分54秒
 ************************************************************************/
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
#define eps 1e-8
double func(double x) {
	return  pow(x, 4) + 5 * pow(x, 3) + 6 * pow(x, 2) + 7 * x + 4;
}
double solve_equation(double y) {
	double l = 0, r = 100;
    if (y < func(l) || y > func(r)) return -1;
    while (r - l > eps) {
		double mid = (l + r) / 2;
        if (func(mid) < y) {
			l = mid;
        } else {
			r = mid;
        }
    }
    return l;
}
int main() {
	double y;
	cin >> y;
	cout << setiosflags(ios::fixed) << setprecision(10) << solve_equation(y) << endl;
}
