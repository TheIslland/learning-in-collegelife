/*************************************************************************
	> File Name: oula45.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时12分47秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
typedef int64_t int1;
int1 Triangle(int1 n) {
    return n * (n + 1) / 2;
}
int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}
int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}
int1 binary_search(int1 (*num)(int1), int1 n, int1 x) {
    int1 head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(num(mid) == x) return mid;
        if(num(mid) > x) tail = tail - 1;
        else head = head + 1;
    }
    return -1;
}
int main() {
    int1 n = 144;
    while(binary_search(Pentagonal,2 * n, Hexagonal(n)) == -1 ) ++n;
    printf("%" PRId64 "\n",Hexagonal(n));
    return 0;
}
