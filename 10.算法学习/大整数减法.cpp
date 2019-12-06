/*************************************************************************
	> File Name: 大整数减法.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  8 12:03:14 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;\
}
void sub(char *str_a, char *str_b) {
    int len1 = strlen(str_a), len2 = strlen(str_b), flag = 0;
    if (len1 < len2 || (len1 == len2 && strcmp(str_a, str_b) < 0)) {
        SWAP(str_a, str_b);
        SWAP(len1, len2);
        flag = 1;
    }
    cout << str_a << endl;
    cout << str_b << endl;
    int a[505] = {0}, b[505] = {0};
    for (int i = 0; i < len1; i++) {
        a[i] = str_a[len1 - i - 1] - 48;
    }
    for (int i = 0; i < len2; i++) {
        b[i] = str_b[len2 - i - 1] - 48;
    }
    for (int i = 0; i < len1; i++) {
        a[i] -= b[i];
        if (a[i] >= 0) continue;
        a[i + 1] -= 1;
        a[i] = 10 + a[i];
    }
    flag && (cout << "-");
    int len = len1;
    while (a[len] == 0) len--;
    for (int i = len; i >= 0; i--) {
        cout << a[i];
    }
} 

int main() {
    char a[500];
    char b[500];
    cin >> a >> b;
    sub(a, b);
    return 0;
}
