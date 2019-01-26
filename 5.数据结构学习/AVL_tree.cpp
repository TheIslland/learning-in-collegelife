/*************************************************************************
	> File Name: AVL_tree.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月25日 星期五 14时47分00秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

//比较宏
#define max(a, b) ({ \
    __typeof(a) __a = (a); \
    __typeof(b) __b = (b); \
    __a > __b ? __a : __b; \
})

//AVL树结构定义
typedef struct Node {
    int key; //存储权值，用于查找
    int height; //存储树高用于平衡
    struct Node *lchild, *rchild;
} Node;

//一个虚拟节点
Node *NIL = NULL;

//按key值初始化ＡＶＬ树节点
Node *init(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->height = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

//在所有函数初始化之前初始化NIL
__attribute__((constructor))
void init_NIL() {
    NIL = init(0);
    NIL->height = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

//更新树高
void calc_height(Node *root) {
    root->height = max(root->lchild->height, root->rchild->height) + 1; //取左右子树中树高最大的那个加一
    return ;
}

//左旋操作
Node *left_rotate(Node *root) {
    Node *temp = root->rchild; //如果进行左旋，则新的根节点必为原根节点的右孩子成为根节点
    root->rchild = temp->lchild; //首先让原根节点的右子树更新为新根节点的左子树
    temp->lchild = root; //新根节点的左子树更新为原根节点
    calc_height(root); //更新树高
    calc_height(temp); 
    return temp; //更新根节点
}

//右旋操作
Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

//平衡操作
Node *maintain(Node *root) {
    if (abs(root->lchild->height - root->rchild->height) <= 1) return root; //如果左右树高差小于１则视为平衡不操作
    if (root->lchild->height > root->rchild->height) { //如果左子树高高于右子树高
        if (root->lchild->lchild->height < root->lchild->rchild->height) { //且左子树的右子树较高
            root->lchild = left_rotate(root->lchild); //先进行左旋
        }
        root = right_rotate(root); //再进行右旋
    } else {
        if (root->rchild->rchild->height < root->rchild->lchild->height) { //如果右子树高高于左子树高且右子树的左子树高
            root->rchild = right_rotate(root->rchild); //先右旋再左旋
        }
        root = left_rotate(root);
    }
    return root;
}

//插入操作
Node *insert(Node *root, int key) {
    if (root == NIL) return init(key); //如果树空则初始化为根节点
    if (root->key == key) return root; //如果该节点已存在则直接返回
    else if (root->key < key) root->rchild = insert(root->rchild, key); //如果插入节点比当前节点大，插入到其右子树下
    else root->lchild = insert(root->lchild, key); //反之插入到左子树下
    calc_height(root); //更新树高
    return maintain(root); //平衡
}

//获取前驱
Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild; //一个点的前驱在排序二叉树中是比当前点小的点中最大的点，故应为左子树中最深的右子树节点
    return temp;
}

//删除操作
Node *erase(Node *root, int key) {
    if (root == NIL) return root; //如果当前为虚拟节点，不处理直接返回
    if (root->key < key) { //如果当前节点比要删除的节点小，去右子树递归删除
        root->rchild = erase(root->rchild, key);
    } else if (root->key > key) { //反之，如果比要删除的节点大，则去左子树中删除
        root->lchild = erase(root->lchild, key);
    } else { //如果找到了要删除的点
        if (root->lchild == NIL && root->rchild == NIL) { //如果为叶子节点，直接释放，并返回一个虚节点
            free(root);
            return NIL;
        } else if (root->lchild == NIL || root->rchild == NIL) { //如果节点为有一个孩子的节点，则找到那个孩子节点，删除待删除节点，将那个孩子节点作为原节点的代替
            Node *temp = (root->lchild != NIL ? root->lchild : root->rchild);
            free(root);
            return temp;
        } else { //如果为有两个孩子节点的节点，则查找前驱节点为待删除节点的替代
            Node *temp = predecessor(root); 
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    calc_height(root); //更新树高
    return maintain(root); //进行树的平衡操作
}

//进行树的清空操作
void clear(Node *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

//进行树的遍历操作
void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n", root->key, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (scanf("%d%d", &op, &val) != EOF) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
        }
        output(root);
    }
    return 0;
}
