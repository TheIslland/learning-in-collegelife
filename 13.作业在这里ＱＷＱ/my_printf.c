/*************************************************************************
	> File Name: my_printf.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月20日 星期四 20时45分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int64_t temp = va_arg(arg, int), x = 0, num = 0, judg = 0;
                        char y[1000];
                        if (temp < 0) {
                            judg = 1;
                            temp = -temp;
                        }
                        while (temp) {
                            y[num++] = temp % 10 + '0';
                            temp /= 10;
                        }
                        num--;
                        if (judg) {
                            putchar('-');
                        }
                        while (num >=0 ) {
                            putchar(y[num]);
                            num--;
                        }
                    } break;
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]); 
                        exit(1);
                }
            } break;
            default:
                putchar(frm[i]);
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 101);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
