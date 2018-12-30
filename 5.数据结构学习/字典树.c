/*************************************************************************
	> File Name: 字典树.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月30日 星期日 20时39分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

/*
void insert(Node *node, const char *str) {
     Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) p->next[str[i] - BASE] = getNewNode();
    }
    p->flag = 1;
    return ;
}*/

int insert(Node *node, const char *str) {
     Node *p = node;
    int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) 
            p->next[str[i] - BASE] = getNewNode();
        p = p->next[str[i] - BASE];
        cnt += p->flag;
    }
    p->flag = 1;
    return cnt;
}

int search(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        p = p->next[str[i] - BASE];
    }
    return p->flag;
}

int main() {
    Node *root = getNewNode();
    int ans = 0;
    char str[10000];
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        int temp_len = insert(root, str);
        if (temp_len > ans) ans = temp_len;
    }
    printf("%d\n", ans);
    return 0;
}
