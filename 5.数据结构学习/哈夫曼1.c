/*************************************************************************
	> File Name: 哈夫曼1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月01日 星期四 17时46分29秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->freq = freq;
    node->lchild = node->rchild = NULL;
    return node;
}

int main() {
 
    return 0;
}
