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
    int data, size; //节点的值与当前节点下节点个数
    struct SBTNode *lchild, *rchild, *father; //指针指向，左孩子，右孩子，和父亲节点
}SBTNode;

SBTNode* init(int init_data, int init_size, SBTNode *init_father); //初始化ＳＢ节点函数，参数为节点值，节点个数，和父节点

SBTNode *NIL; //虚拟叶子节点

//虚拟节点初始化
void init_NIL() {
    NIL = (SBTNode *)malloc(sizeof(SBTNode));
    NIL->data = 0;
    NIL->size = 0;
    NIL->lchild = NIL;
    NIL->rchild = NIL;
    NIL->father = NULL;
}

//初始化ＳＢ节点
SBTNode* init(int init_data, int init_size, SBTNode *init_father) {
    SBTNode *node = (SBTNode *)malloc(sizeof(SBTNode));
    node->data = init_data;
    node->size = init_size;
    node->lchild = NIL;
    node->rchild = NIL;
    node->father = init_father;
    return node;
}

//左旋操作
SBTNode* left_rotate(SBTNode *node) {
    SBTNode *temp = node->rchild; //声明ｔｅｍｐ节点指向旋转节点的右子树根节点
    node->rchild = temp->lchild; //将ｔｅｍｐ节点的左子树转化为原根节点的右子树
    temp->lchild->father = node; //ｔｅｍｐ的左子树的父亲节点初始化为原根节点
    temp->lchild = node; //ｔｅｍｐ节点的左子树转化为原根节点
    temp->father = node->father; //ｔｅｍｐ节点的父亲节点初始化化为原根节点的父亲节点
    node->father = temp; //原根节点的父亲节点为ｔｅｍｐ节点
    temp->size = node->size; //ｔｅｍｐ节点的节点数初始化为原根节点的节点数
    node->size = node->lchild->size + node->rchild->size + 1; //原根节点的节点数的更新为其下左右节点数和加一
    return temp; //返回现在根节点
}

//右旋操作
SBTNode* right_rotate(SBTNode *node) {
    SBTNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild->father = node;
    temp->rchild = node;
    temp->father = node->father;
    node->father = temp;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
    return temp;
}

//节点平衡操作
SBTNode* maintain(SBTNode *node, int flag) {
	if (flag == 0) {
			if (node->lchild->lchild->size > node->rchild->size) {
			node = right_rotate(node);
        } else if (node->lchild->rchild->size > node->rchild->size){
			node->lchild = left_rotate(node->lchild);
            node = right_rotate(node);
        } else {
			return node;
            }
    } else {
		if (node->rchild->rchild->size > node->lchild->size) {
			node = left_rotate(node);
        } else if (node->rchild->lchild->size > node->lchild->size) {
			node->rchild = right_rotate(node->rchild);
            node = left_rotate(node);
        } else {
			return node;
        }
    }
    node->lchild = maintain(node->lchild, 0);
    node->rchild = maintain(node->rchild, 1);
	node = maintain(node, 0);
    node = maintain(node, 1);
    return node;
}

//插入操作
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

//查找操纵
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

//插入操作
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

//返回前驱
SBTNode* predecessor(SBTNode *node) {
    SBTNode *temp = node->lchild;
    while (temp != NIL && temp->rchild != NIL) {
        temp = temp->rchild;
    }
    return temp;
}

//返回后继
SBTNode* successor(SBTNode *node) {
    SBTNode *temp = node->rchild;
    while (temp != NIL && temp->lchild != NIL) {
        temp = temp->lchild;
    }
    return temp;
}

//删除操作
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

//
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

//
int select(SBTNode *node, int k) {
    int rank = node->lchild->size + 1;
    if (rank == k) {
        return node->data;
    } else if (k < rank) {
        return select(node->lchild, k);
    } else {
        return select(node->rchild, k - rank);
    }
}

//
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
    init_NIL();
    SBTNode *binarytree = NULL;
    int arr[10] = { 8, 9, 10, 3, 2, 1, 6, 4, 7, 5 };
    for (int i = 0; i < 10; i++) {
        binarytree = insert_node(binarytree, arr[i]);
    }
    int value;
    scanf("%d", &value);
    if (search(binarytree, value) != NIL) {
        printf("search success!\n");
    } else {
        printf("search failed!\n");
    }    
    scanf("%d", &value);
    if (delete_tree(binarytree, value)) {
        printf("delete success!\n");
    } else {
        printf("delete failed!\n");
    }
    clear(binarytree);
    return 0;
}
