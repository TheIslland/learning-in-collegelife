/*************************************************************************
	> File Name: 148字符反转.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:54:03 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	cout << str << endl;
    return 0;
}
