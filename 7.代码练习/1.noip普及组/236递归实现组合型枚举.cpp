/************************************************************
    File Name : 236递归实现组合型枚举.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-03 星期二 19:52:13
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
int n, m;
void make_num(int *ans, int i) {
    if (i > n + 1) return;
    if (ans[0] >= m) {
        for (int i = 1; i <= ans[0]; i++) {
            cout << ans[i] << (i < ans[0] ? " " : "\n");
        }
        return;
    }
    for (int j = i; j <= n; j++) {
        ans[++ans[0]] = j;
        make_num(ans, j + 1);
        ans[0]--;
    }
    return;
}
int main() {
    int ans[11] = {0};
    cin >> n >> m;
    make_num(ans, 1);
    return 0;
}