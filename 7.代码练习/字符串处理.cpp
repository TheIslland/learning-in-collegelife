/*************************************************************************
	> File Name: 字符串处理.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 09时51分09秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
const int N = 3000;
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

void insert(Trie trie, const char *pattern, int *ans) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(pattern); i++) {
		if (p->childs[pattern[i] - BASE] == NULL) {
			p->childs[pattern[i] - BASE] = new_node();
        }
        p = p->childs[pattern[i] - BASE];
    }
    	if(p->is_terminal) return ;
        *ans = *ans + 1;
        p->is_terminal = 1;
}

int main() {
    string str1,str2;
    while(getline(cin,str1)) {
	    TrieNode *root = new_node(); 
        if(str1 == "#") break;
        int ans = 0;
        istringstream stream(str1);
        while(stream>>str2) {
            const char *temp = str2.data();
            insert(root, temp, &ans);
        }
        cout << ans << endl;
        clear(root);
    } 
	return 0;
}
