/*************************************************************************
	> File Name: 正方形.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月02日 星期六 13时24分55秒
 ************************************************************************/
#include <iostream>
using namespace std;

int flag = 0, n, a[30], temp[5] = {0}, len = 0;

void dfs(int i, int num) {
    if (flag) return ;
    temp[num] += a[i];
    if (temp[0] > len || temp[1] > len || temp[2] > len || temp[3] > len) {
        temp[num] -= a[i];
        return ;
    }
    if (temp[0] == len && temp[1] == len && temp[2] == len && temp[3] == len) {
        flag = 1;
        return ;
    }
    if (n + 1 < i) {
        if (!flag) dfs(i + 1, 0);
        if (!flag) dfs(i + 1, 1);
        if (!flag) dfs(i + 1, 2);
        if (!flag) dfs(i + 1, 3);
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
    if (len % 4) {
        cout << "No" << endl;
        return 0;
    }
    len /= 4;
    dfs(0, 0);
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
