/*************************************************************************
	> File Name: 链表的创建、插入、遍历操作的复习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月09日 星期日 14时45分28秒
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
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
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
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

void output(LinkedList head) {
	if (head == NULL) {
        return ;
    }
	Node *current_node = head;
    while (current_node != NULL) {
		printf("%d", current_node->data);
    	if(current_node->next != NULL) {
			printf(" ");
        }
        current_node = current_node->next;
	}
	printf("\n");	
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
	int n, p, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &q);
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = q;
        node->next = NULL;
        linkedlist = insert(linkedlist, node, p);
    }
    output(linkedlist);
    return 0;
}
