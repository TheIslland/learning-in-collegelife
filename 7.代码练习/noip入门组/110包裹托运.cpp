/*************************************************************************
	> File Name: 110包裹托运.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 11:42:31 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double x;
    cin >> x;
    cout << setiosflags(ios::fixed) << setprecision(2) << (x > 15 ? 15 * 6 + (x - 15) * 9.0 : x * 6) << endl;
    return 0;
}
