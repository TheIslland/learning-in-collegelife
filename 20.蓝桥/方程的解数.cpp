/*************************************************************************
	> File Name: 方程的解数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月01日 星期五 18时02分05秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m, ans = 0;

int k[155], p[155], temp[160][5];

void init() {
    memset(temp, 1, sizeof(temp));
	for (int i = 1; i <= 150; i++) {
		for (int j = 1; j <= 4; j++) {
			temp[i][j] = i * temp[i][j - 1];
        }
    }
}

void dfs(int i, int sum) {
    if (sum == 0 && i == n + 1) {
        ans++;
        return ;
    }
    for (int j = 1; j <= m; j++) {
        if (i < n + 1) dfs(i + 1, sum + k[i] * temp[j][p[i]]);
    }
    return ;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> p[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
