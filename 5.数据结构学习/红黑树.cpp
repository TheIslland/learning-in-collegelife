/*************************************************************************
	> File Name: 红黑树.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月17日 星期日 18时07分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//红黑树颜色定义
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

//颜色类名定义
typedef int color_t;

//红黑树的结构体定义
typedef struct RBTNode {
    int key; //权值的存储
    color_t color; // 0 red, 1 black, 2 double black
    struct RBTNode *lchild, *rchild; //声明左子树，声明右子树
} RBTNode;

//声明虚拟节点
RBTNode *NIL;

//优先执行虚拟节点的初始化操作
__attribute__((constructor))
void init_NIL() {
    NIL = (RBTNode *)malloc(sizeof(RBTNode));
    NIL->key = -1; //将虚拟节点的ｋｅｙ值初始化为-1
    NIL->color = BLACK; //将虚拟节点设置为黑色
    NIL->rchild = NIL->lchild = NIL; //初始化左右子树
    return ;
}

//初始化
RBTNode *init(int key) {
    RBTNode *p = (RBTNode *)malloc(sizeof(RBTNode));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED; //所有新节点的颜色都是红色
    return p;
}

//判断当前节点的左右孩子里是否有红色节点
int has_red_child(RBTNode *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

//左旋操作
RBTNode *left_rotate(RBTNode *node) {
    RBTNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    return temp;
}

//右旋操作
RBTNode *right_rotate(RBTNode *node) {
    RBTNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    return temp;
}

//插入操作的平衡调节
RBTNode *insert_maintain(RBTNode *root) {
    if (!has_red_child(root)) return root; //判断当前节点的子孩子中是否有红色节点，如果没有红色节点则不需要进行插入调整
    //以下是对子孩子中有红色节点的情况进行操作，即双红的情况
    if (root->lchild->color == RED && root->rchild->color == RED) { //此情况没有必要处理
    } else if (root->lchild->color == RED && has_red_child(root->lchild)) { //如果为在其左子树中异常
        if (root->lchild->rchild->color == RED) { //判断是不是ＬＲ型，是则先进性小左旋，再进行大右旋
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root); //大右旋
    }  else if (root->rchild->color == RED && has_red_child(root->rchild)) { //判断是不是右子树异常
        if (root->rchild->lchild->color == RED) { //判断是不是ＲＬ型，是则先进性小右旋，再进行左旋
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root); //大左旋
    } else {
        return root; //
    }
    root->color = RED; //将父节点的颜色变为红色
    root->lchild->color = root->rchild->color = BLACK; //他的两个子孩子变为黑色
    return root;
}

//插入操作
RBTNode *__insert(RBTNode *root, int key) {
    if (root == NIL) return init(key); //如果当前节点已经是虚拟叶子节点，则创建新节点
    if (root->key == key) return root; //如果该权值的节点已经存在则，不作操作直接的返回原节点
    else if (root->key > key) { //如果当前节点比插入节点大则去左子树中寻找
        root->lchild = __insert(root->lchild, key);
    } else { //反之去右子树中寻找
        root->rchild = __insert(root->rchild, key);
    }
    return insert_maintain(root); //进行平衡的调节操作，因为是插入调整所以是从父亲节点的角度看
}

RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

RBTNode *predecessor(RBTNode *root) {
    RBTNode *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

RBTNode *erase_maintain(RBTNode *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    #define UNBALANCE(a, b) (root->a->color == DOUBLE_BLACK && !has_red_child(root->b))
    if (UNBALANCE(lchild, rchild) || UNBALANCE(rchild, lchild)) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    #undef UNBALANCE
    if (root->lchild->color == DOUBLE_BLACK) {
        if (root->rchild->color == RED) {
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            return erase_maintain(root->lchild);
        }
        root->lchild->color = BLACK;
        if (root->rchild->rchild->color != RED) {
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        root = left_rotate(root);
        root->color = root->lchild->color;
    } else {
        if (root->lchild->color == RED) {
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            return erase_maintain(root->rchild);
        }
        root->rchild->color = BLACK;
        if (root->lchild->lchild->color != RED) {
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

RBTNode *__erase(RBTNode *root, int key) {
    if (root == NIL) return NIL;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            RBTNode *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            RBTNode *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

RBTNode *erase(RBTNode *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(RBTNode *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void output(RBTNode *root) {
    if (root == NIL) return ;
    printf("(%d %d %d) = %d\n", root->key, root->lchild->key, root->rchild->key, root->color);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    srand(time(0));
    int op, val;
    RBTNode *root = NIL;
    #define MAX_OP 20
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 5, val = rand() % 10;
        switch (op) {
            case 0: 
                printf("delete val %d from RBT\n", val);
                root = erase(root, val);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("insert val %d to RBT\n", val);
                root = insert(root, val);
                break;
        }
        output(root);
    }
    return 0;
}
