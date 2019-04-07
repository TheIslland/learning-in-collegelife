/*************************************************************************
	> File Name: 字典树的复习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月05日 星期六 16时31分47秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100010;
const int SIZE = 26;
const char BASE = 'a';

typedef struct TrieNode {
	int is_terminal;
    struct TrieNode **childs;
} TrieNode, *Trie;



TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode*) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->is_terminal = 0;
    return p;
}

void clear(Trie p) {
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

void insert(Trie trie, char *pattern, int *ans) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(pattern); i++) {
		if (p->childs[pattern[i] - BASE] == NULL) {
			p->childs[pattern[i] - BASE] = new_node();
        }
        p = p->childs[pattern[i] - BASE];
    	if(p->is_terminal) continue;
        *ans = *ans + 1;
        p->is_terminal = 1;
    }
}

int main() {
    char buffer[N];
    int ans = 0;
    scanf("%s", buffer);
    TrieNode *trie = new_node();
    for (int i = 0; i < strlen(buffer); i++) {
		insert(trie, buffer + i, &ans);
    }
	printf("%d", ans);
    return 0;
}
