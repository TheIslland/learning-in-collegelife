/*************************************************************************
	> File Name: double_arr_trie1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月09日 星期三 10时55分04秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
            cnt++;
        }
        p = p->next[str[i] - 'a'];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for(int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    return ;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0;
    while (!flag) {
        flag = 1;
        base += 1;
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
    if (node->flag == 0) trie[ind].check = -trie[ind].check;
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
        int del = str[i] - 'a';
        int check = abs(trie[trie[p].base + del].check);
        if (check - p) return 0;
        p = trie[p].base + del;
    }
    return trie[p].check < 0;
}

int main() {
 
    return 0;
}
