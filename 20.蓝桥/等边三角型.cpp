/*************************************************************************
	> File Name: 等边三角型.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月02日 星期六 08时53分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int n, flag = 0, num, sum = 0;
double len = 0;
int a[40];
int temp[4];

void dfs(int i, int num) {
    temp[num] += a[i];
    //剪枝2最优性剪枝
    if (falg) return ;
    //剪枝３
    if (temp[0] > len || temp[1] > len || temp[2] > len) {
        temp[num] -= a[i];
        return ;
    }
    if (temp[0] == len && temp[1] == len && temp[2] == len) {
        flag = 1;
        return ;
    }
    if (i + 1 < n) {
        if (!flag) dfs(i + 1, 0);
        if (!flag) dfs(i + 1, 1);
        if (!flag) dfs(i + 1, 2);
    }
    temp[num] -= a[i];
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len += a[i];
    }
    len /= 3;
    //剪支１
    if (len > (int)len) {
        cout << "no" << endl;
    } else {
        dfs(0, 0);
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
