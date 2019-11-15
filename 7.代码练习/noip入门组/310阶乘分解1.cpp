/*************************************************************************
        > File Name: 310阶乘分解1.cpp
        > Author: TheIslland
        > Mail: voidland@163.com, 861436930@qq.com
        > Created Time: Fri Nov 15 19:33:40 2019
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

#define MAX_N 1000000
int cnt[MAX_N];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int num = i;
        for (int j = 2; j * j <= num; j++) {
            if (num % j) continue ;
            while (num % j == 0) cnt[j]++, num /= j;
        }
        cnt[num]++;
    }
    for (int i = 2; i <= n; i++) {
        if (!cnt[i]) continue;
        cout << i << " " << cnt[i] << endl;
    }
    return 0;
}
