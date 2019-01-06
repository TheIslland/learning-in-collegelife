/*************************************************************************
	> File Name: 二差查找树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月06日 星期日 19时32分48秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild, *father;
}Node;

Node* init(int value, Node *node) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->lchild = NULL;
    p->rchild = NULL;
    p->father = node;
    return p;
}

Node* insert(Node *node, int value) {
    if (node == NULL) {
		node = init(value, NULL);
    } else if (value > node->data) {
		if (node->rchild == NULL) {
			node->rchild = init(value, node);
        } else {
			node->rchild = insert(node->rchild, value);
        }
    } else if (value < node->data){
		if (node->lchild == NULL) {
			node->lchild = init(value, node);
        } else {
			node->lchild = insert(node->lchild, value);
        }
    }
    return node;
 }

Node* search(Node *node, int value) {
	if (node == NULL || node->data == value)  return node;
    if (value > node->data) {
		if (node->rchild == NULL) {
			return NULL;
        } else {
			return search(node->rchild, value);
        }
    } else {
		if (node->lchild == NULL) {
			return NULL;
        } else {
			return search(node->lchild, value);
        }
    }
}

void output(Node *node) {
    if (node == NULL) return ;
    output(node->lchild);
    printf("%d ", node->data);
    output(node->rchild);
}

void clear(Node *node) {
    if (node != NULL) {
        if (node->lchild != NULL) {
            clear(node->lchild);
        }
        if (node->rchild != NULL) {
            clear(node->rchild);
        }
        free(node);
    }
}

int main() {
    Node *binarytree = NULL;
    init(100, binarytree);
    int n, temp, value;
    scanf("%d", &n);
    for (int i = 0 ; i < n; i++) {
		scanf("%d", &temp);
        binarytree = insert(binarytree, temp);
    }
    scanf("%d", &value);
    if (search(binarytree, value) == NULL) {
		printf("search failed!\n");
    } else {
		printf("search success!\n");
    }
    output(binarytree);
    clear(binarytree);
    return 0;
}
