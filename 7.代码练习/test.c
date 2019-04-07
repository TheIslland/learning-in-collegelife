/*************************************************************************
	> File Name: test.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月27日 星期二 18时37分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main() {
    char str[100], ans[20];
    int note[600] = {0};
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i += 3) {
        strncpy(ans, str, 3);
    }
    printf("%s\n", ans);
    return 0;
}
