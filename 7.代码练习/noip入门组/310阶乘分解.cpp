/************************************************************
    File Name : 310阶乘分解.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-15 星期五 17:39:12
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
#define MAX_N 1000000
int prime[MAX_N + 5];
using namespace std;

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i] == 0) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] < MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    init();
    for (int j = 1; j <= prime[0] && prime[j] <= n; j++) {
        int num = n, cnt = 0;
        while (num) {
            cnt += num / prime[j];
            num /= prime[j];
        }
        cout << prime[j] << " " << cnt << endl;
    }
    return 0;
}