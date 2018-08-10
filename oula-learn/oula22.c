/*************************************************************************
	> File Name: oula22.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 16时05分25秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#define MAX_N 50000
char a[MAX_N];
char b[MAX_N][100];
void sort(char b[MAX_N][100], int x) {
    int i, j;
    char p[100];
    for(int i = 0; i < x - 1 ; i++) {
        for(int j = i + 1; j < x; j++) {
            if(strcmp(b[i], b[j]) > 0) {
                strcpy(p, b[i]);
                strcpy(b[i], b[j]);
                strcpy(b[j], p);
            }
        }
    }
}
int exc(char x) {
    if(x >= 'A' && x <='Z') {
        return x - 64;
    }
    return 0;
}
int main() {
    gets(a);
    int64_t sum = strlen(a), ans = 0, x = 0;
    int num = 0;
    for(int i = 0; i < sum; i++) { 
        if(a[i] == ',') {
            num++;
            x = 0;
            continue;
        }
        b[num][x++] = a[i];
    }
    sort(b, num + 1);
     for(int i = 0; i <= num; i++) {
        int64_t account = 0;
         for(int j = 0; j < strlen(b[i]); j++) {
            account += exc(b[i][j]);
        }
        ans += account * (i + 1);
        printf("%s %d\n",b[i],i + 1);
    }
    printf("%"PRId64"\n",ans);
    printf("%s\n",b[937]);
    return 0;
}
