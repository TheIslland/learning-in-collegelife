/*************************************************************************
	> File Name: 单链表操作.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月09日 星期日 10时40分33秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
    }
    return head;
}

Node *init(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = value;
    return node;
}

LinkedList insert_1(LinkedList head, int value) {
    Node ret, *p = &ret, *q = head;
    ret.next = head;
    while (q->data < value && q != NULL) {
        p = p->next;
        q = q->next;
    }
    Node *node = init(value);
    node->next = q;
    p->next = node;
    return ret.next;
}

void output(LinkedList head) {
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList delete_node(LinkedList head, int index) {
    if (head == NULL) {
        return head;
    }
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head = head->next;
        free(current_node);
        return head;
    }
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}

LinkedList erase(LinkedList head, int n) {
    if (head == NULL) {
        return head;
    } 
    Node *current_node = head;
    Node *next_node = head;
    int count = 1, index = 0;
    while (next_node->next != NULL) {
        next_node = next_node->next;
        count++;
    }
    while (current_node->next != NULL && index < count - n - 1) {
        current_node = current_node->next;
        index++;
    }
    if (count == n) {
        Node *delete_node = current_node;
        head = head->next;
        free(delete_node);
    }
    if (index == count - n - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        //printf("%d %d %d\n", count, index, n);
        free(delete_node);
    }
    return head;
}

LinkedList reverse (LinkedList head) {
    if (head == NULL) {
        return head;
    }
    Node *next_node,*current_node;
    current_node = head->next;
    head->next = NULL;
	while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    for (int i = 1; i <= 10; i++) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, i - 1);
    }
    output(linkedlist);
   // linkedlist = erase(linkedlist, 10);
    linkedlist = insert_1(linkedlist, 8);
    output(linkedlist);
   /* linkedlist = delete_node(linkedlist, 3);
    output(linkedlist);
    linkedlist = reverse(linkedlist);
    output(linkedlist);*/
    clear(linkedlist);
    return 0;
}
