/*************************************************************************
	> File Name: 走迷宫.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月27日 星期三 20时56分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int xx[4] = {1, 0, -1, 0};
int yy[4] = {0, 1, 0, -1};

char node[20][20] = {0};

int ans = 0, n, m;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return ;
    if (node[x][y] == '#' || node[x][y] == '1') return ;
    if (node[x][y] == 'T') {
        ans++;
        return ;
    }
    node[x][y] = '1';
    for (int i = 0; i < 4; i++) {
        int tx = x + xx[i];
        int ty = y + yy[i];
        dfs(tx,ty);
    }
    node[x][y] = '.';
    return ;
}

int main() {
    int a, b;
    cin >> n >> m;
    char tmep;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> node[i][j];
            if (node[i][j] == 'S') {
                a = i, b = j;
            }
        }
    }
    dfs(a, b);
    cout << ans << endl;
    return 0;
}
