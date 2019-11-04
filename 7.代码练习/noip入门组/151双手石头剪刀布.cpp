/*************************************************************************
	> File Name: 151双手石头剪刀布.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Nov  3 22:32:20 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int judg(int a, int b) {
	if (a == 'O' && b == 'Y') {
		return 1;
	}
	else if (a == 'Y' && b == 'O') {
		return -1;
	}
	else if (a == 'Y' && b == 'H') {
		return 1;
	}
	else if (a == 'H' && b == 'Y') {
		return -1;
	}
	else if (a == 'H' && b == 'O') {
		return 1;
	}
	else if (a == 'O' && b == 'H') {
		return -1;
	}
	else {
		return 0;
	}
}
int main() {
	char a, b, c, d;
	cin >> a >> b >> c >> d;
	if (judg(a, c) > 0) {
		if (judg(a, d) >= 0) {
			cout << "MING" << endl;
		}
		else {
			if (judg(b, d) == 1) {
				cout << "MING" << endl;
			}
			else {
				cout << "LIHUA" << endl;
			}
		}
	}
	else if (!judg(a, c)){
		if (judg(b, d) == 1) {
			cout << "MING" << endl;
		}
		else if (judg(b, d) == 0) {
			cout << "TIE" << endl;
		}
		else {
			cout << "LIHUA" << endl;
		}
	}
	else {
		if (judg(b, c) <= 0) {
			cout << "LIHUA" << endl;
		}
		else {
			if (judg(b, d) >= 0){
				cout << "MING" << endl;
			}
			else {
				cout << "LIHUA" << endl;
			}
		}
	}
	return 0;
}