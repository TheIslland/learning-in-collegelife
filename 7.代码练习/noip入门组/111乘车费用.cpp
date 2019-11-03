/*************************************************************************
	> File Name: 111乘车费用.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 12:06:14 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n > 3) {
        cout << setiosflags(ios::fixed) << setprecision(1) << 14 + (n - 3) * 2.3 << endl;
    } else {
        cout << 14 << endl;
    }
    return 0;
}
