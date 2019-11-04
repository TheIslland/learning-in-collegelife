/*************************************************************************
	> File Name: 158打印图形二.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 00:07:04 2019
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
		int x = h;
		x -= i;
        cout << x;
		for (int j = 0; j < 2 * (h - i) - 1; j++)
		{
			cout << " ";
		}
		cout << x;
		printf("\n");
	}
    for (int i = 0; i < h; i++) cout << " ";
    cout << 0 << endl;
	for (int i = 1; i <= h; i++)//下半部分正三角
	{
		for (int j = 0; j < h - i; j++)
		{
			printf(" ");
		}
		int x = 0;
		x += i;
        cout << x;
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << " ";
		}
		cout << x;
		printf("\n");
	}

    return 0;
}
