/*************************************************************************
	> File Name: P1305_新二叉树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月05日 星期一 19时27分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *lchild, *rchild;
} Node;

Node *init(char value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->lchild = node->rchild = NULL;
}

void push(Node *root, char value[]) {
    if (!root) {
       return ; 
    }
    if (root->value == value[0]) {
        if (value[1] != '*') {
            root->lchild = init(value[1]);
        }
        if (value[2] != '*') {
            root->rchild = init(value[2]);
        }
    }
    push(root->lchild, value);
    push(root->rchild, value);
    return ;
}

void output(Node *root) {
    if (!root) return ;
    printf("%c", root->value);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    char a[5];
    Node *node = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        if (i == 0) {
            node = init(a[0]);
        }
        push(node, a);
    }
    output(node);
    return 0;
}
