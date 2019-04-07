/*************************************************************************
	> File Name: sort.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月22日 星期六 20时28分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OP 20

#define swap(a, b) {\
    __typeof(a) __temp = a; a = b; b = __temp;\
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
void insert_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
    output(arr, n);
}

void bulle_sort(int *arr, int n) {
    int judg = 1;
    for (int i = 1; i < n && judg; i++) {
        judg = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] < arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            judg++;
        }
    }
    output(arr, n);
}

void hill_sort(int *arr, int n) {
    int i, j, k;
    for (i = n / 2; i >= 1; i /= 2) {
        for (j = i; j < n; j++) {
            for (k = j; (k - i >= 0) && (arr[k] < arr[k - i]); k -= i) {
                swap(arr[k], arr[k - i]);
            }
        }
    }
    output(arr, n);
}

void mearg_sort(int *arr, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && arr[l] > arr[r]) {
            swap(arr[l], arr[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    mearg_sort(arr, l, mid);
    mearg_sort(arr, mid + 1, r);
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 < r) {
        
    }
}

int main() {
    srand(time(0));
    int a[MAX_OP];
    for (int i = 0; i < MAX_OP; i++) {
        a[i] = rand() % 100;
    }
    output(a, MAX_OP);
    hill_sort(a, MAX_OP);
    return 0;
}
