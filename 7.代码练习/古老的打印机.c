/*************************************************************************
	> File Name: 古老的打印机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 10时12分40秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 26
#define BASE 'a'

int MAX = 0;
typedef struct Node {
    int count;
    struct Node *childs[SIZE];
}TrieNode, *Trie;

TrieNode *Get_Node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->count = 0;
    return p;
}

int insert(TrieNode *root, char *str) {
    TrieNode *p = root;
    int ind = str[0] - BASE, cnt = 0, a = 0;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        if (p->childs[len] == NULL) {
            p->childs[len] = Get_Node();
            a += 1;
        }
        p = p->childs[len];
        cnt++;
    }
    if (cnt > MAX) MAX = cnt;
	return a * 2 + 1;
}

void clear(TrieNode *root) {
	if (root == NULL) return ;
    for (int i = 0; i < SIZE; i++) {
		clear(root->childs[i]);
    }
    free(root);
}

int main() {
    int n;
	while (scanf("%d", &n) != EOF){
		TrieNode *root = Get_Node();
    	int ans = 0;
    	char str[55];
    	for (int i = 0; i < n; i++) {
        	scanf("%s", str);
        	ans += insert(root, str);
		}
    	ans -= MAX;
    	printf("%d\n", ans);
    	MAX = 0;
    	clear(root);
    }
    return 0;
}
