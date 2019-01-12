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
    int count; //计数变量，用于标记字符串尾
    struct Node **childs; //字典树
    struct Node *fail; //失败指针，相当于KMP中的失败数组
}*Trie, TrieNode;

//获取一个新节点
TrieNode *new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0;i < BASE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}

//字典树清空操作
void clear(Trie root) {
    for (int i = 0; i < SIZE; i++) {
        if (root->childs[i] == NULL) {
            clear(root->childs[i]);
        }
        free(root->childs);
        free(root);
    }
}

//字典树插入操作
void insert(Trie root, char *str) {
    TrieNode *p = root;
    for (int i = 0; i < SIZE; i++) {
        if (p->childs[str[i] - BASE] == NULL) {
            p->childs[str[i] - BASE] = new_node();
        }
        p = p->childs[str[i] - BASE];
    }
    p->count++; 
}

//建立AC自动机
void build_automation(Trie root) {
    root->fail = root; //根节点的失败指针是他本身
    TrieNode *arr[MAX_N]; //声明一个数组模拟队列
    int l = 0, r = 0; //声明队列头尾指针
    arr[r++] = root; //将根节点入队
    while (l < r) { //当队列不为空时循环遍历（广度）
        TrieNode *now = arr[l++]; //出队一个元素作为当前指针
        for (int i = 0; i < SIZE; i++) { //遍历当前指针的所有孩子节点
            if (now->childs[i] != NULL) { //如果当前孩子节点为空，那么下一个节点
                TrieNode *child = now->childs[i]; //声明一个孩子节点， 那么孩子节点的失败指针应该制造向根节点
                if (now == root) {
                    child->fail = root;
                } else { //如果当前节点不为根节点
                    TrieNode *iter = now; //声明一个查找节点，初始化为当前节点
                    while (iter != root && iter->fail->childs[i] == NULL) { //当查找节点不为根节点，且当前节点的失败指针的下一节点不存在
                        iter = iter->fail; //则更新查找节点为失败指针
                    }
                    if (iter->fail->childs[i] != NULL) { //如果查找到合适的失败指针，赋值
                        child->fail = iter->fail->childs[i];
                    } else { //否则让失败指针指向根节点
                        child->fail = root;
                    }
                }
                arr[r++] = child; //孩子节点入队
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
            total_count += iter->count;
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
        char pattern[MAX_N];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automation(root);
    char str_buffer[MAX_N];
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    clear(root);
    return 0;
}
