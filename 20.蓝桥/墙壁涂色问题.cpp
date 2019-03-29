/*************************************************************************
	> File Name: 墙壁涂色问题.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月29日 星期五 20时24分39秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
#define MAX_N 55

int n;
long long int dp[MAX_N];
int main() {
    cin >> n;
    dp[1] = 3;
    dp[2] = 6;
    dp[3] = 6;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}
