# c语言程序设计

## 如何输出6个整数

```c
#include<stdio.h>
int main() {
	int n;
    while(scanf("%d",&n) != EOf) {
		FILE *fin = fopen("/dev/null","w");
        printf("%d has %d digits\n",n,fprintf(fout, "%d",n));
        printf("has %d dights\n",printf("%d",n));
    }
    return 0;
}
```

## 当一个表达式没有返回值或有意义的返回值时采取（表达式，1）赋值给表达式一个返回值