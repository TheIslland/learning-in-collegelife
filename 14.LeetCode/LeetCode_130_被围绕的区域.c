/*************************************************************************
	> File Name: LeetCode_130_被围绕的区域.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月21日 星期一 10时01分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct UnionSet {
    int *fa;
    int *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->fa = (int *)malloc(sizeof(int ) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->fa[i] = i;
        u->size[i] = 1;
    } 
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->fa[x] != x) 
        return (u->fa[x] = find(u, u->fa[x]));
    return x;
}

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb, fb ^= fa, fa ^= fb;
    }
    u->fa[fb] = fa;
    u->size[fa] += u->size[fb];
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u->size);
    free(u);
    return ;
}
//将二维数组转化为一位数组处理
int getInd(int i, int j, int m) {
    return i * m + j + 1;
}

//对于本题来说可以转化为Ｏ联通域是否有与边界Ｏ联通，边界点用虚拟节点连接处理
//所以可以采取下右二方向搜索
void solve(char** board, int n, int m) {
    UnionSet *u = init(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue; //如果一个点时Ｘ就跳过不处理
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { //如果是边界点就将其与虚拟外圈点联通，最后只需判断是否与虚拟店联通即可知谁被包围
                merge(u, 0, getInd(i, j, m));
            }
            if (i - 1 >= 0 && board[i - 1][j] == 'O') { //向下搜索遇到Ｏ联通他们
                merge(u, getInd(i, j, m), getInd(i - 1, j, m));
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') { // 向右搜索遇到Ｏ联通他们
                merge(u, getInd(i, j, m), getInd(i, j - 1, m));
            }
        }
    } 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 'O') continue;
            if (find(u, getInd(i, j, m)) != find(u, 0)) board[i][j] = 'X'; //只要该点没与虚拟边界点连接就改写
        }
    }
    clear(u);
    return ;
}
