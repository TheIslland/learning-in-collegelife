/*************************************************************************
	> File Name: oula38.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时14分16秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
int is_valid(int x) {
    int num[10] = {0};
    int n = 0, dight = 0;
    do {
        n += 1;
        int y = x * n;
        while (y) {
            if (y % 10 == 0) return 0;
            if (num[y % 10]) return 0;
            num[y % 10] = 1;
            y /= 10;
            dight += 1;
        }
    } while(dight < 9);
    if(dight > 9) return 0;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int y = x * i;
        ret = ret * (int)pow(10, floor(log10(y)) + 1) + y;
    }
    return ret;
}
int main() {
    for (int i = 1; i < 10000; i++) {
        int temp = is_valid(i);
        temp && printf("%d %d\\n",i,temp);
    }
    return 0;
}
