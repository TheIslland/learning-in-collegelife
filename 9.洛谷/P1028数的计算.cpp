/*************************************************************************
	> File Name: P1028数的计算.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Apr 10 20:32:08 2019
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[1005];

void init() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for (int i = 4; i < 1001; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i - 1] + dp[i / 2];
        } else {
            dp[i] = dp [i - 1];
        }
    }
}

int main() {
    int n;
    init();
    cin >> n;
    cout << dp[n] << endl;
    return 0;
}
