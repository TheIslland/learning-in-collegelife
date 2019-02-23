/*************************************************************************
	> File Name: n个最小和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月22日 星期五 14时42分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

struct Node{
    int x, y, sum;
    Node(int a, int b, int temp) {x = a; y = b; sum = temp;}
    bool operator < (const Node &b) const {
        return this->sum >= b.sum;
    }
};

int main() {
    priority_queue<Node> q;
    int n, ind = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        q.push(Node(0, i, a[0] + b[i]));
    }
    while (n--) {
        Node temp = q.top();
        cout << temp.sum;
        if (n >= 1) cout << " ";
        q.pop();
        q.push(Node(temp.x + 1, temp.y, a[temp.x + 1] + b[temp.y]));
    }
    return 0;
}
