/*************************************************************************
	> File Name: 筛法建堆.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月04日 星期日 15时06分36秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Heap {
    int *data;
    int cnt, size;
} Heap;

void build(Heap *h) {
    int f, c, temp;
    for (int i = h->cnt / 2; i > 0; i--) {
        f = i;
        temp = h->data[i];
        while (f * 2 <= h->cnt) {
            c = f * 2;
            if (c != h->cnt && h->data[c] < h->data[c + 1]) c++;
            if (temp < h->data[c]) {
                h->data[f] = h->data[c];
                f = c;
            } else break;
        }
        h->data[f] = temp;
    }
    printf("%d\n", h->cnt);
}

void heap_sort(int *arr, int n) {
    int *p = arr - 1;
    for (int i = n >> 1; i >= 1; i--) {
        int ind = i;
        while ((ind << 1) <= n) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[1], p[i]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;
}

int main() {
 
return 0;
}
