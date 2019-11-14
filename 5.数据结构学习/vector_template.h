/*************************************************************************
	> File Name: vector_template.h
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov 14 19:50:44 2019
 ************************************************************************/

#ifndef _VECTOR_TEMPLATE_H
#define _VECTOR_TEMPLATE_H
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;
template<typename Type> class Vector {
private:
    int size, length;
    Type *data;
public:
    Vector(int len) {
        size = len;
        length = 0;
        data = (Type *)malloc(sizeof(Type) * size);
    }
    ~Vector() { delete data; }
    void expand() {
        Type *old = data;
        size *= 2;
        data = (Type *)malloc(sizeof(Type) * size);
        for (int i = 0; i < length; i++) {
            data[i] = old[i];
        }
    }
    bool insert(int loc, Type val) {
        if (loc < 0 || loc > length) return false;
        if (length >= size) expand();
        for (int i = loc; i < length; i++) {
            data[i + 1] = data[i];
        }
        data[loc] = val;
        length++;
        return true;
    }
    bool search(Type val) {
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
#endif
