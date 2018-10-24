/*************************************************************************
	> File Name: 神奇二叉树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月24日 星期三 19时15分36秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int *lchild, *rchild;
}Node ;

Node *init (int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}
//根据先序和中序建立原树
Node *build(char pre_str[], char in_str[], int len) {
	//建立当前节点ｐ
    Node *p = init(pre_str[0] - '0');
    //计算左节点高度
    int pos = strchr(in_str, pre_str[0]) - in_str;
    //当左节点不为叶子节点时
    if (pos > 0) {
        //当前节点的左节点为递归到叶子左节点
		p->lchild = build(pre_str + 1, in_str, pos);
    }
	//当右节点不为叶子节点为时
    if (len - pos - 1) {
        //当前节点右节点为递归到叶子右节点
		p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
	return p;
}
void postorder_1(Node *node) {
	if (node->lchild) {
		postorder_1(node->lchild);
    }
    if (node->rchild) {
		postorder_1(node->rchild);
    }
    printf("%c", node->data + '0');
}

void postorder_2(Node *node) {
    if (node->rchild) {
		postorder_2(node->rchild);
    }
    if (node->lchild) {
		postorder_2(node->lchild);
    }
    printf("%c", node->data + '0');
}

void clear(Node *node) {
    if (node->lchild) {
    	clear(node->lchild);    
	}
    if (node->rchild) {
        clear(node->rchild);
    }
    free(node);
}
int main() {
    char pre_str[52], in_str[52];
    scanf("%s", pre_str);
    scanf("%s", in_str);
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder_1(root);
    printf("\n");
    postorder_2(root);
    return ;
}

