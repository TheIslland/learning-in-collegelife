/*************************************************************************
	> File Name: 全排列.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 16时51分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *a, char *b) {
    while (a < b) {
        swap(a++, b--);
    }
}

int next_permutation(char *first, char *end) {
    if (first == end) return 0;
    char *p = end;
    char *q = p;
    while (p != first) {
        p--;
        char *find = end;
        if (*p < *q) {
            while (*find <= *p) {
                find--;
            }
            swap(p, find);
            reverse(p + 1, end);
            return 1;
        }
        q--;
    }
    return 0;
}

int main() { 
    char a[5] = {0, 1, 2, 3, 4};
    do {
        for (int i = 0; i < 5; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } while (next_permutation(a, a + 4));
    return 0;
}
