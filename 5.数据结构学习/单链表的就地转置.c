/*************************************************************************
	> File Name: 单链表的就地转置.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 17时06分41秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
        //  	printf("1.failed\n");
            return head;
        }
        head = node;
        //printf("1.success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        //printf("2.success\n");
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
        //printf("3.success\n");
        return head;
    }
    //printf("2.failed\n");
    return head;
}

Node *init(char value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
}
void output(LinkedList head) {
    if (head == NULL) {
        return;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%c", current_node->data);
    	if (current_node->next != NULL) printf(" ");
        current_node = current_node->next;
    }
    printf("\n");
}

LinkedList reverse(LinkedList head) {
	if (head == NULL) {
        return head;
    }
    Node *current_node, *next_node;
    current_node = head->next;
    head->next = NULL;
    while (current_node != NULL) {
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
	int m, num = 0;
    char t;
    scanf("%d", &m);
    for (int i = 0; i < 2 * m; i++) {
		scanf("%c", &t);
        if (i % 2) {
        	Node *node = init(t);
        	linkedlist = insert(linkedlist, node, num++);
        }
    }
    //output(linkedlist);
    linkedlist = reverse(linkedlist);
    output(linkedlist);
    return 0;
}
