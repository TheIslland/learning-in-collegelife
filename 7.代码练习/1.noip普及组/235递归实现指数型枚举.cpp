/************************************************************
    File Name : 235递归实现指数型枚举.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-03 星期二 18:38:13
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
int a[15], n;
void make_num(int i, int *ans) {
    if (i > n + 1) return;
    for (int j = 1; j <= ans[0]; j++) {
        cout << ans[j] << (j < ans[0] ? " " : "\n");
         //if (j == ans[0]) cout << "i is :" << i << endl;
    }
    for (int j = i; j <= n; j++) {
        ans[++ans[0]] = j;
        make_num(j + 1, ans);
        ans[0]--;
    }
    return;
}
int main() {
    init();
    int ans[15] = {0};
    cin >> n;
    make_num(1, ans);
    return 0;
}