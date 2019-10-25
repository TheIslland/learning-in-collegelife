/*************************************************************************
	> File Name: 492回文拆分.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 24 20:16:18 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int a[30] = {0};
int f(int n) {
    if (n == 1) return 1;
    if (n % 2) a[n] = f(n - 1) * 2 + 1;
    else a[n] = f(n - 1);
    return a[n];
}
int main() {
    int k;
    cin >> k;
    cout << f(k) << endl;
    return 0;
}
