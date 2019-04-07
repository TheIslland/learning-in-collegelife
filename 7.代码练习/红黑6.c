/*************************************************************************
	> File Name: 红黑6.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月22日 星期五 10时08分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef int color_t;

typedef struct RBTNode {
    int key;
    color_t color;
    struct RBTNode *lchild, *rchild;
} RBTNode;

RBTNode *NIL;

__attribute__((constructor))
void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->key = -1;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

int has_red_child(RBTNode *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

RBTNode *insert_maintain(RBTNode *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
    } else if (root->lchild->color == RED && has_red_child(root->lchild)) {
        
    } else if (root->rchild->color == RED && has_red_child(root->rchild)) {

    } else {
        return root;
    }
}

RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    else if (root->key > key) {
        root->lchild = __insert(root->lchild, key);
    } else {
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root);
}

RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

int main() {
 
    return 0;
}
