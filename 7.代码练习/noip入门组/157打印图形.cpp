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
    int h;
    cin >> h;
    h -= 1;
    for (int i = 0; i < h; i++)//上半部分的倒三角
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		char x = 'A';
		x += i;
		for (int j = 0; j < h - i; j++)
		{
			cout << (char)(x);
			x++;
		}
		cout << x;
		for (int j = 0; j < h - i; j++) {
			x--;
			cout << (char)(x);
		}
		printf("\n");
	}
	for (int i = 0; i <= h; i++)//下半部分正三角
	{
		for (int j = 0; j < h - i; j++)
		{
			printf(" ");
		}
		char x = 'A';
		x = x + h - i;
		for (int j = 0; j < i; j++)
		{
			cout << (char)(x);
			x++;
		}
		cout << x;
		for (int j = 0; j < i; j++)
		{
			x--;
			cout << (char)(x);
		}
		printf("\n");
	}

    return 0;
}
