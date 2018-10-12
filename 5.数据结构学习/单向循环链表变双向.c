/*************************************************************************
	> File Name: 单向循环链表变双向.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 17时58分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
	int data;
    struct LinkedList *next;
    struct LinkedList *prior;
} Node, *LinkedList;

Node *init(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prior = NULL;
    return node;
}

LinkedList insert(LinkedList head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        node->next = head;
        node->prior = head;
        //printf("1\n");
        return head;
    }
    Node *prior_node = head->next;
    if (index == 0) {
        node->next = head;
        head->prior = node;
        head->next = node;
        node->prior = head;
    //    printf("2\n");
        return head;
    }
    Node *current_node = head->next;
    int count = 0;
    while (current_node != head && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next->prior = node;
        current_node->next = node;
        node->prior = current_node;
      //  printf("3\n");
    }
    if (node == head->next) {
        head = node;
    }
    return head;
}

void output (LinkedList head, int m, int num) {
    Node *current_node = head;
    int count = 0;
    while (current_node->next != head) {
        if (current_node->data == m) break;
        current_node = current_node->next;
    }
    while (count < num) {
        printf("%d ", current_node->data);
        current_node = current_node->prior;
        count++;
    }
    //printf("%d\n", current_node->data);
    free(current_node);
}

int main() {
	int n, start;
    LinkedList List = NULL;
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        Node *node = init(temp);
        List = insert(List, node, i);
    }
    scanf("%d", &start);
    output (List, start, n);
	return 0;
}
