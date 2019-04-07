/*************************************************************************
	> File Name: 全排列.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月12日 星期六 10时45分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
    return ;
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
    while (q != first) {
        p--;
        char *find = end;
        if (*p < *q) {
            while (*find < *p) {
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

int isInswap(char *str, int l, int r) {
    for (int i = l; i < r; i++) {
        if (str[i] == str[r]) return 0;
    }
    return 1;
}

void next_permutation_recursion(char *str, int first, int end) {
    if (first == end) {
        for (int i = 0; i < 5; i++) {
            printf("%d", str[i]);
        }
        printf("\n");
    } else {
        for (int i = first; i <= end; i++) {
            if (isInswap(str, first, i)) {
                swap(str + i, str + first);
                next_permutation_recursion(str, first + 1, end);
                swap(str + i, str + first);
            }       
        }
    }
}

int main() {
    char a[5] = {0, 1, 2, 3, 4};
    /*do {
        for (int i = 0; i <5; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
    } while (next_permutation(a, a + 4));
    */
    next_permutation_recursion(a, 0, 4);
    return 0;
}
