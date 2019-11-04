/*************************************************************************
	> File Name: 163余弦公式.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 14:31:30 2019
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    double a, b, o;
    cin >> a >> b >> o;
    double c = sqrt(a * a + b * b - 2 * a * b * cos(o / 180 * 3.141592653589793));
    printf("%.6lf\n", c);
    return 0;
}
