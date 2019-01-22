/*************************************************************************
	> File Name: 哈弗曼.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月29日 星期一 18时17分00秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef struct Node {
    ll freq;
    char *name;
    int ind;
    struct Node *lchild, *rchild;
    bool operator < (const Node& t)const{
        return freq > t.freq;
    } 
} Node;

typedef struct ans{
    char *str;
    char *code;
}Ans;

void clear(Node *root) {
    if(!root) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root->name);
    free(root);
    return ;
}

Node *getNewNode(const char *name, ll freq, int ind) {
    Node *p = (Node *)malloc(sizeof(Node));
    //p->name = (char *)malloc(sizeof(char) * 4);
    p->name = strdup(name);
    p->ind = ind;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *init(Node node) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->name = strdup(node.name);
    p->freq = node.freq;
    p->ind = node.ind;
    p->lchild = node.lchild;
    p->rchild = node.rchild;
    return p;
}

Node *build_node(priority_queue<Node> &q) {
    Node *ret;
    while (q.size() > 1) {
        Node *node1, *node2, *new_node;
        node1 = init(q.top());
        q.pop();
        node2 = init(q.top());
        q.pop();
        ll num = node1->freq + node2->freq;
        new_node = getNewNode("", num, -1);
        new_node->lchild = node2;
        new_node->rchild = node1;
        q.push(*new_node);
   }
    ret = init(q.top());
    q.pop();
    return ret;
}

void extract_node(Node *root, char (*code)[30], int k, char *buff) {
    buff[k] = 0;
    if (root->ind >= 0) {
        strcpy(code[root->ind], buff);
        return ;
    }
    buff[k] = '0';
    extract_node(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_node(root->rchild, code, k + 1, buff);
    return ;
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    output(root->rchild);
    if (root->ind != -1)
    cout << "node :" << root->name << " " << root->freq << " ind = " << root->ind << endl;
    return;
}

int main() {
    int n ; 
    scanf("%d", &n);
    Node *root;
    priority_queue<Node> q;
    char str[20][1000];
    for (int i = 0 ; i < n; i++) {
        ll freq;
        Node *temp;
        scanf("%s%lld", str[i], &freq);
        temp = getNewNode(str[i], freq, i);
        q.push(*temp);
    }
    root = build_node(q);
    output(root);
    char code[256][30] = {0}, buff[30];
    extract_node(root, code, 0, buff);
    for (int i = 0; i < n; i++) {
        if (str[i][0] == 0) continue;
        cout << str[i] << ": " << code[i] << endl;
    }
    return 0;
}
