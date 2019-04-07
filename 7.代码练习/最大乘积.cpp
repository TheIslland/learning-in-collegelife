/*************************************************************************
	> File Name: 最大乘积.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 16时29分03秒
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
    int n;
    cin >> n;
    long long int num[5], temp;
    num[0] = num[1] = INT_MAX;
    num[2] = num[3] = num[4] = INT_MIN;
    for (int i = 0 ; i < n; i++) {
        cin >> temp;
        if (temp > num[4]) {
            num[2] = num[3];
            num[3] = num[4];
            num[4] = temp;
        } else if (temp > num[3]) {
            num[2] = num[3];
            num[3] = temp;
        } else if (temp > num[2]) {
            num[2] = temp;
        } else {
        }
        if (temp < num[0]) {
            num[1] = num[0];
            num[0] = temp;
        } else if (temp < num[1]) {
            num[1] = temp;
        } else {
        }
    }
    long long int ans = (num[0] * num[1] * num [4] > num[2] * num[3] * num[4] ? num[0] * num[1] * num[4] : num[2] * num[3] * num[4]);
    cout << ans << endl;
    return 0;
}
