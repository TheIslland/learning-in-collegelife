/*************************************************************************
	> File Name: 186跳弹簧.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 01:22:45 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int a[100005] = {0};
int n;
int ans = 0;
int f(int x) {
    if (n < x) return ans;
    ans++;
    return f(x + a[x]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << f(1) << endl;
    return 0; 
}
