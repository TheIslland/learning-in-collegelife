/*************************************************************************
	> File Name: 467求阶乘.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 02:06:02 2019
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
ll a[30] = {0};
void init() {
    a[1] = 1;
    for (int i = 2; i <= 20; i++) {
        a[i] = a[i - 1] * i;
    }
}
int main() {
    int n;
    init();
    cin >> n;
    cout << a[n] << endl;
    return 0;
}
