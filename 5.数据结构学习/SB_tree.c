/*************************************************************************
	> File Name: SB_tree.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月25日 星期五 11时32分31秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct SBTNode {
    int data, size;
    struct SBTNode *lchild, *rchild, *father;
} SBTNode;

SBTNode* init(int init_data, int init_size, SBTNode *init_father);

SBTNode *NIL;

void init_NIL() {
    NIL = (SBTNode *)malloc(sizeof(SBTNode));
    NIL->data = 0;
    NIL->size = 0;
    NIL->lchild = NIL;
    NIL->rchild = NIL;
    NIL->father = NULL;
}

SBTNode* init(int init_data, int init_size, SBTNode *init_father) {
    SBTNode *node = (SBTNode *)malloc(sizeof(SBTNode));
    node->data = init_data;
    node->size = init_size;
    node->lchild = NIL;
    node->rchild = NIL;
    node->father = init_father;
    return node;
}

SBTNode* left_rotate(SBTNode *node) {
    SBTNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild->father = node;
    temp->lchild = node;
    temp->father = node->father;
    node->father = temp;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
	return temp;
}

SBTNode* right_rotate(SBTNode *node) {
}

SBTNode* maintain(SBTNode *node, int flag) {
}

SBTNode* insert(SBTNode *node, int value) {
    node->size++;
    if (value > node->data) {
        if (node->rchild == NIL) {
            node->rchild = init(value, 1, node);
        } else {
            node->rchild = insert(node->rchild, value);
        }
    } else {
        if (node->lchild == NIL) {
            node->lchild = init(value, 1, node);
        } else {
            node->lchild = insert(node->lchild, value);
        }
    }
    return maintain(node, value > node->data);
}

SBTNode* search(SBTNode *node, int value) {
    if (node == NIL || node->data == value) {
        return node;
    } else if (value > node->data) {
        if (node->rchild == NIL) {
            return NIL;
        } else {
            return search(node->rchild, value);
        }
    } else {
        if (node->lchild == NIL) {
            return NIL;
        } else {
            return search(node->lchild, value);
        }
    }
}

SBTNode* insert_node(SBTNode *node, int value) {
    if (node == NULL) {
        node = init(value, 1, NULL);
        return node;
    }
    if (search(node, value) != NIL) {
        return node;
    }
    return insert(node, value);
}


SBTNode* predecessor(SBTNode *node) {
    SBTNode *temp = node->lchild;
    while (temp != NIL && temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}

SBTNode* successor(SBTNode *node) {
    SBTNode *temp = node->rchild;
    while (temp != NIL && temp->lchild != NIL) {
        temp = temp->lchild;
    }
    return temp;
}

void remove_node(SBTNode *delete_node) {
    SBTNode *temp = NIL;
    if (delete_node->lchild != NIL) {
        temp = delete_node->lchild;
        temp->father = delete_node->father;
        delete_node->lchild = NIL;
    }
    if (delete_node->rchild != NIL) {
        temp = delete_node->rchild;
        temp->father = delete_node->father;
        delete_node->rchild = NIL;
    }
    if (delete_node->father->lchild == delete_node) {
        delete_node->father->lchild = temp;
    } else {
        delete_node->father->rchild = temp;
    }
    temp = delete_node;
    while (temp != NULL) {
        temp->size--;
        temp = temp->father;
    }
    delete_node->lchild = NIL;
    delete_node->rchild = NIL;
    free(delete_node);
}

int delete_tree(SBTNode *node, int value) {
    SBTNode *delete_node, *current_node;
    current_node = search(node, value);
    if (current_node == NIL) {
        return ERROR;
    }
    if (current_node->lchild != NIL) {
        delete_node = predecessor(current_node);
    } else if (current_node->rchild != NIL) {
        delete_node = successor(current_node);
    } else {
        delete_node = current_node;
    }
    current_node->data = delete_node->data;
    remove_node(delete_node);
    return OK;
}

void clear(SBTNode *node) {
    if (node != NIL) {
        if (node->lchild != NIL) {
            clear(node->lchild);
        }
        if (node->rchild != NIL) {
            clear(node->rchild);
        }
        free(node);
    }
}

int main() {
    return 0;
}
