/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Apr  8 12:17:28 2019
 ************************************************************************/

#include<iostream>
using namespace std;

int dp[10][10] = {0};

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << dp[i][j];
        }
    }
    return 0;
}
