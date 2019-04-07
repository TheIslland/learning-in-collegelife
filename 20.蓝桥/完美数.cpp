/*************************************************************************
	> File Name: 完美数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 17时40分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int main() {
    int a[10005] = {0};
    for (int i = 6; i <= 10000; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) sum += j;
        }
        if (i == sum) a[i] = 1;
    }
    long long int ans = 0;
    for (int i = 6; i <= 10000; i++) {
        if (a[i]) ans += i;
    }
    cout << ans << endl;
    return 0;
}
