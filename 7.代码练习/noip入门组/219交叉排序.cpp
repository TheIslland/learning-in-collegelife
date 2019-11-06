/*************************************************************************
	> File Name: 219交叉排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 23:05:26 2019
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
bool cmp1(int a, int b) {
    return a < b;
}
bool cmp2(int a, int b) {
    return a > b;
}
int main() {
    int n, l1, r1, l2, r2;
    int a[10005] = {0};
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a + l1 - 1, a + r1, cmp1);
    sort(a + l2 - 1, a + r2, cmp2);
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n - 1 ? " " : "");
    }
    return 0;
}
