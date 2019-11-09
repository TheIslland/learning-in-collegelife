/*************************************************************************
	> File Name: 顺序表综合实现.c
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Nov  7 17:31:31 2019
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define OK 1
#define ERROR 0

typedef struct Vector {
    int length, size;
    int *data;
} Vector;

void init(Vector *vector, int size) {
    vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
    return ;
}

void expend(Vector *vector) {
    int *data = vector->data;
    vector->size *= 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0 ; i < vector->length; i++) {
        vector->data[i] = data[i];
    }
    free(data);
    return ;
}

int insert(Vector *vector, int loc, int value) {
    if (loc  < 0 || loc > vector->length) {
        printf("failed\n");
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expend(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->length++;
    vector->data[loc] = value;
    printf("success\n");
    return OK;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == value) {
            printf("success\n");
            return OK;
        }
    }
    printf("failed\n");
    return ERROR;
}

int delete_node(Vector *vector, int num) {
    if (num < 0 || num >= vector->length) {
        printf("failed\n");
        return ERROR;
    }
    for (int i = num; i < vector->length; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->length--;
    printf("success\n");
    return OK;
}
void print(Vector *vector) {
    for (int i = 0; i < vector->length; i++) {
        printf("%d", vector->data[i]);
        (i < vector->length - 1) && (printf(" "));
    }
    printf("\n");
}
int main() {
	Vector *a = (Vector *)malloc(sizeof(Vector));
	init(a, 20);
	int m, t;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		int b, c;
		if (t == 1) {
			scanf("%d %d", &b, &c);
			insert(a, b, c);
		}
		else if (t == 2) {
			scanf("%d", &b);
			delete_node(a, b);
		}
		else if (t == 3) {
			scanf("%d", &b);
			search(a, b);
		}
		else {
			print(a);
		}
	}
	return 0;
}

