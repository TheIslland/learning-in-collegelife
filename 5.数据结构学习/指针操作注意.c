/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月12日 星期五 17时17分53秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i, (*b)[4];
    for (i = 0; i< 2; i++) {
        b = a + i;
        //注意数组指针ｂ是从ａ的首地址加ｉ行后的内容开始存储
        printf("%d \n", *(b[i] + 1));
        for (int k = 0; k < 3; k++) {
            for (int j = 0 ; j < 4; j++) {
                printf("%d ", *(b[k] + j));
            }
            printf("\n");
        }
    }
    return 0;
}
