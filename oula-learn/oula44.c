/*************************************************************************
	> File Name: oula44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时53分03秒
 ************************************************************************/

#include<stdio.h>
#incldue<inttypes.h>
int64_t Pentagonal(int64_t n ) {
    return n * (3 * n - 1) / 2;
}
int64_t is_Pentagonal(int64_t x) {
    int64_t head = 1, tail = 10000, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(Pentagonal(mid) == x) return 1;
        if(Pentagonal(mid) > x) tail = mid - 1;
        if(Pentagonal(mid) < x) head = mid + 1;
    }
    return 0;
}
int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while(Pentagonal(j + 1) - Pentagonal(j) < ans) {
        j++;
        i = j - 1;
        do {
            if(is_Pentagonal(Pentagonal(i) + Pentagonal(j))) {
                if(is_Pentagonal(Pentagonal(j) - Pentagonal(i))) {
                    if(Pentagonal(j) - Pentagonal(i) < ans) {
                        ans = Pentagonal(j) - Pentagonal(i);
                    }
                }
            }
            i--;
        } while(i >= 1 && Pentagonal(j) - Pentagonal(i) < ans);
    }
    return 0;
}
