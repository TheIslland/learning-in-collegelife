/************************************************************
    File Name : 586排列.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-30 星期六 16:29:10
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
    int x, y, z, sum = 0, a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cin >> x >> y >> z;
    sum += x + y + z;
    do {
        int b = a[0] * 100 + a[1] * 10 + a[2];
        int c = a[3] * 100 + a[4] * 10 + a[5];
        int d = a[6] * 100 + a[7] * 10 + a[8];
        if (sum * b / x == sum * c / y && sum * c / y == sum * d / z)
            cout << b << " " << c << " " << d << endl;
    } while (next_permutation(a, a + 9));
    return 0;
}