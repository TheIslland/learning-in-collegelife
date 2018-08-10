/*************************************************************************
	> File Name: oula14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 15时11分17秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 1000000
int sequ[MAX_N + 5] = {0};
//设计和读取一个递归函数最重要的环节是给予一个递归函数一个明确的语义信息
int get_lence(int64_t x) {
    if(x == 1) return 1;
    if(x <= MAX_N && sequ[x])
    return sequ[x];
    int temp_ans;
    if(x & 1) 
     temp_ans = get_lence(x * 3 + 1) + 1;
    else
     temp_ans = get_lence(x / 2) + 1;//x >> 1相当于 x / 2
    if(x <= MAX_N ) sequ[x] = temp_ans;
    return temp_ans;
}
int main() {
    int ans = 0,ans_length = 0;
    for(int i = 1; i < MAX_N; i++) {
        int temp_length = get_lence(i);
        if(temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n",ans,ans_length);
    return 0;
}
