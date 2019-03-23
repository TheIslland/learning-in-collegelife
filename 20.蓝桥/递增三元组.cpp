/*************************************************************************
	> File Name: 递增三元组.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 14时18分40秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 10], b[n + 10], c[n + 10];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = lower_bound(a, a + n, b[i]) - a;
        int y = n - (upper_bound(c, c + n, b[i]) - c);
        ans = ans + x * y;
    }
    cout << ans << endl;
    return 0;
}

