/*************************************************************************
	> File Name: 顺序表.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月29日 星期六 10时08分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Vector {
    int size, length;
    int *data;
}Vector;

Vector *init(int n) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->size = n;
    v->length = 0;
    v->data = (int *)malloc(sizeof(int) * n);
    return v;
}

void expand(Vector *v) {
    int *old_data = v->data;
    v->size *= 2;
    v->data = (int *)malloc(sizeof(int) * v->size);
    for (int i = 0; i < v->length; i++) {
        v->data[i] = old_data[i];
    }
	free(old_data);
    return ;
}

int insert(Vector *v, int num, int value) {
    if (num < 0 || num > v->length) {
        printf("failed\n");
        return 0;
    }
    if (v->length >= v->size) {
        expand(v);
    }
    for (int i = v->length; i > num; --i) {
        v->data[i] = v->data[i - 1];
    }
    v->data[num] = value;
    v->length++;
	printf("success\n");
    return 1;
}

int find(Vector *v, int value) {
    for(int i = 0; i < v->length; i++) {
        if (v->data[i] == value) {
			printf("success\n");
            return 1;
        }
    }
    printf("failed\n");
    return 0;
}

int delete_node(Vector *v, int num) {
    if (num < 0 || num > v->length) {
        printf("failed\n");
        return 0;
    }
    for(int i = num; i < v->length; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->length--;
	printf("success\n");
    return 1;

}

void print(Vector *vector) {
	for (int i = 0; i < vector->length; i++) {
		if(i > 0) printf(" ");
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = init(20);
	int m, t;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        int b,c;
        if(t == 1) {
            scanf("%d %d", &b, &c);
			insert(a, b, c);
        } else if(t == 2) {
			scanf("%d", &b);
            delete_node(a,b);
        } else if(t == 3) {
			scanf("%d", &b);
        	find(a, b);
        } else {
			print(a);
        }
    }
    return 0;
}

