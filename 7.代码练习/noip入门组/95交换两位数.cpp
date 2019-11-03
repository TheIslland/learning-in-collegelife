/*************************************************************************
	> File Name: 95交换两位数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  1 20:24:21 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << n % 10 << n / 10 % 10 << endl;
    return 0;
}
