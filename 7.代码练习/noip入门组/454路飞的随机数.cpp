/*************************************************************************
	> File Name: 454路飞的随机数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 10:14:30 2019
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
    int n, m;
    int a[1005] = {0};
    int b[1005] = {0};
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> m;
        !b[m] && (b[m] = 1, a[++a[0]] = m);
    }
    sort(a + 1, a + a[0] + 1);
    cout << a[0] << endl;
    for (int i = 1; i <= a[0]; i++) {
        cout << a[i] << (i < a[0] ? " " : "");
    }
    return 0;
}
