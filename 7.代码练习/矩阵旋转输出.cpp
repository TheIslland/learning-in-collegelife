/*************************************************************************
	> File Name: 矩阵旋转输出.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 31 19:55:23 2019
 ************************************************************************/

#include <iostream>
using namespace std;
int main() {
	int matrix[3][3];
	int ans[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ans[j][2 - i] = matrix[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ans[i][j] << (j < 2 ? " " : "");
		}
		cout << endl;
	}
	return 0;
}
