/*************************************************************************
	> File Name: 矩阵螺旋输出.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 31 19:56:10 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int main() {
    int a[106][106] = {0};
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int l[4] = {n, m, 0, 0}, dir = 0, i = 0, j = 0, count;
    while (count <= n * m) {
        int count = 0;
        while(count < l[dir]) {
            cout << a[i + x[i]][j + y[i]] << " ";
        }
        if (dir > 1) {
            l[dir]++;
        } else {
            l[dir]--;
        }
        dir = (dir + 1) % 4;
        count++;
    }
    return 0;
}
