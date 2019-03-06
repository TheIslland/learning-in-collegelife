/*************************************************************************
	> File Name: 八皇后.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月06日 星期三 19时20分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

int l[30] = {0};
int r[30] = {0};
int note[30] = {0};
int temp[30] = {0};
int ans = 0, n;

void dfs(int i) {
    if (i >= n) {
        if (ans <= 2) {
            for (int k = 0; k < n; k++) {
                cout << temp[k] + 1 << " ";
            }
            cout << endl;
        }
        ans++;
        return ;
    }
    for (int j = 0; j < n; j++) {
        if (!l[i + j] && !r[j - i + n] && !note[j]) {
            l[i + j] = r[j - i + n] = note[j] = 1;
            temp[i] = j;
            dfs(i + 1);
            l[i + j] = r[j - i + n] = note[j] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}
