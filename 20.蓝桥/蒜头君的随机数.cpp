/*************************************************************************
	> File Name: 蒜头君的随机数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 14时19分53秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a[110] = {0}, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) continue;
        num++;
    }
    cout << num + 1 << endl;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) continue;
        cout << a[i] << " ";
    }
    cout << a[n - 1];
    return 0;
}
