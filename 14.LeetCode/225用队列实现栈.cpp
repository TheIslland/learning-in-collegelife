/************************************************************
    File Name : 225用队列实现栈.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-16 星期六 19:17:21
************************************************************/
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
class MyStack {
public:
    queue<int> a, b;
    /** Initialize your data structure here. */
    MyStack() {  
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = a.size();
        for (int i = 0; i < len - 1; i++) {
            b.push(a.front());
            a.pop();
        }
        int ret = a.front();
        a.pop();
        for (int i = 0; i < len - 1; i++) {
            a.push(b.front());
            b.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int len = a.size();
        for (int i = 0; i < len - 1; i++) {
            b.push(a.front());
            a.pop();
        }
        int ret = a.front();
        b.push(a.front());
        a.pop();
        for (int i = 0; i < len; i++) {
            a.push(b.front());
            b.pop();
        }
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {
    
    return 0;
}