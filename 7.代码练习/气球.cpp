/*************************************************************************
	> File Name: 气球.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 11时30分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int main() {
    int n, min = INT_MAX, ind = 0, ans = 0;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        ans += num[i];
        if (min > num[i]) {
            ind = i;
            min = num[i];
        }
    }
    if (n == 1) cout << "-1" << endl;
    else if (ans - min == min) cout << "-1" << endl;
    else {
        cout << 1 << endl << ind << endl;
    }
        return 0;
}
