/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月05日 星期五 20时05分30秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 256;

char* get_letter(void) {
    static char letter[1000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    }
    return letter;
}

int main() {
    char *str = get_letter();

    // 在此处添加你的代码
    char sep[] = " \t\n\r\n\"',.";
    char str1[256];
    strcpy(str1, str);
    char *temp = strtok(str1, sep);
    int num = 0;
    char cmp[] = "love";
    while (temp) {
		printf("%s\n", temp);
        if (strcmp(temp, cmp) == 0) num++;
        temp = strtok(NULL, sep);
    }
    printf("%d\n", num);
    puts(str);
    return 0;
}

#undef MAX_LENGTH

