/*************************************************************************
	> File Name: 得到整数ｘ.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 15时02分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    int a[n];
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        int total1 = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total1 += a[j];
            }
        }
        if (total1 == x) ans++;
    }
    cout << ans << endl;
    return 0;
}
