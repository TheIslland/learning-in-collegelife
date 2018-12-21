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

int main() {
    srand(time(0));
    int arr[7][MAX_N];
    for (int i = 0; i < 7; i++) {
        rand_num(arr[i], MAX_N);
    }
    Sort s;
    TEST(arr[0], MAX_N, s.select_sort, num, MAX_N);
    TEST_TIME(s.select_sort(arr[0], MAX_N));
    printf("\n");

    TEST(arr[1], MAX_N, s.quick_sort, num, 0, MAX_N - 1);
    TEST_TIME(s.quick_sort(arr[1], 0, MAX_N - 1));
    printf("\n");
    
    TEST(arr[2], MAX_N, s.insert_sort, num, MAX_N);
    TEST_TIME(s.insert_sort(arr[2], MAX_N));
    printf("\n");
    
    TEST(arr[3], MAX_N, s.bubble_sort, num, MAX_N);
    TEST_TIME(s.bubble_sort(arr[3], MAX_N));
    printf("\n");

    TEST(arr[4], MAX_N, s.merge_sort, num, 0, MAX_N - 1);
    TEST_TIME(s.merge_sort(arr[4], 0, MAX_N - 1));
    printf("\n");
    
    TEST(arr[5], MAX_N, s.hill_sort, num, MAX_N);
    TEST_TIME(s.hill_sort(arr[5], MAX_N));
    printf("\n");
    
    TEST(arr[6], MAX_N, s.heap_sort, num, MAX_N);
    TEST_TIME(s.heap_sort(arr[6], MAX_N));
    return 0;
}
