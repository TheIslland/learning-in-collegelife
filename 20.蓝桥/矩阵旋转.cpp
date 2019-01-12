/*************************************************************************
	> File Name: 矩阵旋转.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 10时34分26秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[200][200] = {0};
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[j][n - i - 1]);
        }
    }
    for (int i = 0 ; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", a[i][j]);
            if (j < n -1) printf(" ");
        }
        printf("\n");
    }
	return 0;
}
