/*************************************************************************
	> File Name: 承压计算.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 18时02分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio> 
using namespace std;
int main() {
    long double num[32][35] = {0};
    int sum = 0;
    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= i; j++) {
            num[i + 1][j] = num[i + 1][j] + num[i][j] / 2.0;
            num[i + 1][j + 1] = num[i + 1][j + 1] + num[i][j] / 2.0;
        }
    }
    long double min = 0x3f3f3f, max = -1;
    for (int i = 1; i <= 30; i++) {
        if (num[30][i] > max) max = num[30][i];
        if (num[30][i] < min) min = num[30][i];
    }
    double ans = max / min * 2086458231.0;
    printf("%lf\n", ans);
    return 0;
}
