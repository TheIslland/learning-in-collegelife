/*************************************************************************
	> File Name: 素数筛.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 15时45分56秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define MAX_N 20000000
int prime[MAX_N] = {0};
int main() {
    int n;
    cin >> n;
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i * i <= n ;i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            prime[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
