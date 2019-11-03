/*************************************************************************
	> File Name: 124招聘.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 18:45:58 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a > 0 || b <= 50) && (c <= 25 || d >= 5)) {
        cout << "ok" << endl;
    } else {
        cout << "pass" << endl;
    }
    return 0;
}
