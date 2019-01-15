/*************************************************************************
	> File Name: 古老的打印机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月15日 星期二 18时42分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26
#define BASE 'a'

int MAX = 0;
typedef struct Node {
    int flag, count;
    struct Node *childs[SIZE];
}TrieNode, *Trie;

TrieNode *Get_Node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->flag = 0;
    p->count = 0;
    return p;
}

void insert(TrieNode *root, char *str) {
    TrieNode *p = root;
    int ind = str[0] - BASE, cnt = 0;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        if (p->childs[len] == NULL) {
            p->childs[len] = Get_Node();
            root->childs[ind]->flag += 1;
        }
        p = p->childs[len];
        cnt++;
    }
    root->childs[ind]->count += 1;
    if (cnt > MAX) MAX = cnt;
}

void clear(TrieNode *root) {
	if (root == NULL) return ;
    for (int i = 0; i < SIZE; i++) {
		clear(root->childs[i]);
    }
    free(root);
}

int aq_count(TrieNode *root) {
    int ans = 0, temp = -10;
    TrieNode *p = root;
    for (int i = 0; i < SIZE; i++) {
        if (p->childs[i] != NULL) {
           if (p->childs[i]->flag > temp) temp = p->childs[i]->flag;
            ans += p->childs[i]->flag * 2 + p->childs[i]->count;
        } 
    }
    return ans;
}
int main() {
    int n;
	while (scanf("%d", &n) != EOF){
		TrieNode *root = Get_Node();
    	int ans = 0;
    	char str[55];
    	for (int i = 0; i < n; i++) {
        	scanf("%s", str);
        	insert(root, str);
		}
    	ans = aq_count(root) - MAX;
    	printf("%d\n", ans);
    	MAX = 0;
    	clear(root);
    }
    return 0;
}
