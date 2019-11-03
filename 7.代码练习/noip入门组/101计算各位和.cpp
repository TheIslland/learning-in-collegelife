/*************************************************************************
	> File Name: 101计算各位和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 10:13:30 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    while(n) {
        ans += n % 10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}
