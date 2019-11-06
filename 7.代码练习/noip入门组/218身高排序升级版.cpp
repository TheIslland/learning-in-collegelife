/*************************************************************************
	> File Name: 218身高排序升级版.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 22:55:28 2019
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
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = c;\
}
struct Node{
    int height, num;
};
bool cmp(struct Node a, struct Node b) {
    if (a.height == b.height) return a.num < b.num;
    return a.height < b.height;
}
int main() {
    int n, m;
    struct Node a[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        Node temp = {m, i + 1};
        a[i] = temp;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].num << (i < n - 1 ? " " : "");
    }
    return 0;
}
