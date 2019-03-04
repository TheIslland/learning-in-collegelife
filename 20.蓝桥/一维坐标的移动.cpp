/*************************************************************************
	> File Name: 一维坐标的移动.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月04日 星期一 18时36分28秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 5050;

int vis[MAXN];
int ret[MAXN];
int n, a, b;

int bfs() {
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == b) {
            return ret[x];
        }

        for (int i = 0; i < 3; i++) {
            int xx;
            if (i == 0) {
                xx = x + 1;
            } else if (i == 1) {
                xx = x - 1;
            } else {
                xx = x * 2;
            }
            if (xx >= 0 && x <= n && !vis[xx]) {
                ret[xx] = ret[x] + 1;
                vis[xx] = 1;
                q.push(xx);
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> a >> b;
    cout << bfs() << endl;
    return 0;
}
