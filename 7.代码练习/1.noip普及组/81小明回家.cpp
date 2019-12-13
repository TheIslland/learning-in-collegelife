/************************************************************
    File Name : 81小明回家.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-10 星期二 18:14:54
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

#define MAX_N 2000
int n, m, start_x, start_y;
char a[MAX_N + 5][MAX_N + 5];
int note[MAX_N + 5][MAX_N + 5];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Node {
    int x, y, sum;
    Node(){};
    Node(int now_x, int now_y, int now_sum) {
        x = now_x;
        y = now_y;
        sum = now_sum;
    }
    Node(const Node& b) {
        this->x = b.x;
        this->y = b.y;
        this->sum = b.sum;
    }
};

int bfs(int x, int y, char judg) {
    queue<Node> q;
    q.push(Node(x, y, 0));
    note[x][y] = 1;
    while (!q.empty()) {
        Node temp = q.front();
        // cout << temp.x << " " << temp.y << endl;
        if (a[temp.x][temp.y] == judg) {
            return temp.sum;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int now_x = temp.x + dir[i][0], now_y = temp.y + dir[i][1];
            // cout << now_x << " " << now_y << endl;
            if (now_x > 0 && now_x <= n && now_y > 0 && now_y <= m &&
                a[now_x][now_y] != '#' && !note[now_x][now_y]) {
                q.push(Node(now_x, now_y, temp.sum + 1));
                note[now_x][now_y] = 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<Node> p;
    int ans = __INT_MAX__, sum = 0, start_xx, start_yy, end_x, end_y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'P') {
                p.push_back(Node(i, j, 0));
                continue;
            }
        }
        getchar();
    }
    for (int i = 0; i < p.size(); i++) {
        start_x = p[i].x;
        start_y = p[i].y;
        sum = bfs(start_x, start_y, 'S');
        memset(note, 0, sizeof(note));
        sum += bfs(start_x, start_y, 'T');
        memset(note, 0, sizeof(note));
        ans > sum && (ans = sum);
    }
    cout << ans << endl;
    return 0;
}
