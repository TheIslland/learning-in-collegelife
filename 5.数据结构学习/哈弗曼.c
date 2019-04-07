/*************************************************************************
	> File Name: 哈弗曼.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月29日 星期一 18时17分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void swap_node (Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return ;
} 
Node *build_node(Node **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            if (arr[j]->freq <= arr[n - i - 1]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            }
            if (arr[j]->freq <= arr[n - i -2]->freq) {
                swap_node(arr + j, arr + n - i - 2);
            }
        }
        Node *temp = getNewNode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_node(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_node(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_node(root->rchild, code, k + 1, buff);
    return ;
}
int main() {
    int n ; 
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0 ; i < n; i++) {
        char key[20];
        int freq;
        scanf("%s%d", key, &freq);;
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_node(arr, n);
    char code[256][20] = {0}, buff[20];
    extract_node(root, code, 0, buff);
    for (int j = 0; j < 256; j++) {
        if (code[j][0] == 0) continue;
        printf("%c : %s\n", j, code[j]);
    }
    return 0;
}
