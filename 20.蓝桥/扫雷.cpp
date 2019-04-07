/*************************************************************************
	> File Name: 扫雷.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 10时41分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char str[n + 2][m + 2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> str[i][j];
        }
    }
    int num[1000][1000] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str[i][j] == '*') {
                num[i][j] = 9;
                num[i + 1][j]++;
                num[i + 1][j + 1]++;
                num[i - 1][j]++;
                num[i - 1][j - 1]++;
                num[i + 1][j - 1]++;
                num[i - 1][j + 1]++;
                num[i][j + 1]++;
                num[i][j - 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (num[i][j] >= 9) {
                cout << '*';
                continue ;
            }
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}
