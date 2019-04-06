/*************************************************************************
	> File Name: 捡水果.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年04月06日 星期六 22时04分09秒
 ************************************************************************/

#include <stdio.h>
#define MAX 101
int d[MAX][MAX];
int maxsum[MAX][MAX];
int n;
int max(int x, int y) {
	if(x > y) return x;
	else return y;
}

int Maxsum(int i,int j) {
	if(maxsum[i][j] != -1) return maxsum[i][j];
	if(i == n) maxsum[i][j]=d[i][j];
	else {
		int x = Maxsum(i + 1, j);
		int y = Maxsum(i + 1, j + 1);
		maxsum[i][j] = max(x, y) + d[i][j];
	}
	return 	maxsum[i][j];	
}
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
	    	scanf("%d", &d[i][j]);
	    	maxsum[i][j] = -1; 
		} 
	}
    printf("%d\n", Maxsum(1,1));
    return 0;
}

