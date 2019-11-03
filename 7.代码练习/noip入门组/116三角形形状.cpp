/************************************************************************
	> File Name: 116三角形形状.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 13:47:04 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int a[3];
    string ans;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] > a[2]) {  
        if (a[0] * a[0] + a[1] * a[1] > a[2] * a[2]) {
            ans = "acute triangle";
        } else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]){
            ans = "right triangle";
        } else {
            ans = "obtuse triangle";
        } 
    }else ans = "illegal triangle";
    cout << ans << endl;
    return 0;
}
