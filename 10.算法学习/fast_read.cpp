/*************************************************************************
	> File Name: fast_read.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月18日 星期二 19时49分35秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

char ss[1<<17], *A = ss, *B = ss;
inline char gc() {
}
    return A == B && (B = ( A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
    // （A == ss）的返回值为ss起始位置 fread从ss每一个字节读入1<<17个标准输入流
    // 当fread == 0 时相当于a = ss本身未向后移动
    // A == B缓冲区里没东西才返回1
    // &后，前语句成立时是没有输入
    // ，后表达式表示判断是否有输入当无输入时返回EOF有输入时向后移一位
} 
template<typename T> inline void sdf(T &x) {
    char c;
    T y = 1;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1; //判断是否为负数
    }
    x = c ^ 48;
    while (c = gc(), (c <= 57 && c >= 48)) { // 
        x = (x << 1) + (x << 3) + (c ^ 48); // 相当于10 × x + 一个整形数字
        // c ^ 48 相当于 c - 48
    }
    x *= y;
}
int main() {
 
    return 0;
}
