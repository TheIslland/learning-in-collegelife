/*************************************************************************
	> File Name: 535瓷砖.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 22:46:03 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
char str[55][55] = {0};
int ans = 1, h, w;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int i, int j) {
    if (i < 0 || i >= w || j < 0 || j >= h) return ;
    if (str[i][j] == '#' || str[i][j] == 0) return ;
    if (str[i][j] == '.') ans++;
    for (int k = 0; k < 4; k++) {
        str[i][j] = '#';
        dfs(i + dir[k][0], j + dir[k][1]);
    }
}

int main() {
    cin >> h >> w;
    int x, y;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> str[i][j];
            if (str[i][j] == '@') {
                x = i;
                y = j;
            }

        }
    }
    dfs(x, y);
    cout << ans << endl;
    return 0;
}
