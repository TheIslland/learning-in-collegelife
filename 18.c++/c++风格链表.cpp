/*************************************************************************
	> File Name: c++风格链表.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月06日 星期三 21时44分40秒
 ************************************************************************/
#include<iostream>

class Node {
public:
	int data;
    Node *next;
Node(int _data) {
    data = _data;
    next = NULL;
}
};

class LinkedList{
private:
    Node *head;
public:
LinkedList(){
    head = NULL;
}
~LinkedList() {
    Node *current_node = head;
    while (current_node != NULL) {
		Node *delete_node = current_node;
        current_node = current_node->next;
        delete delete_node;
    }
}
};
int main() {
	LinkedList linkedlist;
    return 0;
}
