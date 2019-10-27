/*************************************************************************
	> File Name: 489偶数个三.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Oct 22 19:15:23 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int a[1005][2] = {0};
int f(int n, int flag) {
    if (a[n][flag] != 0) return a[n][flag];
    if (n == 0) return 0;
    if (n == 1 && flag == 0) return 8;
    if (n == 1 && flag == 1) return 1;
    if (flag == 0) {
        a[n][flag] = (f(n - 1, 1) * 9 % 12345+  f(n - 1, 0) % 12345) % 12345;
    } else {
        a[n][flag] = (f(n - 1, 0) * 9 % 12345 + f(n - 1, 1) % 12345) % 12345;
    }
    return a[n][flag];
}
int main() {
    int n;
    cin >> n;
    cout << f(n, 1) << endl;
    return 0;
}
