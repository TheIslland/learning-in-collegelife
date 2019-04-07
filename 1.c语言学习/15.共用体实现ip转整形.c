/*************************************************************************
	> File Name: 共用体实现ip转整形.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 10时07分24秒
 ************************************************************************/
#include <stdio.h>

union IP {
	struct {
		unsigned char arr[4];
    } ip;
	unsigned int num;
};

int main() {
    IP ip;
    int a, b, c, d;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
    	ip.ip.arr[0] = a;
    	ip.ip.arr[1] = b;
    	ip.ip.arr[2] = c; 
        ip.ip.arr[3] = d;
		printf("%d\n", ip.num);
    }
}
