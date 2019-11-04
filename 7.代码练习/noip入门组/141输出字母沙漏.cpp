/*************************************************************************
	> File Name: 141输出字母沙漏.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 17:54:22 2019
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int h;
    cin >> h;
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
