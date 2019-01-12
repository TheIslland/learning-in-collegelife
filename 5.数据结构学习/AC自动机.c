/*************************************************************************
	> File Name: AC自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月12日 星期六 19时01分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;
const int MAX_N = 100000;
const char BASE = 'a';

typedef struct Node {
    int count;
    struct Node **childs;
    struct Node *fail;
}*Trie, TrieNode;

TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0;i < BASE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->cout = 0;
    return p;
}

void clear(Trie root) {
    for (int i = 0; i < SIZE; i++) {
        if (root->childs[i] == NULL) {
            clear(root->childs[i]);
        }
        free(root->childs);
        free(root);
    }
}

void insert(Trie root, char *str) {
    TrieNode *p = root;
    for (int i = 0; i < SIZE; i++) {
        if (p->childs[str[i] - BASE] == NULL) {
            p->chlids[str[i] - BASE] = new_node();
        }
        p = p->childs[str[i] - BASE];
    }
    p->count++;
}

void build_automation(Trie root) {
    root->fail = root;
    TrieNode *arr[MAX_N];
    int l = 0, r = 0;
    arr[r++] = root;
    while (l < r) {
        TrieNode *now = arr[l++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] != NULL) {
                TrieNode *child = now->childs[i];
                if (now == root) {
                    child->fail = root;
                } else {
                    TrieNode *iter = now;
                    while (iter != root && iter->fail->childs[i] == NULL) {
                        iter = iter->fail;
                    }
                    if (iter->fail->chlids[i] != NULL) {
                        child->fail = iter->fail->childs[i];
                    }
                }
                arr[r++] = child;
            }
        }
    }
}

int match_count(TrieNode *root, const char *str) {
    TrieNode *p = root;
    int total_count = 0;
    for (int i = 0; str[i]; i++) {
        while (p != root && p->childs[str[i] - BASE] == NULL) {
            p = p->fail;
        }
        p = p->childs[str[i] - BASE];
        if (p == NULL) {
            p = root;
        }
        TrieNode *iter = p;
        while (iter != root) {
            total_count += iter->chlids[i];
            iter = iter->fail;
        }
    }
    return total_count;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[MAX_LEN];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automaton(root);
    char str_buffer[MAX_LEN];
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    clear(root);
    return 0;
}
