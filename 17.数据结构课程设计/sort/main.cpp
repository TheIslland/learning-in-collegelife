/*************************************************************************
	> File Name: main.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月22日 星期六 10时07分15秒
 ************************************************************************/

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sort.h"

using namespace std;

int main() {
    srand(time(0));
    int arr[MAX_N];
    rand_num(arr, MAX_N);
    Sort s;
    int n;
    out("请选择排序方式:");
    out("1.选择排序");
    out("2.快排");
    out("3.插入排序");
    out("4.冒泡排序");
    out("5.归并排序");
    out("6.希尔排序");
    out("7.堆排序");
    out("8.现有排序全部使用");
    cin >> n;
    switch(n) {
        case 8:
        case 1:
            FUNC_INVOKE(arr, MAX_N, s.select_sort, num, MAX_N);
            if (n != 8) break;
        case 2:
            FUNC_INVOKE(arr, MAX_N, s.quick_sort, num, 0, MAX_N - 1);
            if (n != 8) break;
        case 3:
            FUNC_INVOKE(arr, MAX_N, s.insert_sort, num, MAX_N);
            if (n != 8) break;
        case 4:
            FUNC_INVOKE(arr, MAX_N, s.bubble_sort, num, MAX_N);
            if (n != 8) break;
        case 5:
            FUNC_INVOKE(arr, MAX_N, s.merge_sort, num, 0, MAX_N - 1);
            if (n != 8) break;
        case 6:
            FUNC_INVOKE(arr, MAX_N, s.hill_sort, num, MAX_N);
            if (n != 8) break;
        case 7:
            FUNC_INVOKE(arr, MAX_N, s.heap_sort, num, MAX_N);
            if (n != 8) break;
    }
    return 0;
}
