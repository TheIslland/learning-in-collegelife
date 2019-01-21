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
    int ans = 0;
    char str[10000];
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        int temp_len = insert(root, str);
    }
    printf("请查询:\n");
    char fd[1000];
    scanf("%s", fd);
    if (search(root, fd)) printf("%s 在字典中\n", fd);
    else printf("%s 不在字典中\n", fd);
    return 0;
}
