/*************************************************************************
	> File Name: 计算集合的并集.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月19日 星期六 19时51分48秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;
int main() {
    set<int> s;
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0 ; i < n + m; i++) {
        cin >> temp;
        s.insert(temp);
    }
    set<int>::iterator it = s.begin();
    cout << (*it);
    it++;
    for (; it != s.end(); it++) {
        cout << " " << (*it);
    }
    s.clear();
    return 0;
}
