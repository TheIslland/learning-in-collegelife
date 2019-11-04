/*************************************************************************
	> File Name: 142五位质数回文数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 19:10:59 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#define swap(a, b) {\
	__typeof(a) c = a; a = b; b = c;\
}
using namespace std;
int is_plal(int a) {
	int cmp = a, sum = 0;
	while (a) {
		sum = sum * 10 + a % 10;
		a /= 10;
	}
	return cmp == sum;
}
int is_prime(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0) return 0;
	}
	return 1;
}
int main() {
	int a, b, n = 1;
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	for (int i = a; i <= b; i++) {
		if (is_plal(i) && is_prime(i)) {
			if (n == 1) {
				cout << i;
				n++;
			}
			else {
				cout << " " << i;
			}
		}
	}
    return 0;
}
