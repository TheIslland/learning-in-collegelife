/************************************************************
    File Name : vector.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-14 星期四 17:19:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include "vector_template.h"
using namespace std;



int main() {
    Vector<int> a(100);
    int m, t;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        int b, c;
        if (t == 1) {
            cin >> b >> c;
            a.insert(b, c);
        } else if (t == 2) {
            cin >> b;
            a.delete_node(b);
        } else if (t == 3) {
            cin >> b;
            a.search(b);
        } else {
            a.output();
        }
    }
    return 0;
}