/*************************************************************************
	> File Name: 杨辉三角形.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年04月04日 星期四 18时25分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

long long int dp[55][55] = {0};

void init() {
    dp[1][1] = 1;
    for (int i = 2; i < 51; i++) {
        for (int j = 1; j < 51; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }    
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    cout << dp[n][m] << endl;
    return 0;
}
