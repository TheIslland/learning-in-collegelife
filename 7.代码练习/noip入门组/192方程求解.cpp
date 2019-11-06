/*************************************************************************
	> File Name: 192方程求解.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 13:53:18 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;

double func(double x) {
    return x * exp(x);
}

int main() {
    double a;
    cin >> a;
    double l = 0, r = 30, mid = (l + r) / 2.0;
    while(r - l > 1e-6) {
        mid = (l + r) / 2.0;
        if (func(mid) > a) r = mid;
        else l = mid;
    }
    cout << setiosflags(ios::fixed) << setprecision(4) << mid << endl;
    return 0;
}
