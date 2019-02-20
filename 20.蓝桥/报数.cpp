/*************************************************************************
	> File Name: 报数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月20日 星期三 18时22分40秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    int tot = 0;
    while (que.size() > 1) {
        tot = (tot + 1) % m;
        int temp = que.front();
        que.pop();
        if (tot != 0) {
            que.push(temp);
        }
    }
    cout << que.front() << endl;
    return 0;
}
