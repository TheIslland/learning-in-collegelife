/*************************************************************************
	> File Name: 指针相关.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 15时21分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    int64_t temp_num;
    int a = 5, *p = &a;
    char b = 'c', *q = &b;
    printf("%d %d\n", a, *p);
    printf("sizeof(*p) = %lu\n", sizeof(p));
    printf("sizeof(*p) = %lu\n", sizeof(q));
    p = (int *)&temp_num;
    q = (char *)&temp_num;
    p[1] = 0x3f80;
    p[0] = 0;
    printf("%"PRIx64"\n", temp_num);
    double *p_ = (double *)&temp_num;
    *p_ = 1.0;
    printf("%" PRIx64 "\n", temp_num);
    return 0;
}
