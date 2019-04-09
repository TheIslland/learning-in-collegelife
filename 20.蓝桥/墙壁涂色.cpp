/*************************************************************************
	> File Name: 墙壁涂色.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon Apr  8 16:24:35 2019
 ************************************************************************/

#include<iostream>
using namespace std;

long long int dp[1005][1000] = {0};

void Addtion(long long int *a, long long int *c) {
	if (a[0] > c[0]) 
		c[0] = a[0];
    for (int i = 1; i <= a[0]; i++) {
        c[i] += a[i]; 
    }
    for (int j = 1; j <= c[0]; j++) {
        if (c[j] < 10) continue; 
        c[j + 1] += c[j] / 10; 
        c[j] = c[j] % 10; 
        if (j == c[0]) c[0] += 1; 
    }
}

/*
        for (int j = dp[i][-1]; j > 0; j--) {
            cout << dp[i][j]; 
        }
        cout << endl;
*/
void init(int a, int b) {
    dp[1][0] = 1;
    dp[1][1] = b;
    dp[2][0] = 1;
    dp[2][1] = b * (b - 1);
    dp[3][0] = 1;
    dp[3][1] = b * (b - 1) * (b - 2);
    for (int i = 4; i <= a; i++) {
        for (int j = 1; j <= b - 2; j++) Addtion(dp[i - 1], dp[i]);
        for (int j = 1; j <= b - 1; j++) Addtion(dp[i - 2], dp[i]);
    }
}

int main() {
    int n, k;
    init(n, k);
    cin >> n >> k;
    init(n, k);
    for (int i = dp[n][0]; i > 0; i--) {
        cout << dp[n][i]; 
    }
    cout << endl;
    return 0;
}

