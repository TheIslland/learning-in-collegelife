/*************************************************************************
	> File Name: make_input.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月21日 星期四 15时50分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    FILE *file;
    file = fopen("input", "w");
    int n = 300;
    while (n--) {
        fprintf(file, "%d %d\n", rand() % 2, rand() % 100);
    }
    fclose(file);
    return 0;
}
