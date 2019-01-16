/*************************************************************************
	> File Name: 字符串统计.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月15日 星期二 20时04分05秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26
#define BASE 'a'
#define MAX_N 100005
#define MAX_LEN 2000
typedef struct TrieNode {
    int count;
    struct TrieNode **childs;
    struct TrieNode *fail;
}TrieNode, *Trie;

TrieNode *getNewTrieNode() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}

void clear(TrieNode *root) {
    if (root == NULL) return ;
    for (int i = 0; i < SIZE; i++) {
        clear(root->childs[i]);
    }
    free(root->childs);
    free(root);
    return ;
}

void insert(Trie root, char *str) {
    TrieNode *p = root;
    for (int i = 0; i < strlen(str); i++) {
        int len = str[i] - BASE;
        if (p->childs[len] == NULL) {
            p->childs[len] = getNewTrieNode();
        }
        p = p->childs[len];
    }
    p->count = 1;
}
void build_automaton(Trie root) {
    root->fail = root;
    TrieNode *q[MAX_LEN];
    int l = 0, r = 0;
    q[r++] = root;
    while (l < r) {
		TrieNode *now = q[l++];
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
                	if (iter->fail->childs[i] != NULL) {
						child->fail = iter->fail->childs[i];
                    } else {
                        child->fail = root;
                    }
                }
                q[r++] = child;
            }
        }
    }
}

void get_fail(Trie root) {
    root->fail = root;
    TrieNode *arr[MAX_LEN];
    int l = 0, r = 0;
    arr[r++] = root;
    while (l < r) {
        TrieNode *now = arr[l++];
        for (int i = 0; i < SIZE; i++) {
            if(now->childs[i] != NULL) {
                TrieNode *child = now->childs[i];
                if (now == root) {
                    child->fail = root;
                } else {
                    TrieNode *itor = now;
                    while (itor != root && itor->fail->childs[i] == NULL) {
                        itor = itor->fail;
                    }
                    if (itor->fail->childs[i] != NULL) {
                        child->fail = itor->fail->childs[i];
                    } else {
                        child->fail = root;
                    }
                }
                arr[r++] = child;
            }
        }
    }
}
/*
int match_count(Trie root, const char *buffer) {
    TrieNode *p = root;
    for (int i = 0; buffer[i]; i++) {
		while (p != root && p->childs[buffer[i] - BASE] == NULL) {
			p = p->fail;
        }
        p = p->childs[buffer[i] - BASE];
		if (p == NULL) {
			p = root;
        }
        TrieNode *iter = p;
        while (iter != root) {
            if (iter->count > 0) {
                iter->count += 1;
            }
            iter = iter->fail;
        }
    }
}*/
void match_count(Trie root, char *str) {
    TrieNode *p = root;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        while (p != root && p->childs[len] == NULL) {
            p = p->fail;
        }
        p = p->childs[len];
        if (p == NULL) {
            p = root;
        }
        TrieNode *iter = p;
        while (iter != root) {
            iter->count += 1;
            iter = iter->fail;
        }
    }
}

void print(Trie root, char *str, int *ind) {
    TrieNode *p = root;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        p = p->childs[len];
    }
    printf("%d: %d\n", *ind, p->count - 1);
}

int main() {
    int n;
    TrieNode *root = getNewTrieNode();
    char pattern[1005][22];
    char str[100005];
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", pattern[i]);
        insert(root, pattern[i]);
    }
    get_fail(root);
    scanf("%s", str);
    match_count(root, str);
    for (int j = 0; j < i; j++) {
        print(root, pattern[j], &j);   
    }
    return 0;
}
