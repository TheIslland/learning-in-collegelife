/*************************************************************************
	> File Name: 序列求和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月22日 星期五 19时17分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;


int main() {
    long long int ans = 0, n, temp1, temp2;
    cin >> n;
    ans = n + n / 2 * (n - 1);
    cout << ans << endl;
    return 0;
}
