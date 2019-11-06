/*************************************************************************
	> File Name: 203身高排队.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 17:34:55 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
typedef long long ll;
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, temp, sum = 0;
	int a[105] = { 0 };
	int b[14][14] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			sum += temp;
			a[++a[0]] = temp;
			b[i][j] = temp;
		}
	}
	sort(a + 1, a + a[0] + 1, cmp);
	for (int i = 0; i < m; i++) {
		int max = -1;
		for (int j = 0; j < n; j++) {
			b[j][i] > max && (max = b[j][i]);
		}
		cout << max << endl;
	}
	for (int i = 1; i <= a[0]; i++) {
		cout << a[i] << (i < a[0] ? " " : "");
	}
	int ave = round(sum * 1.0 / a[0]);
	int ans = 0;
	cout << endl << ave << endl;
	for (int i = 1; i <= a[0]; i++) {
		a[i] >= ave && ans++;
	}
	cout << ans << endl;
	return 0;
}