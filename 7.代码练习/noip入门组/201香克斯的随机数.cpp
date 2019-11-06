/*************************************************************************
	> File Name: 201香克斯的随机数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 16:05:12 2019
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
    int a[1005] = {0};
    int b[105] = {0};
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        !a[m] && (b[++b[0]] = m, a[m] = 1);
    }
    sort(b + 1, b + b[0] + 1);
    cout << b[0] << endl;
    for (int i = 1; i <= b[0]; i++) {
        cout << b[i] << (i < b[0] ? " " : "");
    }
    return 0;
}
