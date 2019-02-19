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
        return root; //如果父系节点里有红节点，但是孙系节点中无红色节点，则不需要处理
    }
    root->color = RED; //将父节点的颜色变为红色
    root->lchild->color = root->rchild->color = BLACK; //他的两个子孩子变为黑色
    return root;
}

//基本插入操作
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

//完全的插入操纵
RBTNode *insert(RBTNode *root, int key) {
    root = __insert(root, key);
    root->color = BLACK; //确保根节点是黑色
    return root;
}

//寻找前驱
RBTNode *predecessor(RBTNode *root) {
    RBTNode *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

//删除调整
RBTNode *erase_maintain(RBTNode *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root; //无双黑节点的情况，即处理了２度红与黑，一度红与０度红的情况
    //判断是否为一侧双黑另一侧（兄弟节点及其子孩子）无红的情况
    #define UNBALANCE(a, b) (root->a->color == DOUBLE_BLACK && root->b->color == BLACK && !has_red_child(root->b))
    if (UNBALANCE(lchild, rchild) || UNBALANCE(rchild, lchild)) {
        //下沉型
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    #undef UNBALANCE
    if (root->lchild->color == DOUBLE_BLACK) { //当双黑节点在左子树时
        if (root->rchild->color == RED) { //如果我的兄弟节点是红色，ＲＲ型，大左旋改色
            root = left_rotate(root);
            root->color = BLACK;
            root->lchild->color = RED;
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        root->lchild->color = BLACK; //无论是ＲＬ型还是ＲＲ型都会在操作黑将双黑节点转变为单黑节点，所以此操作先置无影响
        if (root->rchild->rchild->color != RED) { 
            //因为此时不存在三黑无红的情况，所以通过判断是否为ＲＲ型判断是否为ＲＬ型（因为存在子孩子双红的情况所以不能直接通关判断ＲＬ是否为红型来确定ＲＬ型），如果此时为ＲＬ型则先进性小右旋，将ＲＬ型转化为ＲＲ型
            root->rchild = right_rotate(root->rchild);
            root->rchild->color = BLACK;
            root->rchild->rchild->color = RED;
        }
        //对ＲＲ型进行大左旋平衡处理
        root = left_rotate(root);
        root->color = root->lchild->color;
    } else { //当双黑节点在右子树时
        if (root->lchild->color == RED) { //如果我的兄弟节点是红色，ＬＬ型，大右旋改色
            root = right_rotate(root);
            root->color = BLACK;
            root->rchild->color = RED;
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        root->rchild->color = BLACK; //无论是ＬＲ型还是ＬＬ型都会在操作后将双黑几点转变为单黑节点，所以此操作无先置影响
        if (root->lchild->lchild->color != RED) { 
        //因为此时不存在三黑无红的情况，所以通过判断是否为ＬＬ型判断是否为ＬＲ型（因为存在子孩子双红的情况所以不能直接通关判断ＬＲ是否为红型来确定ＬＲ型），如果此时为ＬＲ型则先进性小右旋，将ＬＲ型转化为ＬＬ型
            root->lchild = left_rotate(root->lchild);
            root->lchild->color = BLACK;
            root->lchild->lchild->color = RED;
        }
        //对ＬＬ型进行大右旋平衡处理
        root = right_rotate(root);
        root->color = root->rchild->color;
    }
    //共用的染色处理
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

//删除基本操作
RBTNode *__erase(RBTNode *root, int key) {
    if (root == NIL) return NIL; //如果删除节点不存在，则不删除直接返回
    if (root->key > key) { //如果当前节点比要删除节点大则去左子树寻找
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) { //如果当前节点比要删除节点小则去右子树寻找
        root->rchild = __erase(root->rchild, key);
    } else { //当存一个这样的节点时
        if (root->lchild == NIL || root->rchild == NIL) { //如果是一个０度或者１度节点
            RBTNode *temp = (root->lchild == NIL ? root->rchild : root->lchild); //如果是一个０度节点ｔｅｍｐ为虚拟叶子节点，如果为１度节点则为其非空子孩子
            temp->color += root->color; //如果要删除节点为红色，则对替换节点无影响，如果为黑色，则子替换节点为红色时染黑，为黑色时染为双黑
            free(root); //释放节点
            return temp;
        } else { //删除节点为二度顶点时
            RBTNode *temp = predecessor(root); //找到删除节点的前驱节点
            root->key = temp->key; //将前驱节点的值，赋值给欲删除节点，待删除节点颜色不变
            root->lchild = __erase(root->lchild, temp->key); //转化为删除前驱节点，因为前驱节点必为０度或者１度节点，所以转化为处理０或１度节点问题
        }
    }
    return erase_maintain(root); //调整平衡性
}

//完全的删除操作
RBTNode *erase(RBTNode *root, int key) {
    root = __erase(root, key);
    root->color = BLACK; //确保根节点为黑色
    return root;
}

//清空红黑树
void clear(RBTNode *node) {
    if (node == NIL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

//前序遍历输出红黑树
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
