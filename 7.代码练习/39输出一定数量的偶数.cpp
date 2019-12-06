/************************************************************
    File Name : 39输出一定数量的偶数.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-12-06 星期五 16:18:27
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
    int beg, n;
    cin >> beg >> n;
	beg < 0 && (beg = 0);
    beg & 1 && (beg += 1);
    for (int i = 0; i < n; beg++) {
        if (beg & 1) continue;
        cout << beg << endl;
        i++;
    }
    return 0;
}