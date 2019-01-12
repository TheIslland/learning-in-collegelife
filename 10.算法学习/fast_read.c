/*************************************************************************
	> File Name: fast_read.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月18日 星期二 19时49分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ss[1<<17], *A = ss, *B = ss
inline char gc() {
    return A == B && (B = ( A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
}
template<typename T> inline void sdf(T &x) {
    char c;
    T y;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1;
    }
    x = c ^ 48;
    while (c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48);
    }
    x *= y;
}
int main() {
 
    return 0;
}
