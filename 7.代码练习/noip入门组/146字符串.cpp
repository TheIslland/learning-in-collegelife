/*************************************************************************
	> File Name: 146字符串.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:34:35 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'z' || str[i] == 'Z') {
			str[i] -= 25;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
			str[i] += 1;
		}
	}
	cout << str << endl;
    return 0;
}
