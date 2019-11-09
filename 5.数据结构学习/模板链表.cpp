/*************************************************************************
	> File Name: 模板链表.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  8 18:56:26 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
template <typename Type> class Node{
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};

template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (int index == 0) {
                head = node;
                return true;
            }
            return false;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type>  *current_node = head;
        int count = 0;
        while 
    }
}

int main() {
    return 0;
}
