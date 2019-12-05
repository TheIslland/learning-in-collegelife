/************************************************************
    File Name : 237递归实现排列形枚举.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-05 星期四 20:15:25
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

int main() {
    int n;
    cin >> n;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i < n - 1 ? " " : "\n");
        }
    } while (next_permutation(a, a + n));
    return 0;
}