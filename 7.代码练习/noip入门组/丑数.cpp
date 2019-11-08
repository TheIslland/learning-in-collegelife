/*************************************************************************
	> File Name: 丑数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 14:21:00 2019
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
    int n;
    int a[16005] = {0};
    a[1] = 1;
    for (int i = 1; i < 501; i++) {
        a[i * 2] = 1;
        a[i * 3] = 1;
        a[i * 5] = 1;
        a[i * 6] = 1;
        a[i * 10] = 1;
        a[i * 15] = 1;
        a[i * 30] = 1;
    }
    for (int i = 1; i <= 15; i++) {
        if (a[i]) cout << i << endl;
    }
    return 0;
}
