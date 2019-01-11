/*************************************************************************
	> File Name: 交叉排序.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 15时36分42秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
    int n, l1, l2, r1, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    int a[n];
    for (int i = 0; i < n; i++) {
		cin >> a[i];
    }
    sort(a + l1 - 1, a + r1);
    sort(a + l2 - 1, a + r2, cmp);
    for (int i = 0; i < n; i++) {
		cout << a[i];
        if (i < n - 1) cout << " ";
    }
	return 0;
}
