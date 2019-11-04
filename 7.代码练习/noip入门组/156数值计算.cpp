/*************************************************************************
	> File Name: 156数值计算.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 23:52:42 2019
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define swap(a, b) {\
        __typeof(a) c = a; a = b; b = c;\
}
using namespace std;
int is_prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int is_square(int n) {
	int temp = sqrt(n);
	if (temp * temp != n) return 0;
	else return 1;
}
int main() {
	int a, b, n = 1, cnt = 0;
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	for (int i = a; i <= b; i++) {
		if (is_prime(i) && is_square(i / 100) && is_square(i % 100)) {
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
