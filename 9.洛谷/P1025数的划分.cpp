/*************************************************************************
	> File Name: P1025数的划分.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed Apr 10 19:33:56 2019
 ************************************************************************/

#include<iostream>
using namespace std;

long long int dp[205][7] = {0};

void init() {
    for (int i = 0; i < 201; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2; i < 7; i++) {
        dp[1][i] = 0;
        dp[0][i] = 0;
    }
    for (int i = 2; i < 201; i++) {
        for (int j = 2; j < 7; j++) {
            if (j > i) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    } 
}

int main() {
    init();
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << endl;
    return 0;
}
