/*************************************************************************
	> File Name: 206队列列求和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 19:11:56 2019
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
    double a[36][36] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[35][j] += a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << a[35][i] << endl;
    }
    return 0;
}
