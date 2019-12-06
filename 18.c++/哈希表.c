/*************************************************************************
	> File Name: 哈希表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月06日 星期二 19时49分56秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtale(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}
int APHash() {

}

int ZobristHash() {
    
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0;str[i]; i++) hash = hash * seed + str[i];
    return hash & 0xfffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1; 
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}
void clear_node(Node *node) {
    if (!node) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (!h) return ;
    for (int i = 0; i < h->size; i++) 
        clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    char str[100];
    HashTable *h = init_hashtale(100);
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 0: {
                printf("insert %s to HashTable\n", str);
                insert (h, str);
            } break;
            case 1: {
                printf("search %s result = %d\n", str, search(h,str));
            }
        }
    }
    return 0;
}
