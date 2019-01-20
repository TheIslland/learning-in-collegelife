/*************************************************************************
	> File Name: 线索化ac自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 11时01分59秒
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
    struct Node *fail;
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
void build_automation(Trie node) {
	TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode*) * (MAX_N + 5));
    int head = 0, tail=  0;
    queue[tail++] = node; //一个队列用于层次遍历
    while (head < tail) {
        TrieNode *now = queue[head++]; //初始化一个ｎｏｗ当前节点为队头节点，用于层次遍历
        for (int i = 0 ; i < SIZE; i++) { //遍历每一个ｎｏｗ当前节点下的每一个孩子节点
            if (now->childs[i] == NULL) { //如果某一孩子节点未被使用
                if (now != node) now->childs[i] = now->fail->childs[i]; //且这个节点不是根节点，那么就使用这个节点存储ｎｏｗ当前节点的失败指针中应最终指向的childs[i]孩子节点
                continue; //跳到下一个
            } //６５行到６８行的这个操作用于初始化线索
            TrieNode *p = (now->fail ? now->fail->childs[i] : node); //６９行到７０行用于初始化下一节点的ｆａｉｌ失败指针，本行用于判断当前节点是否有失败指针，有，则在失败指针的孩子几点中寻找是否有所要查找的childs[i]孩子节点，反之，没有的话，让ｐ指向根节点（问题：什么节点没有失败指针。答：１．根节点，２．根节点下面的第一层孩子节点）
            if (p == NULL) p = node; //如果失败指针指向的孩子节点中没有childs[i]的话让ｐ指向根节点
            now->childs[i]->fail = p; //初始化childs[i]节点的失败指针为ｐ
            queue[tail++] = now->childs[i]; //将孩子节点入队列
        }
    }
    free(queue);
    return;
}

int match_count(TrieNode *root, const char *str) {
    int ret = 0;
    TrieNode *p = root, *q;
    while (str[0]) {
        p = p->childs[str[0] - 'a'];
        q = p;
        while (q) ret += q->count, q = q->fail;
        if (p == NULL) p = root;
        str++;
    }
    return ret;
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
