/*************************************************************************
	> File Name: 最大子矩阵.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 11时37分13秒
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int n, m, ans = -999999999;
    cin >> n >> m;
    int a[51][51] = {0};
    int dp[51][51] = {0};
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
        	if (dp[i][j] >= ans) ans = dp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int p = 1; p <= i; p++) {
                for (int q = 1; q <= j; q++) {
					int temp = dp[i][j] - dp[p - 1][j] - dp[i][q - 1] + dp[p - 1][q - 1];
                    if (temp >= ans) ans = temp;
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}
