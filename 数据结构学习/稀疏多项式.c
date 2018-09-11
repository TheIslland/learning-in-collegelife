/*************************************************************************
	> File Name: 稀疏多项式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月11日 星期二 15时23分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
typedef struct Vector {
    int size, length;
    int *c, *e;
} Vector;

void init (Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->c = (int *)malloc(sizeof(int) * size);
    vector->e = (int *)malloc(sizeof(int) * size);
}

void expend (Vector *vector) {
    int *old_c = vector->c;
    int *old_e = vector->e;
    vector->size = vector->size * 2;
    vector->c = (int *)malloc(sizeof(int) * vector->size);
    vector->e = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->c[i] = old_c[i];
        vector->e[i] = old_e[i];
    }
    free(old_c);
    free(old_e);
}

int insert (Vector *vector, int loc, int value1, int value2) {
    if (loc < 0 || loc > vector->length) {
		return ERROR;
    }
    if (vector->length >= vector->size) {
        expend(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->c[i] = vector->c[i - 1];
        vector->e[i] = vector->e[i - 1];
    }
    vector->c[loc] = value1;
    vector->e[loc] = value2;
    vector->length++;
	return OK;
}

void clear (Vector *vector) {
    free(vector->c);
    free(vector->e);
    free(vector);
}

int count (Vector *vector, int num) {
	int sum = 0;
    for (int i = 0; i < vector->length; i++) {
		sum += vector->c[i] * pow(num,vector->e[i]);
    }
    return sum;
}

int main() {
    int m, x, ans = 0;
    scanf("%d", &m);
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    init(vector, m);
	for (int i = 0 ; i < m; i++) {
		int c, e;
        scanf("%d %d", &c, &e);
        insert(vector, i, c, e);
    }
    scanf("%d", &x);
    ans = count(vector, x);
    printf("%d\n", ans);
    clear(vector);
}
