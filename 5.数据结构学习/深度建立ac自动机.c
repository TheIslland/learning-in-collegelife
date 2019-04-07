/*************************************************************************
	> File Name: 深度建立ac自动机.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月20日 星期日 09时44分31秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BASE 'a'
#define SIZE 26
#define MAX_N 100000
typedef struct Node {
    int flag;
    struct Node **childs;
    struct Node *fail, *father;
}Node, *Trie;

Node *new_node(Node *father) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->childs = (Node **)malloc(sizeof(Node *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->father = father;
    p->flag = 0;
    return p;
}

void clear(Trie node) {
    if (node == NULL) return ;
    for (int i = 0; i < SIZE; i++) clear(node->childs[i]);
    free(node->childs);
    free(node);
    return ;
}

void intsert(Trie root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int len = str[i] - BASE;
        if (p->childs[len] == NULL) {
            p->childs[len] = new_node(p);
        }
        p = p->childs[len];
    }
    p->flag = 1;
    return ;
}

//深度建立失败指针
void build_ac(Node *node) {
    if (node == NULL) return; //后发而先置，递归时判断当前节点是否为根节点的父亲节点，如果是　返回 
    if (node->fail == NULL) build_ac(node->father); //如果当前节点没有失败指针，递归建立
    for (int i = 0; i < SIZE; i++) {
        if (node->childs[i] == NULL) continue; //如果子孩子为空，找下一个
        if (node->childs[i]->fail) continue; //如果当前节点的子孩纸已有失败指针，则不要重复建立，不加此句会爆栈造成段错误，因为每次循环递归建一次父串失败指针，当存在四层以上时爆栈。
        Node *p = node->fail, *pre_p; //声明ｐ为孩子节点的前以节点的失败指针，ｐｒｅ_ｐ的作用是存储
        while (p && p->childs[i] == NULL) { //当ｐ不为空，且失败指针的孩子节点不匹配时执行循环ＫＭＰ
            if (p->fail == NULL) build_ac(p->father); //如果当前ｐ没有失败指针，则建立ｐ父亲节点的失败指针
            pre_p = p; //更新存储最后一个失败指针
            p = p->fail;
            
        }
        if (p == NULL) p = pre_p;
        else p = p->childs[i]; //
        node->childs[i]->fail = p; //ＫＭＰ建立失败指针
        build_ac(node->childs[i]); //建立孩子节点失败指针
    }
    return ;
}

int main() {
    Node *trie = new_node(NULL); 
    return 0;
}
