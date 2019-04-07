/*************************************************************************
	> File Name: P1115_最大子段和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 20时42分48秒
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    int ans = a[0], sum = a[0];
    for (int i = 1; i < n; i++) {
        if (sum > 0) {
            sum += a[i];
        } else {
            sum = a[i];
        }
        ans = (ans > sum ? ans : sum);
    }
    cout << ans << endl;
    return 0;
}
