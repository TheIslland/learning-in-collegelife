/*************************************************************************
	> File Name: 205队列平均数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 19:04:13 2019
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
    int a[35][35] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        cout << setiosflags(ios::fixed) << setprecision(6) <<  sum * 1.0 / m << endl;
    }
    return 0;
}
