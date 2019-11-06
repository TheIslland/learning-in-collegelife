/*************************************************************************
	> File Name: 197排序的实现.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 19:55:40 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
bool cmp(int a, int b){
    return a > b ? a : b;
}
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;}
using namespace std;
int main() {
    int a[10] = {0};
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++) {
        int max = -1, ind = i;
        for (int j = i; j < 10; j++) {
            a[j] > max && (max = a[j], ind = j);
        }
        swap(a[i], a[ind]);
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << (i < 9 ? " " : "");
    }
    cout << endl;
    return 0;
}
