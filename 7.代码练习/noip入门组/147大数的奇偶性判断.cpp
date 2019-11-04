/*************************************************************************
	> File Name: 147大数的奇偶性判断.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:44:05 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    char str[10005];
    cin >> str;
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	int x = (int)str[--i];
	cout << (x & 1 ? "NO" : "YES");
    return 0;
}
