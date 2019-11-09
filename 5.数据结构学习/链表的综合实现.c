/*************************************************************************
	> File Name: 链表的综合实现.c
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Nov  8 20:16:48 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node head;
    int length;
} List;

Node *init_node(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *p = (List *)malloc(sizeof(List));
    p->head.next = NULL;
    p->length = 0;
    return p;
}

int insert(List *l, int index, int val) {
    if (index < 0 || index > l->length) return 0;
    if (l == NULL) return 0;
    Node *p = &(l->head), *node = init_node(val);
    while (index--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int index) {
    if (l == NULL) return 0;
    if (index < 0 || index >= l->length) return 0;
    Node *p = &(l->head), *q;
    while (index--) p = p->next;
    q = p->next;
    p = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void output(List *l) {
    if (l == NULL) return ;
    printf("list （%d) = [", l->length);
    for (Node *p = l->head.next; p; p = p->next){
        printf("%d-->", p->val);
    }
    printf("\n");
    return ;
}
void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_list(List *list) {
    if (list == NULL) return ;
    Node *p = list->head.next, *q;
    while (p != NULL) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(list);
    return ;
}


int main() {
    srand(time(0));
    List *l = init_list();
    #define max_op 20
    int index, val, op;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        index = rand() % (l->length + 3) - 2;
        val = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to the List = %d", 
                      val, index ,insert(l, index, val));
                output(l);
            } break;
            case 3: {
                printf("earse items at %d from list = %d\n", index, erase(l, index));
            } break;

        }
        
    }
    return 0;
}
