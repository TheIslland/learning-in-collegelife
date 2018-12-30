/*************************************************************************
	> File Name: 矩形.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月30日 星期日 17时32分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_N 1000
int g[MAX_N + 5][MAX_N + 5] = {0};
int f[MAX_N + 5][MAX_N + 5] = {0};
int dp[MAX_N + 5][MAX_N + 5] = {0};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 0) continue;
            f[i][j] = f[i + 1][j] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int k = j;
            while (f[i][k] >= j && k <= m) ++k;
            dp[i][j] = (k - j) * f[i][j] + dp[i][k];
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
