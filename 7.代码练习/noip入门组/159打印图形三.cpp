/*************************************************************************
	> File Name: 157打印图形.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 00:04:37 2019
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    char h;
    cin >> h;
    int len1 = h - 'A';
    for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		char x = h - i;
        cout << x;
		x -= 1;
		for (int j = 0; j < len1 - i; j++)
		{
			cout << (char)(x);
			x--;
		}
        x++;
		for (int j = 0; j < len1 - i; j++) {
			cout << (char)(x);
            x++;
		}
		printf("\n");
	}
    return 0;
}
