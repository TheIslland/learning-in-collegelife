/*************************************************************************
	> File Name: 单链表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月29日 星期六 10时59分38秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node, * LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("ERROR\n");
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
    int count = 0;
    Node *current_node = head;
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
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return ;
}

LinkedList delete_node(LinkedList head, int index) {
    if(head == NULL) {
        printf("failed\n");
        return head;
    }
    int count = 0;
    Node *current_node = head;
    if (index == 0) {
        head = head->next;
        free(current_node);
        printf("success\n");
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
        printf("success\n");
        return head;
    }
    printf("failed\n");
    return head;
}

LinkedList reverse(LinkedList head) {
    if (head == NULL) {
        return head;
    }
    Node *current_node = head->next;
    Node *Next_node;
    head->next = NULL; 
    while (current_node != NULL) {
        Next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = Next_node;
    }
    return head;
}

void clear(LinkedList head) {
    if (head == NULL) {
        return ;
    }
    Node *current_node = head;
    while (head != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(current_node);
    }
    return ;
}

int main() {
    LinkedList linkedlist = NULL;
	int m, t;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
		scanf("%d", &t);
        if (t == 1) {
			int a, b;
            scanf("%d %d", &a, &b);
            Node *node = (Node *)malloc(sizeof(Node));
            node->data = b;
            node->next = NULL;
            linkedlist = insert(linkedlist, node, a);
        }
        if(t == 2) {
            output(linkedlist);
        }
        if(t == 3) {
			int a;
            scanf("%d", &a);
            linkedlist = delete_node(linkedlist, a);
        }
        if(t == 4) {
			linkedlist = reverse(linkedlist);
        }
    }
    return 0;
}
