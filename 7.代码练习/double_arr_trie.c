/*************************************************************************
	> File Name: double_arr_trie.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月08日 星期二 16时49分16秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

typedef struct DATNode {
    int base, check;
} DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    return ;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - BASE];
    }
    node->flag = 1;
    return cnt;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0;
    while (!flag) {
        base += 1;
        flag = 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

void Transform(Node *node, DATNode *trie, int ind) {
    if (node->next[ind]->flag == 1) trie[ind].check = -trie[ind].check;
    trie[ind].base = getBase(node, trie);
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1; 
    for (int i = 0; str[i]; i++) {
        int delete = str[i] - 'a';
        int check = abs(trie[trie[p].base + delete].check);
        if (check - p == 0) return 0;
        p = trie[p].base + delete;
    }
    return trie[p].check < 0;
}
int main() {
	int n, cnt = 1;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }        
    return 0;
}
