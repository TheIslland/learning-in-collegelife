/*************************************************************************
	> File Name: 高精度加法.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 09时08分44秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
void func(char *temp, int *ans) {
    int len = strlen(temp);
    if (len > ans[0]) ans[0] = len;
    for (int i = 1; i <= len; i++) {
        ans[i] += temp[len - i] - '0';
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[0] += (i == ans[0]);
    }
    return ;
}
void output(int *ans) {
    int flag = 0;
    for (int i = ans[0]; i > 0; i--) {
        if (!flag && ans[i] == 0) continue;
        flag = 1;
        printf("%d", ans[i]);
    }
    if (!flag) printf("0");
    return ;
}
int main() {
    int n, ind = 0;
    scanf("%d", &n);
    while (n--) {
    ind++;
    char temp1[2000] = {0}, temp2[2000];
    int ans[2000] = {0};
    scanf("%s %s", temp1, temp2);
    func(temp1, ans);
    func(temp2, ans);
    if (ind > 1) printf("\n");
    printf("Case %d:\n", ind);
    printf("%s + %s = ", temp1, temp2);
    output(ans);
    printf("\n");
    }
    return 0;
}
