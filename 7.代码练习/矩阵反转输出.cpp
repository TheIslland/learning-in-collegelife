/*************************************************************************
	> File Name: 矩阵反转输出.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 31 19:53:46 2019
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
	int matrix[100][100];
	int m;
	int n;
	int flag;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cin >> flag;
	if (flag & 1) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n / 2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - j - 1];
				matrix[i][n - j - 1] = temp;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m / 2; j++) {
				int temp = matrix[j][i];
				matrix[j][i] = matrix[m - j - 1][i];
				matrix[m - j - 1][i] = temp;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << (j < n - 1 ? " " : "");
		}
		cout << endl;
	}
	return 0;
}