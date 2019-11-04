/*************************************************************************
	> File Name: 149最后一个单词.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:56:41 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main() {
	char str[100];
	char ans[100];
	while (scanf("%s", str) != EOF) {
		strcpy(ans, str);
	}
	cout << strlen(ans) << endl;
    return 0;
}
