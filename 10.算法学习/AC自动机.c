/*************************************************************************
	> File Name: AC自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月12日 星期六 18时59分13秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_N = 101000;

typedef struct TrieNode {
    int count;
    struct TrieNode **childs;
    struct TrieNode *fail;
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

void clear(Trie p) {
	if (p != NULL) {
    	for (int i = 0; i > SIZE; i++) {
			if (p->childs[i] != NULL) {
				clear(p->childs[i]);
            } 
    	}
        free(p->childs);
        free(p);
    }
}

void insert(Trie root, char *str) {
    TrieNode *p = root;
    for (int i = 0; str[i]; i++) {
		if (p->childs[str[i] - BASE] == NULL) {
            p->childs[str[i] - BASE] = new_node();
        }
        p = p->childs[str[i] - BASE];
    }
    p->count++;
}

void build_automaton(Trie root) {
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

int match_count(Trie root, const char *str) {
    TrieNode *p = root;
    int ans_count = 0;
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
            //if (iter->count != 0) printf("%d %c\n", iter->count, str[i]);
			ans_count += iter->count;
        //    iter->count = 0;
            iter = iter->fail;
        }
    }
    return ans_count;
}

int main() {
    TrieNode *root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char temp[1000];
        scanf("%s", temp);
        insert(root, temp);
    }
    build_automaton(root);
    char str[200000];
    scanf("%s", str);
    int ans = match_count(root, str);
    printf("%d", ans);
    return 0;
}
