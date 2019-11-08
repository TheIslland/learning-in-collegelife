/*************************************************************************
	> File Name: 221抢气球.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 23:52:03 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
struct Node {
    int h, ind;
};
bool cmp(struct Node a, struct Node b) {
    return a.h < b.h;
}
int main() {
    int n, m, k;
    struct Node a[100005];
    int b[100005] = {0};
    int c[100005] = {0};
    cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &a[i].h);
        a[i].ind = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n, cmp);
    sort(b, b + m);
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (; j < m; j++) {
            if (a[i].h >= b[j]) {
                c[a[i].ind]++;
            } else {
                break;
            }
        }
        if (j >= m) break;
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << endl;
    }
    return 0;
}
