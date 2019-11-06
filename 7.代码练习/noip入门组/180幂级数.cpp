/*************************************************************************
	> File Name: 180幂级数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 00:54:51 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    unsigned long long int ans = 1;
    int n;
    cin >> n;
    while (n--) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}
