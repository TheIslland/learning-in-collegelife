/*************************************************************************
	> File Name: P1996_约瑟夫问题.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 10时35分08秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;


int main() {
    queue<int> q;
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        q.push(a[i]);
    }
    int cnt = 1, ind = 0;
    while (n--) {
        while (cnt != m) {
            int temp = q.front();
            q.pop();
            q.push(temp);
            cnt++;
        }
        cnt = 1;
        int x = q.front();
        cout << x;
        if (n >= 1) cout << " ";
        q.pop();
    }
    return 0;
}
