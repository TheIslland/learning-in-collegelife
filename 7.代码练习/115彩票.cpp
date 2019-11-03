/*************************************************************************
	> File Name: 115彩票.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:27:48 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int x, y, ans = 0;
    int a[2], b[2];
    cin >> x >> y;
    a[0] = x / 10 % 10;
    a[1] = x % 10;
    b[0] = y / 10 % 10;
    b[1] = y % 10;
    if (a[0] == b[0] && a[1] == b[1] ) {
        ans = 100;
    } else if (a[0] == b[1] && a[1] == b[0]) {
       ans = 20 ;
    } else if (a[0] != b[0] && a[0] != b[1] && a[1] != b[1] && a[1] != b[0]){
        ans = 0;
    } else {
        ans = 2;
    }
    cout << ans << endl;
    return 0;
}
