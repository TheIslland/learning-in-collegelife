/************************************************************
    File Name : 80小明看电影.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-07 星期六 12:58:18
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

struct Node {
    int x, y, sum;
    Node(){};
    Node(int a, int b, int c) {
        x = a;
        y = b;
        sum = c;
    }
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char a[505][505] = {0};
int vis[505][505];
int val = 0, ans = 0, n, m;

void bfs(int start_x, int start_y) {
    queue<Node> q;
    q.push(Node(start_x, start_y, 0));
    vis[start_x][start_y] = 1;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        if (a[temp.x][temp.y] == 'g') {
            val = temp.sum;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int now_x = temp.x + dir[i][0];
            int now_y = temp.y + dir[i][1];
            if (a[now_x][now_y] == '.' && now_x > 0 && now_x <= n &&
                now_y > 0 && now_y <= m && vis[now_x][now_y] == 1) {
                vis[now_x][now_y] = 1;
                q.push(Node(now_x, now_y, temp.sum + 1));
            }
        }
        return;
    }
}
int main() {
    int star_x, star_y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 's') {
                star_x = i;
                star_y = j;
            }
        }
    }
    bfs(star_x, star_y);
    if (val == -1)
        cout << "No";
    else
        cout << val;
    return 0;
}
