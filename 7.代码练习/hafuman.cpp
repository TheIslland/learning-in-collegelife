/*************************************************************************
	> File Name: hafuman.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月22日 星期二 10时00分53秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef struct Node {
    ll freq;
    char *str;
    struct Node *lchild, *rchild, *parent;
} Node;

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root->str);
    free(root);
    return ;
}

void swap() {

}

Node *getNewNode (char *name, ll freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = name;
    p->lchild = p->rchild = p->parent = NULL;
    p->freq = freq;
    return p;
}

Node *build_node(Node **arr, int n) {
    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {

        }
    }
}

int main() {
 
    return 0;
}
