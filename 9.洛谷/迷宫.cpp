/*************************************************************************
	> File Name: 迷宫.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月06日 星期三 20时05分40秒
 ************************************************************************/

#include <iostream>

using namespace std;

int n, m, t, ex, ey, ans = 0;
int a[10][10] = {0};
int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

void dfs(int i, int j) {
    if (i == ex && j == ey) {
        ans++;
        return ;
    }
    a[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int tx = i + xx[k];
        int ty = j + yy[k];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m && a[tx][ty] == 0) {
            dfs(tx, ty);
        }
    }
    a[i][j] = 0;
}

int main() {
    int x, y, t1, t2;
    cin >> n >> m >> t;
    cin >> x >> y >> ex >> ey;
    for (int i = 0; i < t; i++) {
        cin >> t1 >> t2;
        a[t1][t2] = 1;
    }
    dfs(x, y);
    cout << ans << endl;
    return 0;
}
