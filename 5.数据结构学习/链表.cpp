/************************************************************
    File Name : 链表.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-10 星期天 12:30:06
************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include "LinkedList.h"
typedef long long ll;
using namespace std;

int main() {
    int m, t, a, b;
    cin >> m;
    LinkedList l;
    while (m--) {
        cin >> t;
        bool flag;
        switch (t) {
            case 1: {
                cin >> a >> b;
                Node *c = new Node(b);
                flag = l.insert(c, a);
                cout << (flag ? "insert success" : "insert failed") << endl;
            } break;
            case 2: {
                l.output();
            } break;
            case 3: {
                cin >> a;
                flag = l.delete_node(a);
                cout << (flag ? "insert success" : "insert failed") << endl;
            } break;
            case 4: {
                l.reverse_node();
            };
        }
    }
    return 0;
}
