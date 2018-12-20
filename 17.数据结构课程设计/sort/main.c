/*************************************************************************
	> File Name: main.c
	> Author: gongpixi
	> Mail: 1371854096@qq.com
	> Created Time: 2018年12月16日 星期日 17时20分08秒
 ************************************************************************/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sort.h"

#define TEST_TIME(funs) ({\
    int begin = clock();\
    double ret = funs;\
    int end = clock();\
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000);\
    ret;\
})

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void rand_num(int *num, int n) {
    while(n--) num[n] = rand() % 100;
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 20
    int arr[7][MAX_N];
    for (int i = 0; i < 7; i++) {
        rand_num(arr[i], MAX_N);
    }
    TEST(arr[0], MAX_N, select_sort, num, MAX_N);
    TEST_TIME(select_sort(arr[0], MAX_N));
    printf("\n");

    TEST(arr[1], MAX_N, quick_sort, num, 0, MAX_N - 1);
    TEST_TIME(quick_sort(arr[1], 0, MAX_N - 1));
    printf("\n");
    
    TEST(arr[2], MAX_N, insert_sort, num, MAX_N);
    TEST_TIME(insert_sort(arr[2], MAX_N));
    printf("\n");
    
    TEST(arr[3], MAX_N, bubble_sort, num, MAX_N);
    TEST_TIME(bubble_sort(arr[3], MAX_N));
    printf("\n");

    TEST(arr[4], MAX_N, merge_sort, num, 0, MAX_N - 1);
    TEST_TIME(merge_sort(arr[4], 0, MAX_N - 1));
    printf("\n");
    
    TEST(arr[5], MAX_N, hill_sort, num, MAX_N);
    TEST_TIME(hill_sort(arr[5], MAX_N));
    printf("\n");
    
    TEST(arr[6], MAX_N, heap_sort, num, MAX_N);
    TEST_TIME(heap_sort(arr[6], MAX_N));
    return 0;
}
