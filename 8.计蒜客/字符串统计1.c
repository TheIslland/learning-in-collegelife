/*************************************************************************
	> File Name: 字符串统计1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 18时57分10秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 100500;
const int MAX_LEN = 2000;

typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode* fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}

void clear(TrieNode *p) {
    if (p != NULL) {
        for (int i = 0; i < SIZE; i++) {
            if (p->childs[i] != NULL) {
                clear(p->childs[i]);
            }
        }
        free(p->childs);
        free(p);
    }
}

void insert(Trie trie, char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count = 1;
}

void build_automaton(Trie root) {
    root->fail = root;
    TrieNode *q[MAX_SIZE];
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
    TrieNode *root = new_node();
    char pattern[1005][22];
    char str[100005];
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", pattern[i]);
        insert(root, pattern[i]);
    }
    build_automaton(root);
    scanf("%s", str);
    match_count(root, str);
    for (int j = 0; j < i; j++) {
        print(root, pattern[j], &j);   
    }
    return 0;
}
