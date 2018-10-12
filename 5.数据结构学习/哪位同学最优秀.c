/*************************************************************************
	> File Name: 哪位同学最优秀.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 17时00分14秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} Node, *LinkedList;

Node *init(int value) {
	Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    return p;
} 

LinkedList insert (LinkedList head, Node *node, int index) {
    if(head == NULL) {
        if (index != 0) {
            return head;
        }
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
        return head;
    }
    return head;
}

LinkedList delete_node(LinkedList head, int index) {
	if (head == NULL) {
        //printf("failed\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
	if (index == 0) {
        head = head->next;
        free(current_node);
        //printf("success\n");
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
        //printf("success\n");
        return head;
    }
    //printf("failed\n");
    return head;
}

int get_value(LinkedList head, int index) {
    Node *current_node = head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    printf("%d\n", current_node->data);
}

void output(LinkedList head) {
    if(head == NULL) return ;
    Node *current_node = head;
    printf("%d", current_node->data);
    current_node = current_node->next;
    while(current_node != NULL) {
        printf(" %d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return ;
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
    int n, m;
    int length = 0;
    LinkedList List_a = NULL;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        Node *node = init(i + 1);
        List_a = insert(List_a, node, i);
    }
    for(int i = 0; i < m; i++) {
		int temp;
        scanf("%d", &temp);
        Node *node = init(temp);
        List_a = delete_node(List_a, temp - 1);
    }
    //output(List_a);
    int index = (n - m) >> 1;
    get_value(List_a, index);
}
