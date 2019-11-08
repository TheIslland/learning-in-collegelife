/*************************************************************************
	> File Name: 66数字生成序列.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 11:55:48 2019
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
int a[5000007] = {0};
int f(int n) {
    if (a[n] != 0) return a[n];
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 4) return 3;
    a[n] = (n & 1 ? f(3 * n + 1) : f(n / 2)) + 1;
    return a[n];
}
int main() {
    int n, max = -1;
    for (int i = 1; i <= 1000000; i++) {
        if(f(i) > max) {
            max = f(i);
            n = i;
        }
    }
    cout << n << endl;
    return 0;
}

