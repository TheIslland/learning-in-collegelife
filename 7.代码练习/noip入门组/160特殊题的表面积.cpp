/*************************************************************************
	> File Name: 160特殊题的表面积.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 13:21:55 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define PI 3.14
using namespace std;
int main() {
    double r, h;
    double ans = 0;
    cin >> r >> h;
    cout << setiosflags(ios::fixed) << setprecision(2) << PI * r * r + 4 * r * r + (PI * r + 2 * r + 2 * sqrt(2) * r) * h << endl;
    return 0;
}
