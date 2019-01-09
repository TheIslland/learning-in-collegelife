/*************************************************************************
	> File Name: double_arr_trie.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月06日 星期日 15时15分18秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//声明一个普通的字典树
typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

//声明一个双数组字典树类型
typedef struct DATNode {
    int base, check; //base值通过base + 字母值找到子节点（但会出现喜当爹情况）, check 表示当前节点的父节点
} DATNode;

//字典树的新节点获取，与传统字典树获取不同，不再采用直接申请n * n * n.....个而是需要时申请ｎ个
Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

//清除字典树
void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

//字典树的插入
int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) { //如果字符串在字典树中所对应的节点未被声明，则初始化该节点
            p->next[str[i] - 'a'] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - 'a']; //将当前节点更新
    }
    p->flag = 1; //将flag标记为１表示到此处成词
    return cnt;
}

//获取base值
int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0; //初始化base值
    while (!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue; //如果当前节点下的某节点不存在，跳过当前节点
            if (trie[base + i].check == 0) continue; //观察base值是否合理，如果不合理继续更换base值
            flag = 0;
            break;
        }
    }
    return base;
}

//字典树转双数组字典树操作
void Transform(Node *node, DATNode *trie, int ind) {
    if (node->flag) trie[ind].check = -trie[ind].check; //先行操作，当在字典树ind节点处成词时，双数组字典树check标记为负值表示字符串在此处成词
    trie[ind].base = getBase(node, trie); //获取字典树当前节点在双数组字典树中的base值
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind; //更新当前节点下所有节点的check值
    }
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i); //递归操作将字典树转化为双数组字典树
    }
    return ;
}

//按双数组字典树查找
int search(DATNode *trie, const char *str) {
    int p = 1; 
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base + delta;
    }
    return trie[p].check < 0;
}



int main() {
    int n, cnt = 1;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }        
    return 0;
}
