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
#include<ctime>
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
    Node() { next = NULL; }
};

template <typename Type> class LinkedList {
   private:
    Node<Type> head;
    int length;
   public:
    LinkedList() {
        this->head = NULL;
        this->length = 0;
    }
    ~LinkedList() {
        Node<Type> *current_node = this->head.next;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (index < 0 || index > this->length) return false;
        if (index == 0) {
            node->next = this->head.next;
            this->head.next = node;
            this->length++;
            return true;
        }
        Node<Type> *current_node = &head;
        while (index--) current_node = current_node->next;
        node->next = current_node->next;
        current_node->next = node;
        this->length++;
        return true;
    }
    void output() {
        if (head == NULL) return;
        Node<Type> *current_node = head.next;
        while (current_node) {
            cout << current_node->data << endl;
            current_node = current_node->next;
        }
        return;
    }
    bool delete_node(int index) {
        if (index < 0 || index > length) return false;
        Node<Type> *current_node = head, *delete_node;
        while (index--) current_node = current_node->next;
        delete_node = current_node->next;
        current_node->next = delete_node->next;
        delete delete_node;
        return true;
    }
    bool reverse() {
        if (head == NULL) return false;
        Node<Type> current_node = head->next;
        head.next = NULL;
        while (current_node != NULL) {
            insert(current_node, 0);
        }
        return true;
    }
};


int main() {
    int m, t;
    cin >> m;
    LinkedList<int> *l = new LinkedList<int>();
    while (m--) {
        cin >> t;
        switch(t) {
            case 1: {
                int a, b;
                cin >> a >> b;
                Node<int> v1(b);
                Node<int> *c = &v1;
                l->insert(c, a);
            } break;
            case 2: {

            } break;
            case 3:
            case 4:;
        }
    }
    return 0;
}
