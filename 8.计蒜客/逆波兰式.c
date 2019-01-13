/*************************************************************************
	> File Name: 逆波兰式.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月13日 星期日 15时01分19秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;

int getNum(char *str, int *ret) {
    int i = 0, num = 0;
    while(str[i] <= '9' && str[i] >= '0') {
        num = num * 10 + str[i++] - '0';
    }
    *ret = num;
    return i;
}

int getTerm(char *str, int *ret) {
    int i = 0, temp;
    if(str[i] == 0) return 0;
    i += getNum(str + i, ret);//先获得一个数字
    if(str[i] == 0) return i;//如果到结尾返回处理了多少个字符
    while(str[i]) {
        //i += getNum(str + i + 1, & temp) + 1;
        switch (str[i]) {
            case '*' :  {
                int temp;
                i += getNum(str + i + 1, &temp) + 1;//计算本层处理了多少个字符+1表示符号位
                *ret *= temp;
            } break;
            case '/' : {
                int temp;
                i += getNum(str + i + 1, &temp) + 1;
                *ret /= temp;
            } break;
            default : return i;
        }
    }
    return i;
}

int calc(char *str) { //给我们一个表达式并计算值处理加减法
    int i = 0, a, b;
    char op;
    if(str[i] == 0) return 0;
    i += getTerm(str + i, &a);//处理乘法除法
    if(str[i] == 0) return a;
    while(str[i]) {
        op = str[i];
        i += getTerm(str + i + 1, &b) + 1;
        switch (op) {
            case '+' :  a += b; break;
            case '-' :  a -= b; break;
        }
    }
    return a;
}

int main() {
    char str[1000];
    scanf("%s", str);
    printf("%d\n", calc(str));
    return 0;
}
