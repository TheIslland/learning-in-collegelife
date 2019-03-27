/*************************************************************************
	> File Name: 蒜头君的猜想.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月27日 星期三 19时52分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 8000010

int prime[MAX_N] = {0};

void init() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1; 
        }
    }
}

int main() {
    int n, ans = 0;
    init();
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!prime[i] && !prime[n - i] && n - i >= i) {
            ans++;
        }
    }
    cout << ans << endl; 
    return 0;
}
