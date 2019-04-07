/*************************************************************************
	> File Name: on_sort.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月21日 星期日 10时59分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void raddix_sort_(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65536] = {0};
    for (int i = 0 ; i < n;i++) cnt[num[i] & 0xffff]++;
    for (int i =1; i < 65536; i++) cnt[i] += cnt [i - 1];
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i-- ) cnt[i] = =cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memeset(cnt, 0, sizeof(cnt));
    for (int i = 0 ; i < n;i++) cnt[(num[i] >> 16) & 0xffff]++; 
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i + 1];
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i-- ) cnt[i] = =cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp [i] >> 16) & 0xffff]++] = temp[i];
    return;
}

void output(int *num, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return ;
}
int main() {
 
return 0;
}
