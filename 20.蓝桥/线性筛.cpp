/*************************************************************************
	> File Name: 线性筛.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 15时55分30秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;
#define MAX_N 10000000
int prime[MAX_N + 10] = {0};
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        cout << prime[i] << endl;
    }
    return 0;
}
