/*************************************************************************
	> File Name: 有序集合的交运算.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 16时54分48秒
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

int List_length(LinkedList head) {
    Node *current_node = head;
    int count = 0;
    while(current_node != NULL) {
        current_node = current_node->next;
        count++;
    }
    return count;
}

int get_value(LinkedList head, int index) {
    Node *current_node = head;
    int count = 1;
    while(current_node != NULL && count < index) {
        current_node = current_node->next;
        count++;
    }
    if(count == index) return current_node->data;
    return -1;
}

void List_cmp(LinkedList head_a, int a_length, LinkedList head_b, int b_length, LinkedList head_c) {
    int i = 1, j = 1, k = 0;
    //int a_length = List_length(head_a);
    //int b_length = List_length(head_b);
    while ((i <= a_length) && (j <= b_length)) {
        int num_a = get_value(head_a, i);
        int num_b = get_value(head_b, j);
        if (num_a > num_b) {
            j++;
        } else if (num_a < num_b) {
            i++;
        } else {
            Node *node = init(num_a);
            insert(head_c, node, k);
            k++;
        }
    }
    //return head_c;
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
    LinkedList List_b = NULL;
    LinkedList List_c = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
		int temp;
        scanf("%d", &temp);
        Node *node = init(temp);
        List_a = insert(List_a, node, i);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
		int temp;
        scanf("%d", &temp);
        Node *node = init(temp);
        List_b = insert(List_b, node, i);
    }
    List_cmp(List_a, n, List_b, m, List_c);
    length = List_length(List_c);
    printf("%d\n", length);
    output(List_c);
    clear(List_a);
    clear(List_b);
    clear(List_c);
}

