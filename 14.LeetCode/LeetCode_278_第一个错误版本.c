/*************************************************************************
	> File Name: LeetCode_278_第一个错误版本.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月08日 星期四 17时23分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1, r = n;
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (isBadVersion(mid)) r = mid - 1;
        else l = mid;
    }
    return mid;
}
int main() {
 
return 0;
}
