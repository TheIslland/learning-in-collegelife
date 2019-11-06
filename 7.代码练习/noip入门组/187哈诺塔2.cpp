/*************************************************************************
	> File Name: 187哈诺塔2.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 09:14:31 2019
 ************************************************************************/

#include <stdio.h>

long long hnt(int n) {
	long long ans = 0;
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (n == 3) return 7;
	return ans = 2 * hnt(n - 1) + 1;
}
long long cnt(int n) {
	long long ans = 0;
	if (n == 1) return 1;
	if (n == 2) return 4;
	return ans = 2 * cnt(n - 1) + n;
}
int main() {
	long long n, ans, cost;
	scanf("%lld", &n);
	ans = hnt(n);
	cost = cnt(n);
	printf("%lld %lld", ans, cost);
	return 0;
}