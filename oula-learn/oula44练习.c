/*************************************************************************
	> File Name: oula44练习.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 14时04分30秒
 ************************************************************************/

#include<stdio.h>
int cube(int x) {
    return x * x * x;    //求立方
}
int judg_cube(int x) {
    int left = 0, right = x;
    if(x < 0) {
        left = -x, right = 0;//判断x是否为负数，负数左右改为本行
    }
    while(right >= left) {
        int mid = (left + right) / 2;//求中间值
        if(cube(mid) == x)
            return 1;//如果相等代表找到
        if(cube(mid) > x)
            right = mid -1;//中间值较大更新右边界
        if(cube(mid) < x) 
            left = mid + 1;//中间值较小更新左边界
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    if(judg_cube(n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
