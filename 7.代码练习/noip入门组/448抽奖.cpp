/*************************************************************************
	> File Name: 448抽奖.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 10:51:43 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
typedef long long ll;
using namespace std;
int main() {
    int n, m, num;
    int a[100005] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[m] = i + 1;
    }
    cin >> num;
    cout << a[num] << endl;
    return 0;
}
