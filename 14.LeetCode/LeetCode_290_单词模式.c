/*************************************************************************
	> File Name: LeetCode_290_单词模式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月12日 星期六 20时54分34秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const int SIZE = 26;
const char BASE = 'a';

typedef struct Node {
    int flag;
    struct Node **childs;
}*Trie, TrieNode;

TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < 26; i++) {
        p->childs[i] = NULL;
    }
    p->flag = 0;
    return p;
}

void insert(TrieNode *trie, char *str, int *ind, int *arr, int *num) {
    TrieNode *p = trie;
    for (int i = 0; str[i]; i++) {
        if (p->childs[str[i] - BASE] == NULL) {
            p->childs[str[i] - BASE] = new_node();
        }
        p = p->childs[str[i] - BASE];
    }
    if (p->flag == 0) {
        p->flag = *ind;
        arr[*num] = *ind;
        *ind += 1;
    } else {
        arr[*num] = p->flag;   
    }
   // printf("ind1 = %d %d\n", *ind, *num);
    *num += 1;
} 

bool wordPattern(char* pattern, char* str) {
    TrieNode *root1 = new_node();
    TrieNode *root2 = new_node();
    int ind1 = 1, ind2 = 1, len = strlen(pattern) > strlen(str) ? strlen(pattern) : strlen(str), len1 = strlen(pattern);
    int str_log[5000] = {0}, pattern_log[5000] = {0}, pat[26] = {0};
    char *temp;
    temp = strtok(str, " ");
    int n = 0, m = 0;
    while(temp) {
        insert(root1, temp, &ind1, str_log, &n);
        temp = strtok(NULL, " ");
    }
    for (int i = 0 ; i < len1; i++) {
        if (pat[pattern[i] - BASE] == 0) {
            pat[pattern[i] - BASE] = ind2;
            pattern_log[m] = ind2;
            ind2++;
        } else {
            pattern_log[m] = pat[pattern[i] - BASE];
        }
        m++;
    }
    //printf("%d\n", len);
    for (int i = 0; i < len; i++) {
       // printf("%d %d\n", str_log[i], pattern_log[i]);
        if (str_log[i] != pattern_log[i]) return false;
    }
    return true;
}

int main() {
 
    return 0;
}
