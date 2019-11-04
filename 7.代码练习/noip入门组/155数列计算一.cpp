/*************************************************************************
	> File Name: 155数列计算一.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 23:36:57 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, cnt = 0, sum = 3, temp = 0, ans = 0;
    cin >> n;
    while (cnt < n) {
        cout << sum << endl;
        ans += sum;
        temp += 2;
        sum += temp;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
