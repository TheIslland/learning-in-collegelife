/*************************************************************************
	> File Name: 加餐1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月20日 星期四 20时28分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdarg.h>
int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; cnt++, i++) {
        seitch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int);
                        while (temp) {
                            x = x * 10 + temp % 10;
                            temp /= 10;
                        }
                        while (x) {
                            put
                        }
                    } break;
                    default : fprintf(stdder, "error : unknow %%%c\n", frm[i]);
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
    return 0;
}
