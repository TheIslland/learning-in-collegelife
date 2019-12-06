/*************************************************************************
	> File Name: 大整数乘法.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 17:45:28 2019
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
void mul(char *str_a, char *str_b) {
    int len1 = strlen(str_a), len2 = strlen(str_b);
    int a[505] = {0}, b[505] = {0};
    int c[10010] = {0};
    for(int i = 0 ; i < len1; i++) {
        a[i] = str_a[len1 - i - 1] - 48;
    }
    for(int i = 0 ; i < len2; i++) {
        b[i] = str_b[len2 - i - 1] - 48;
    }
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            c[i + j] += a[i] * b[j];
        }
        for (int j = 0; j < len2 + i; j++) {
            if (c[j] < 10) continue;
            c[j + 1] += c[j] / 10;
            c[j] %= 10;
        }
    }
    int len3 = len1 + len2 + 1;
    while (c[len3] == 0) len3--;
    for(int i = len3; i >= 0; i--) {
        cout << c[i];
    }
} 
int main() {
    char a[505];
    char b[505];
    cin >> a >> b;
    mul(a, b);
    return 0;
}
