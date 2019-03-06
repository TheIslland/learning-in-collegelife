/*************************************************************************
	> File Name: 考试成绩排序.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月06日 星期三 21时59分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Node {
public:
    int value;
    string name;
};
int main() {
    int input;
    string name;
    vector<Node> v;
    Node tem;
    while (cin >> tem.name >> tem.value) {
        v.push_back(tem);
    }
    sort(
        v.begin(), 
        v.end(), 
        [](const Node &a, const Node &b){
            if (a.value < b.value) return true;
            if (a.value == b.value && a.name < b.name) return true;
            return false;
        }
        );
    for (auto x: v) {
        cout << x.name << " " << x.value << endl;
    }
    cout << v.size() << endl;
    return 0;
}
