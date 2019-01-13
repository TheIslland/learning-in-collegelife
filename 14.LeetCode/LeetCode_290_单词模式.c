/*************************************************************************
	> File Name: LeetCode_290_单词模式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月12日 星期六 20时54分34秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//由题意可知，我们要分别获取两个串的模式串，经分析可知，我们可以对str字符串建字典树标记求得模式串，对于模式串我们可以采用标记数组模拟字典树来求得模式串
const int SIZE = 26; //字典树单位广度
const char BASE = 'a';

//字典树声明
typedef struct Node {
    int flag;
    struct Node **childs;
}*Trie, TrieNode;

//字典树新节点申请
TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < 26; i++) {
        p->childs[i] = NULL;
    }
    p->flag = 0;
    return p;
}

//字典树新节点插入，有两个传出参数ind表示字符串中的字符种类数,num表示记录到模式串数组中的第几位。arr表示记录模式串的数组
void insert(TrieNode *trie, char *str, int *ind, int *arr, int *num) {
    TrieNode *p = trie;
    for (int i = 0; str[i]; i++) {
        if (p->childs[str[i] - BASE] == NULL) {
            p->childs[str[i] - BASE] = new_node();
        }
        p = p->childs[str[i] - BASE];
    }
    //如果该单词在字典树中不存在，记录其值为当前种类数，模式值与标记值相同，种类数加一，反之存在时只要将模式值赋值为标记值即可
    if (p->flag == 0) {
        p->flag = *ind;
        arr[*num] = *ind;
        *ind += 1;
    } else {
        arr[*num] = p->flag;   
    }
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
    //数组模拟字典树，分别入树
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
    for (int i = 0; i < len; i++) {
        if (str_log[i] != pattern_log[i]) return false;
    }
    return true;
}

int main() {
 
    return 0;
}
