/*************************************************************************
	> File Name: 最大子阵和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 11时26分28秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
int main() {
    int n, m, temp, ans = INT_MIN;
    cin >> n >> m;
    int a[55][55] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> temp;
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + temp;
        if (a[i][j] > ans) ans = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int p = 1; p <= i; p++) {
                for (int q = 1; q <= j; q++) {
                    int judg = a[i][j] - a[p - 1][j] - a[i][q - 1] + a[p - 1][q - 1];
                    if (judg > ans) ans = judg;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
