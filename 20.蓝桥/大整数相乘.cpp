/*************************************************************************
	> File Name: 大整数相乘.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 12时04分06秒
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
int ans[3000] = {0};
void dashu(char *a, char *b) {
    int len1 = strlen(a), len2 = strlen(b), up = 1;
    if (a[0] == '0' || b[0] == '0') {
        ans[0] = 1;
        return ;
    }
    ans[0] = len1 > len2 ? len1 : len2;
    for (int i = len2 - 1; i >= 0; --i) {
		int ind = 0;
        int *temp = (int *)calloc(sizeof(int), 600);
        for (int j = len1 - 1; j >= 0; --j, ind++) {
			temp[ind] = (b[i] - 48) * (a[j] - 48);			
        }
        while (ind + up - 1 > ans[0]) ans[0]++;
        for (int j = up, index = 0; j < len1 + up; j++, index++) {
			ans[j] += temp[index];
        }
     	for (int k = up; k < ans[0]; k++) {
			if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] = ans[k] % 10;
            if (k == ans[0]) ans[0]++;
        }
        up++;
    }
    return ;
}

int main() {
    ans[0] = 1;
	char A[501], B[501];
    cin >> A >> B;
    dashu(A, B);
    for (int i = ans[0]; i > 0; i--) {
		cout << ans[i];
    }
    return 0;
}
