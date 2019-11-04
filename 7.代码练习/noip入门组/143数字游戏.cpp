/*************************************************************************
	> File Name: 143数字游戏.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 19:38:51 2019
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define swap(a, b) {\
        __typeof(a) c = a; a = b; b = c;\
}
using namespace std;
int is_abprime(int n) {
	int a, b, c = 0;
	a = n / 1000;
	b = n / 100 % 10;
	c = a * 10 + b;
	for (int i = 2; i < c; i++) {
		if (c % i == 0) return 0;
	}
	return 1;
}

int is_square(int n) {
	int a, b, c;
	a = n / 10 % 10;
	b = n % 10;
	c = a * 10 + b;
	int temp = sqrt(c);
	if (temp * temp != c) return 0;
	else return 1;
}
int main() {
	int a, b, n = 1, cnt = 0;
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	for (int i = a; i <= b; i++) {
		if ((i % 6 == 0) && is_abprime(i) && is_square(i)) {
			if (n == 1) {
				cout << i;
				n++;
			}else {
				cout << " " << i;
			}
			cnt++;
		}
	}
	cout << endl << cnt;;
    return 0;
}
