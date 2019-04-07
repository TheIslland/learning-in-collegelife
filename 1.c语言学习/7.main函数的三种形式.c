/*************************************************************************
	> File Name: main函数的三种形式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 15时42分01秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int main(int argc, char *argv[]) {
    for (int i = 0 ; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}*/


int main(int argc, char *argv[], char *env[]) {
    for (int i = 0 ; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    for (char **p = env; p[0] != NULL; p++) {
        printf("%s\n", p[0]);
    }
    return 0;
}
