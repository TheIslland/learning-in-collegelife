/*************************************************************************
	> File Name: 矩阵螺旋输出.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 31 19:56:10 2019
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };
int main() {
	int a[106][106] = { 0 };
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int dir, i, j, count, l;
	dir = i = j = count = l = 0;
	while (count < n * m) {
		cout << a[i][j] << (count < n * m - 1 ? " " : "");
		if (x[dir] != 0) {
			if (i + x[dir] <= l || i + x[dir] >= m - l) dir++;
			if (dir == 4) {
				dir = 0;
				l++;
			}
		}
		else {
			if (j + y[dir] < l || j + y[dir] >= n - l) dir++;
		}
		i += x[dir];
		j += y[dir];
		count++;
	}
	return 0;
}