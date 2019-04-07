/*************************************************************************
	> File Name: 简单排序.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 11时11分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
bool cmp (int a, int b) {
    if (abs(a) > abs(b)) return true;
    else return false;
}
using namespace std;
int main() {
    int n;
    int arr[200];
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}
