/************************************************************
    File Name : LinkedList.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-13 星期三 21:00:49
************************************************************/
#include "LinkedList.h"
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

Node::Node(int val) {
    data = val;
    next = NULL;
}
Node::Node() { next = NULL; }

LinkedList::LinkedList() {
    head = Node();
    length = 0;
}
LinkedList::~LinkedList() {
    Node *p = head.next;
    while (p->next) {
        Node *delete_node = p;
        p = p->next;
        delete delete_node;
    }
}
bool LinkedList::insert(Node *node, int ind) {
    if (ind < 0 || ind > length) return false;
    Node *current_node = &head;
    while (ind--) current_node = current_node->next;
    node->next = current_node->next;
    current_node->next = node;
    length++;
    return true;
}
bool LinkedList::delete_node(int ind) {
    if (head.next == NULL || ind < 0 || ind >= length) return false;
    Node *current_node = &head, *del;
    while (ind--) current_node = current_node->next;
    del = current_node->next;
    current_node->next = del->next;
    delete del;
    length--;
    return true;
}
bool LinkedList::reverse_node() {
    if (head.next == NULL) return false;
    Node *p = head.next, *q;
    head.next = NULL;
    while (p) {
        q = p->next;
        p->next = head.next;
        head.next = p;
        p = q;
    }
    return true;
}
void LinkedList::output() {
    if (head.next == NULL) {
        cout << "The ListNode is empty;" << endl;
    }
    cout << "The ListNode is = [ ";
    Node *current_node = head.next;
    while (current_node) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << "]" << endl;
}
