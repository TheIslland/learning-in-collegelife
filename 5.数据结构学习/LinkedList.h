/************************************************************
    File Name : LinkedList.h
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-13 星期三 20:59:25
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

class Node {
public:
    int data;
    Node *next;
    Node(int val);
    Node();
};

class LinkedList {
private:
    Node head;
    int length = 0;
public:
    LinkedList();
    ~LinkedList();
    bool insert(Node *node, int ind);
    bool delete_node(int ind);
    bool reverse_node();
    void output();
};
