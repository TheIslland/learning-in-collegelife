/*************************************************************************
	> File Name: 184路飞吃桃.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 01:11:25 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, ans = 1;
    cin >> n;
    n -= 1;
    while (n--) {
        ans = (ans + 1) * 2;
    }
    cout << ans << endl;
    return 0;
}
