/*************************************************************************
	> File Name: oula11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 14时26分11秒
 ************************************************************************/

#include<stdio.h>
int dric[4][2] = {1,1,1,-1,0,1,1,0};
int main() {
    int max[30][30] = {0};
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            scanf("%d",max[i] + j);
        }
    }
    int ans = 0;
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            for(int k = 0; k < 4; k++) {
                int p = 1;
                for(int step = 0; step < 4; step++) {
                    int xx = i + step * dric[k][0];
                    int yy = j + step * dric[k][1];
                    p *= max[xx][yy];
                }
                if(p > ans) ans = p;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
