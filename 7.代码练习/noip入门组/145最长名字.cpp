/*************************************************************************
	> File Name: 145最长名字.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 20:13:52 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iomanip>
using namespace std;
int main() {
	int n, max = -10;
	cin >> n;
	getchar();
	char ans[105] = {0};
	for (int i = 0; i < n; i++) {
		char a[105];
		scanf("%s", a);
		getchar();
		int len = strlen(a);
		if (len > max) {
			max = len;
			strcpy(ans, a);
		}
	}
	cout << (string)ans << endl;
	return 0;
}
