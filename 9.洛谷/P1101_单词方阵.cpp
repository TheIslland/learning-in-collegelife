/*************************************************************************
	> File Name: P1101_单词方阵.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月07日 星期四 20时04分46秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct Node {
    int x, y;
}c[11];
int n, sx, sy;
char a[102][102];
char note[102][102];
char sta[8] = "yizhong";
int xx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int yy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            note[i][j] = '*';
        }
    }
}

void dfs(int x, int y, int ind) {
    if (ind == 6) {
        for (int i = 0; i < 7; i++) {
            note[c[i].x][c[i].y] = sta[i]; 
        } 
        return ;
    }
    for (int i = 0; i < 8; i++) {
        int tx = x + xx[i];
        int ty = y + yy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < n && sta[ind + 1] == a[tx][ty]) {
            c[ind].x = x;
            c[ind].y = y;
            dfs(tx, ty, ind + 1);
        }
    }    
    return ;
}

int main() {
    cin >> n; 
    init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'y') {
                dfs(i, j, 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << note[i][j]; 
        }
        cout << endl;
    }
    return 0;
}
