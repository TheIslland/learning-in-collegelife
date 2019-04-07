/*************************************************************************
	> File Name: 蒜头君回家.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月04日 星期一 20时12分55秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>
 
using namespace std;
#define MAX_N 2020
int n, m;
int a[MAX_N];
int note[MAX_N];
int num[MAX_N];
int flag[MAX_N];
int bfs() {
    
}

int main() {
    int x, y
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}
