/*************************************************************************
	> File Name: 534体积.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 22:12:17 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
int v[55] = {0};
int a[10000] = {0};
int ans = 0;
void dfs(int n, int ind, int sum) {
    if (ind == n) {
        return ;
    }
    for (int i = ind; i < n; i++) {
        int temp = sum + v[i];
        if (a[temp] == 0) {
            a[temp] = 1;
            ans++;
        }
        dfs(n, i+ 1, temp);
    }
    return ;
}
int main() {
    a[0] = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dfs(n, 0, 0);
    cout << ans << endl;
    return 0;
}
