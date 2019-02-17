/*************************************************************************
	> File Name: 红黑树应用.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月17日 星期日 19时35分14秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

class A{
public:
    A(int x) : x(x) {}
    bool operator<(const A &obj) const {
        return this->x < obj.x;
    }
    A &operator<<(int &x) const {
        x += 1;
        return *this;
    }
    A &operator>>(int &x) const {
        x -= 1;
        return *this;
    }
    int x;
};

int main() {
    map<A, int> arr;
    arr[A(4)] = 5;
    for (auto x : arr) {
        cout.operator<<(const A &);
        cout << x.first << " " << x.second << endl;
    }
    set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(4);
    s.insert(6);
    for (auto x : s) {
        cout << x << endl;
    }
    return 0;
}
