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

using namespace std;

class Vector {
private:
    int size, length;
    int *data;
public:
    Vector(int len) {
        size = len;
        length = 0;
        data = (int *)malloc(sizeof(int) * size);
    }
    ~Vector() { delete data; }
    void expand() {
        int *old = data;
        size *= 2;
        data = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < length; i++) {
            data[i] = old[i];
        }
    }
    bool insert(int loc, int val) {
        if (loc < 0 || loc > length) return false;
        if (length >= size) expand();
        for (int i = loc; i < length; i++) {
            data[i + 1] = data[i];
        }
        data[loc] = val;
        length++;
        return true;
    }
    bool search(int val) {
        if (length == 0) return false;
        for (int i = 0; i < length; i++) {
            if (data[i] == val) return true;
        }
        return false;
    }
    bool delete_node(int ind) {
        if (ind < 0 || ind >= length) return false;
        for (int i = ind; i < length; i++) {
            data[i] = data[i + 1];
        }
        length--;
        return true;
    }
    void output() {
        if (length == 0) {
            cout << "The Vector is Empty = []" << endl;
            return;
        }
        cout << "The Vector is = [ ";
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
        return;
    }
};

int main() {
    Vector a(100);
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