/*************************************************************************
	> File Name: 任务系统.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 19时11分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

struct Node {
    int num;
    int key;
    int org;
    bool operator < (const Node &a) const {
        if (this->key == a.key) return this->num > a.num;
        return this->key > a.key;
    }
};


int main() {
    int n, k; 
    priority_queue<Node> q;
    cin >> n >> k;
    while (n--) {
        string no;
        int num, value;
        cin >> no >> num >> value;
        struct Node temp;
        temp.num = num;
        temp.key = value;
        temp.org = value;
        q.push(temp);
    }
    for (int i = 0; i < k; i++) {
        struct Node temp = q.top();
        cout << temp.num << endl;
        temp.key += temp.org;
        q.pop();
        q.push(temp);
    }
    return 0;
}
