/*************************************************************************
	> File Name: 12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 10时20分37秒
 ************************************************************************/

#include <stdio.h>

int factor_num(int x) {
    int cut = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) cut += 2;
    }
    return cut;
}

int main() {
    int n = 1;
    while (factor_num(n * (n + 1) / 2) < 500) ++n;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
