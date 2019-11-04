/*************************************************************************
	> File Name: 150矩阵旋转.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 22:16:53 2019
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int matrix[205][205] = {0};
	int ans[205][205] = {0};
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[j][n - i - 1] = matrix[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << (j < n - 1 ? " " : "");
		}
		cout << endl;
	}
	return 0;
}
