/************************************************************
    File Name : 79输出素数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-06 星期五 20:02:07
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

using namespace std;
#define MAX_N 10000005

int prime[MAX_N];

void init() {
    for (int i = 2; i <= 10000000; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= 10000000; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    init();
    int a, b, j = 1;
    scanf("%d %d", &a, &b);
    while (a > prime[j]) j++;
    while (j <= prime[0] && prime[j] <= b) {
        printf("%d\n", prime[j]);
        j += 1;
    }
    return 0;
}