/*************************************************************************
	> File Name: Sqlist.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月06日 星期四 09时12分24秒
 ************************************************************************/

#ifndef _SQLIST_H
#define _SQLIST_H
#endif
#include "status.h"
void init(Vector *vector, int size) {
        vector->size = size;
        vector->length = 0;
        vector->data = (int *)malloc(sizeof(int) * size);

}

void expand(Vector *vector) {
        int *old_data = vector->data;
        int vector->size = vector->size * 2;
        int vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length ; i++) {
                vector->data[i] = old_data[i];
            
    }
        free(old_data);

}
int insert(Vector *vector, int loc, int value) {
    if (loc < 0 || loc > vector->length) {
        printf("FALSE\n");
        return ERROR;
    }
    if(vector->length >= vector->size) {
        expand(vector);
    }
    for(int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->length++;
    vector->data[loc] = value;
    printf("success\n");
    return OK;
}
int search(Vector *vector, int value) {
    for(int i = 0; i < vector->length; i++) {
        if(vector->data[i] == value) {
            printf("susses\n")
            return OK;
        }
    }
    printf("false\n");

}
