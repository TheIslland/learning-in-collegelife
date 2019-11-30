/************************************************************
    File Name : 585排名.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-30 星期六 17:29:21
************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

typedef struct Node {
    int a, b;
    Node(){};
    Node(int a, int b) {
        this->a = a;
        this->b = b;
    }
} Node;
bool cmp(Node A, Node B) {
    if (A.a == B.a) return A.b < B.b;
    return A.a > B.a;
}
int main() {
    int n, a, b, g[7] = {0};
    cin >> n;
    struct Node c[205];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        c[i] = Node(a, b);
    }
    sort(c, c + n, cmp);
    for (int i = 0; i < n; i++) {
       // cout << c[i].a << " " << c[i].b << endl;
        int sum = 0;
        for (int j = 1; j <= 6; j++) {
            c[i].b > j && (sum += g[j]);
        }
        g[c[i].b]++;
        cout << sum << endl;
    }
    return 0;
}