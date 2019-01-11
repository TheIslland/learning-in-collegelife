/*************************************************************************
	> File Name: A+B问题.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 16时27分48秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c[1000] = {0};
void dashu(char *str) {
    if (strlen(str) > c[0]) c[0] = strlen(str);
	int ind = 1;
    for (int i = strlen(str) - 1; i >= 0; --i, ind++) {
        c[ind] += str[i] - 48;
    }
    for (int j = 1; j <= c[0]; j++) {
		if (c[j] < 10) continue;
			c[j + 1] += c[j] / 10;
        	c[j] = c[j] % 10;
        	if (j == c[0]) c[0] += 1;
    }
}

int main() {
    char a[501], b[501];
	scanf("%s", a);
    scanf("%s", b);
    dashu(a);
    dashu(b);
    for (int i = c[0]; i > 0; i--) {
		printf("%d", c[i]);
    }
	return 0;
}
