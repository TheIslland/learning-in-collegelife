/*************************************************************************
	> File Name: 买书.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月27日 星期三 22时30分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

long long int n, m, k;

long long int pi[100];

bool dfs(long long int i, long long int sum, long long int num) {
    if (i == n) {
        return ((sum == m) && (num == k));
    }
    if (num > k || sum > m) return false;
    if (dfs(i + 1, sum, num)) return true;
    if (dfs(i + 1, sum + pi[i], num + 1)) return true;
    return false;
}

int main() {
    cin >> m >> n >> k;
    for (long long int i = 0; i < n; i++) cin >> pi[i];
    if (dfs(0, 0, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
