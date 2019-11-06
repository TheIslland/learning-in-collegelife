/*************************************************************************
	> File Name: 200数列计算2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 15:57:54 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
int main() {
    double sum = 0;
    int n;
    int a = 4, b = 7;
    cin >> n;
    while (--n) {
        sum += a * 1.0 / b;
        b = a + b;
        a = b - a;
    }
    cout << a << "/" << b << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << (sum += a * 1.0 / b) << endl;
    return 0;
}
