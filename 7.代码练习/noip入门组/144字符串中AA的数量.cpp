/*************************************************************************
	> File Name: 144字符串中AA的数量.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:06:54 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	char str[105] = {0};
	int letter[200] = {0};
	cin >> str;
	int i = 0;
	while (str[i] != '\0') {
		letter[str[i]]++;
		i++;
	}
	cout << letter['A'] << endl;
    return 0;
}
