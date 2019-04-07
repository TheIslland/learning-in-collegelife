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

typedef struct TrieNode {
    int flag;
    struct TrieNode **next;
} TrieNode;

TrieNode *getNewTrieNode() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->next = (TrieNode **)malloc(sizeof(TrieNode *) * 2);
    for (int i = 0; i < 2; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int TrieNode_insert(TrieNode *TrieNode, const char *str) {
     TrieNode *p = TrieNode;
    int len = strlen(str);
    for (int i = 0; str[i]; i += 3) {
        for (int j = 0; j < 3; j++) {
            int num = str[i + j];
            while (num) {
                int x = num & 1;
                if (p->next[x] == NULL) {
                    p->next[x] = getNewTrieNode();
                }
                p = p->next[x];
                num /= 2;
            }
        }
        p->flag += 1;
    }
}

int TrieNode_search(TrieNode *TrieNode, const char *str) {
    TrieNode *p = TrieNode;
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
    TrieNode *root = getNewTrieNode();
    char str[1000][30];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        int temp_len = TrieNode_insert(root, str[i]);
    }
    return 0;
}
