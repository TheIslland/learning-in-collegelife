/*************************************************************************
	> File Name: test1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 17时42分30秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g;
    for(a = 1; a <= 9; a++) {
        for(b = 0; b <= 9; b++) {
            if(a == b) continue;
            for(c = 0; c <= 9; c++) {
                if(a == c || b == c) continue;
                for(d = 0; d <= 9; d++) {
                    if(a ==d || b == d || c == d) continue;
                    for(e = 1; e <= 9; e++) {
                        if(a == e || b == e || c ==e || d == e) continue;
                        for(f = 0; f <= 9; f++) {
                            if(a == f || b == f || c == f || d  == f || e == f) continue;
                            for(g = 0; g <= 9; g++) {
                                if(a == g || b == g || c == g || d == g || f == g || e == g) continue;
                                int x = a * 1000 + b * 100 + c * 10 + d;
                                int y = e * 100 + f * 10 + g;
                                int z = e * 1000 + g * 100 + a * 10 + b;
                                if(z == y + x && a != b && b != c  && c != d && d != e && e != f && f != g) {
                                    printf("%d %d\n", x, y);
                                    //return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
