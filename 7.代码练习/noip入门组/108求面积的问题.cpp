/*************************************************************************
	> File Name: 108求面积的问题.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 11:10:16 2019
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main() {
    double m, n;
    char flag;
    cin >> flag >> m >> n;
    cout << setiosflags(ios::fixed) << setprecision(2) << (flag == 'r' ? m * n : m * n * 0.5) << endl;
    return 0;
}
