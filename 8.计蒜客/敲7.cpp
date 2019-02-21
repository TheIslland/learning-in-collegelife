/*************************************************************************
	> File Name: 敲7.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 18时31分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

int red(int t) {
    int flag = 0;
    if (t % 7 == 0) return 0;
    while (t) {
        if (t % 10 == 7) return 0;
        t /= 10;
    }
    return 1;
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    queue<string> q;
    string temp;
    while (n--) {
        cin >> temp;
        q.push(temp);
    }
    m -= 1;
    while (m--) {
        q.push(q.front());
        q.pop();
    }
    while (q.size() > 1) {
        while (red(t)) {
            t++;
            q.push(q.front());
            q.pop();
        }
        q.pop();
        t++;
    }
    cout << q.front() << endl;
    return 0;
}
