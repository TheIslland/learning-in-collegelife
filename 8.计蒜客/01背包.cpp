/*************************************************************************
	> File Name: 01背包.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月10日 星期日 20时29分40秒
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define max_n 105
#define max_v 10005

int v[max_n + 5];
int w[max_n + 5];
int dp[max_n + 5][max_v + 5];


int main() {
    int N, V;
    cin >> V >> N;
    for(int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j < v[i]) { 
                continue;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[N][V] << endl;
    return 0;
}
