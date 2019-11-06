/*************************************************************************
	> File Name: 188指定范围内的质数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 09:34:38 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define MAX_N 1000005
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;\
}
int prime[MAX_N] = {0};
void init() {
    for (int i = 2; i <= MAX_N; i++){
        if (prime[i]) continue;
        for (int j = i * 2;  j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) SWAP(n, m);
    init();
    for (int i = n; i <= m; i++) {
        if (!prime[i]) cout << i << endl;
    }
    return 0;
}
