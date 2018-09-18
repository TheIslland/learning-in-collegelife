/*************************************************************************
	> File Name: 回文整数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月18日 星期二 19时25分10秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
bool isPalindrome(int x) {
    if (__builtin_expect(!!(x < 0), 0)) return false;
    // #define likely(x) __builtin_expect(!!(X), 1);
    // #define unlikely(x) __builtin_expect(!!(x), 0);
    // likely 是经常成立 unlikely 是不经常成立，为什么写这两局呢？
    // 人工判断后写入判断进行提速
    // 因为省略了系统预测提取进程从而提速
    int y = 0, z = x;
    while (z) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return z == y;
}
int main() {
 
return 0;
}
