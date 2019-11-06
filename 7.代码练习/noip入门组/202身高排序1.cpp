/*************************************************************************
	> File Name: 202身高排序1.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 16:44:35 2019
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
bool cmp(const Node &a, const Node &b) {
    return a.height < b.height;
}
int main() {
    int n, m;
    struct Node a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        Node temp = {m, i + 1};
        a[i] = temp;
    }
    int judg = 1;
    for (int i = 1; i < n - 1 && judg; i++) {
        judg = 0;
        for (int j = 0; j < n - i; j++) {
            if (a[j + 1].height < a[j].height) {
                SWAP(a[j + 1].height, a[j].height);
                SWAP(a[j + 1].num, a[j].num);
                judg++;
            }
        }
    }
  //  sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i].num << (i < n - 1 ? " " : "");
    }
    return 0;
}
