/*************************************************************************
	> File Name: 132n个数的乘法.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 14:12:41 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n, m;
    long long int ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        ans *= m;
    }
    cout << ans << endl;
    return 0;
}
