/*************************************************************************
	> File Name: n个最小和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 20时35分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

struct cmp{
    bool operator ()(int &a, int &b) {
        return a > b;
    }
};

int main() {
    priority_queue<int, vector<int>, cmp> q;
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            q.push(a[i] + b[j]);
        }
    }
    while (n--) {
        cout << q.top();
        if (n > 0) cout << " ";
        q.pop();
    }
    return 0;
}
