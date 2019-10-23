/*************************************************************************
	> File Name: 488城市路径.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Oct 22 19:13:35 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX_N 100005
int a[MAX_N][2] = {0};
int num[MAX_N][2] = {0};
int dis(int x, int y) {
    return abs(num[x][0] - num[y][0]) + abs(num[x][1] - num[y][1]);
}

int f(int n, int flag) {
    if (n == 2) return dis(1, 2);
    if (n == 3) return dis(1, 3);
    if (flag == 0) return f(n - 1, 0) + dis(n - 1, n);
    else return min(f(n - 1, 1) + dis(n - 1, n), f(n - 2, 0) + dis(n - 2, n));
} 

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i][0] >> num[i][1];
    }
    cout << f(n, 1) << endl;
    return 0;
}
