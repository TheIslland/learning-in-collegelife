/*************************************************************************
	> File Name: 深度建立ac自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 09时44分31秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 'a'
#define SIZE 26
#define MAX_N 100000
typedef struct Node {
    int flag;
    struct Node **childs;
    struct Node *fail, *father;
}Node, *Trie;

Node *new_node(Node *father) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->childs = (Node **)malloc(sizeof(Node *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->father = father;
    p->flag = 0;
    return p;
}

void clear(Trie node) {
    if (node == NULL) return ;
    for (int i = 0; i < SIZE; i++) clear(node->childs[i]);
    free(node->childs);
    free(node);
    return ;
}

void intsert(Trie root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        if (p->childs[len] == NULL) {
            p->childs[len] = new_node(p);
        }
        p = p->childs[len];
    }
    p->flag = 1;
    return ;
}

void build_ac(Node *node) {
    if (node == NULL) return; 
    if (node->fail == NULL) build_ac(node->father); 
    for (int i = 0; i < SIZE; i++) {
        if (node->childs[i] == NULL) continue;
        if (node->childs[i]->fail) continue;
        Node *p = node->fail, *pre_p;
        while (p && p->childs[i] == NULL) {
            if (p->fail == NULL) build_ac(p->father);
            pre_p = p;
            p = p->fail;
            
        }
        if (p == NULL) p = pre_p;
        else p = p->childs[i];
        node->childs[i]->fail = p;
        build_ac(node->childs[i]);
    }
    return ;
}

int main() {
    Node *trie = new_node(NULL); 
    return 0;
}
