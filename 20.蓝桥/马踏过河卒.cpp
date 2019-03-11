/*************************************************************************
	> File Name: 马踏过河卒.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月11日 星期一 20时24分32秒
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
    long long int n, m, f[30][30] = {0};
	int cx, cy; //马的坐标
	int x[8] = {1, 1, 2, 2, -1, -1, -2, -2}; //横向位移
	int y[8] = {2, -2, 1, -1, 2, -2, 1, -1}; //纵向位移
	int d[30][30]; //用来记录是否是马控制点
    cin >> n >> m >> cx >> cy;
	for (int i = 0; i < 30; ++i) { //将 d 数组初始化为 0
    	for (int j = 0;j < 30; ++j) {
        	d[i][j] = 0;
    	}
	}
	d[cx][cy] = 1; // 用 1 来表示该点为马控制点
	for (int i = 0; i < 8; ++i) {
    	int tx = cx + x[i]; //计算马控制点横坐标
    	int ty = cy + y[i]; //计算马控制点纵坐标
    	if (tx >= 0 && tx <= n && ty >= 0 && ty <= n) {
        	d[tx][ty] = 1; //记录为马控制点
    	}
	}
    f[0][0] = 1;
	for (int i = 0;i <= n; ++i) {
    	for (int j = 0; j <= m; ++j) {
        	if (i != 0) {
            	f[i][j] = f[i][j] + f[i-1][j];
        	}
        	if (j != 0) {
            	f[i][j] = f[i][j] + f[i][j-1];
        	}
            if (d[i][j]) f[i][j] = 0;
    	}
	}
    cout << f[n][m] << endl;
// f[n][m]即为点(n,m)的路径数目。
}
