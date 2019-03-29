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
/*此题，由题意可知，由于墙壁是环形的，所以末尾墙壁（即当前块墙壁）不能与第一块墙壁颜色相同而且每相邻的两个墙颜色不能相同，故我们可以分析出两种情况，
 * 情况一：当前块墙壁的前一块墙壁与第一块墙壁颜色相同时，我们可以推知当前块墙壁dp[i] 的颜色与dp[i - 2]块墙壁颜色相同，且有两种情况
 *情况二dp[i - 1]块墙壁与第以块墙壁颜色不同,故由与总计三种颜色，dp[i - 1] 与头墙壁确定了两种颜色，故dp[i]的颜色总数与dp[i - 1]的颜色总数相同
 *由此得出第dp[i]块墙壁的颜色种类为dp[i] = dp[i - 1] + dp[i - 2] * 2
 * */
