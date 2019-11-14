/************************************************************
    File Name : LinkedList.cpp
    Author: TheIslland
    Mail: voidland@163.com, 861436930@qq.com
    Created Time: 2019-11-13 星期三 21:00:49
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

template <typename Type>
class Node {
   public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
    Node() { next = NULL; }
};

template <typename Type>
class LinkedList {
   private:
    Node<Type> head;
    int length = 0;

   public:
    LinkedList() {
        head = Node<Type>();
        length = 0;
    }
    ~LinkedList() {
        Node<Type> *p = head.next;
        while (p->next) {
            Node<Type> *delete_node = p;
            p = p->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int ind) {
        if (ind < 0 || ind > length) return false;
        Node<Type> *current_node = &head;
        while (ind--) current_node = current_node->next;
        node->next = current_node->next;
        current_node->next = node;
        length++;
        return true;
    }
    bool delete_node(int ind) {
        if (head.next == NULL || ind < 0 || ind >= length) return false;
        Node<Type> *current_node = &head, *del;
        while (ind--) current_node = current_node->next;
        del = current_node->next;
        current_node->next = del->next;
        delete del;
        length--;
        return true;
    }
    bool reverse_node() {
        if (head.next == NULL) return false;
        Node<Type> *p = head.next, *q;
        head.next = NULL;
        while (p) {
            q = p->next;
            p->next = head.next;
            head.next = p;
            p = q;
        }
        return true;
    }
    void output() {
        if (head.next == NULL) {
            cout << "The ListNode is empty;" << endl;
        }
        cout << "The ListNode is = [ ";
        Node<Type> *current_node = head.next;
        while (current_node) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << "]" << endl;
    }
};
