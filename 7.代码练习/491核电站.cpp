/*************************************************************************
	> File Name: 491核电站.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 24 20:55:48 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
long long int a[55] = {0};
int m;
long long int f(int n) {
    if(n == 0) return 1;
    if(a[n] != 0) return a[n];
    if (n < m) a[n] = f(n - 1) * 2;
    else if (n == m) a[n] = f(n - 1) * 2 + 1;
    else a[n] = f(n - 1) * 2 - f(n - m - 1);
    return a[n];
}
int main() {
    int n;
    cin >> n >> m;
    cout << f(n) << endl;
    return 0;
}
