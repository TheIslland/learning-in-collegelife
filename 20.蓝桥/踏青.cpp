/*************************************************************************
	> File Name: 踏青.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月27日 星期三 21时26分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int n, m;
char node[150][150] = {0};
int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return ;
    if (node[x][y] == '.') return ;
    node[x][y] = '.';
    for (int i = 0; i < 4; i++) {
        int tx = x + xx[i];
        int ty = y + yy[i];
        dfs(tx, ty);
    }
    return ;
}

int main() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> node[i][j]; 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (node[i][j] == '.') continue ;
            ans++;
            dfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
