/*************************************************************************
	> File Name: 199递推函数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 20:30:08 2019
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
ll num[100006] = {0};
int a[10] = {0};
ll f(int x, int m) {
    if (num[x] != 0) return num[x];
    if (x < 10) return x; 
    for (int i = 0; i < 10; i++) {
        if (a[i] == 0) continue;
        num[x] += (a[i] * f(x - i - 1, m)) % m;  
    }
    return num[x] % m;
}
int main() {
    int k, m;
    cin >> k >> m;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    cout << f(k, m) << endl;
    return 0;
}
