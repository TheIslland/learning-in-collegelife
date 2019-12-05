/************************************************************
    File Name : 446回型方阵.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-05 星期四 19:42:00
************************************************************/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    int n, m, i, j, k;
    char a[15][15];
	cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n - i + 1; j++) {
            for (k = i; k <= n - i + 1; k++) {
                a[j][k] = i;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j - 1) cout << " ";
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}