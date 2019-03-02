/*************************************************************************
	> File Name: 八皇后.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月02日 星期六 17时28分22秒
 ************************************************************************/

#include <iostream>

using namespace std;

int num[8][8];
int l[20] = {0};
int x[20] = {0};
int y[20] = {0};
int ans = 0;
void dfs(int deep, int sum) {
    if (deep >= 8) {
        if (sum > ans) ans = sum;
        return ;
    }
    for (int i = 0; i < 8; i++) {
        if (x[deep + i] == 0 && y[i - deep + 8] == 0 && l[i] == 0) {
            x[deep + i] = y[i - deep + 8] = l[i] = 1;
            dfs(deep + 1, sum + num[deep][i]);
            x[deep + i] = y[i - deep + 8] = l[i] = 0;
        }
    }
}


int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> num[i][j];
        }
    }
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
