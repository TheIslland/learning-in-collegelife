/*************************************************************************
	> File Name: string_BF.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月04日 星期五 19时48分55秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

int match(char *buffer, char *pattern) {
	for (int i = 0; i < strlen(buffer) - strlen(pattern) + 1; ++i) {
		int j = 0;
        for (; j < strlen(pattern); j++) {
			if (buffer[i + j] != pattern[j]) {
				break;
            }
        }
		if (j == strlen(pattern)) {
        	return i;   
    	}   
    }
    return -1;
}

int main() {
    char buffer[MAXLEN], pattern[MAXLEN];
    scanf("%s%s", buffer, pattern);
    int location = match(buffer, pattern);
    if (location != -1) {
        printf("match success, location is %d\n", location);
    } else {
        printf("match failed!\n");
    }
    return 0;
}
