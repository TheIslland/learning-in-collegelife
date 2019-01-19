/*************************************************************************
	> File Name: 蒜头军面试.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月19日 星期六 20时44分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
int main() {
    int n, temp, ind = 0, value = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0 ; i < n; i++) {
        cin >> temp;
        if (m.count(temp)) {
            m[temp] += 1;
        } else {
            m.insert(pair<int, int>(temp, 1));
        }
        if (m[temp] > value) {
            ind = temp;
            value = m[temp];
        } else if (m[temp] == value && temp > ind) {
            ind = temp;
        }
    }
    cout << ind << " " << value << endl;
    return 0;
}
