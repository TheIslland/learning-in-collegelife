/*************************************************************************
	> File Name: P1305_新二叉树1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月22日 星期二 14时31分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BASE_CNT 26
#define BASE '0'

typedef struct Node {
    int flag;
    struct Node **next;
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = (Node **)malloc(sizeof(Node *) * 2);
    for (int i = 0; i < 2; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert(Node *node, const char *str) {
     Node *p = node;
    int cnt = 1;
    int len = strlen(str);
    for (int i = 0; str[i]; i += 3) {
        for (int j = 0; j < 3; j++) {
            int num = str[i + j];
            while (num) {
                int x = num & 1;
                if (p->next[x] == NULL) {
                    p->next[x] = getNewNode();
                }
                p = p->next[x];
                num /= 2;
            }
        }
    }
    p->flag = 1;
}

int search(Node *node, const char *str) {
    Node *p = node;
    int len = strlen(str);
    for (int i = 0; str[i]; i += 3) {
        for (int j = 0; j < 3; j++) {
            int num = str[i + j];
            while (num) {
                int x = num & 1;
                if (p->next[x] == NULL) {
                    return 0;
                }
                p = p->next[x];
                num /= 2;
            }
        }
    }
    return p->flag;
}

int main() {
    Node *root = getNewNode();
    
    return 0;
}
