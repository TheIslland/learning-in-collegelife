/*************************************************************************
	> File Name: 模拟舞伴配对问题.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月21日 星期五 17时28分31秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "queue.h"

using namespace std;

int main() {
    #define MAX_OP 2018
    int n;
    srand (time (0));
    Queue_operation q;
    Queue *q_man = q.init(MAX_OP);
    Queue *q_woman = q.init(MAX_OP);
    printf("请输入舞曲轮数\n");
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 20; i++) {
            int op = rand() % 4, value = rand () % 100;
            switch (op) {
                case 0: break;
                case 1:
                    q.push (q_man, value);
                    printf("push %d to man queue\n", value);
                    q.output(q_man);
                    break;
                case 2:
                    q.push (q_woman, value);
                    printf("push %d to woman queue\n", value);
                    q.output(q_woman);
                    break;
            }
        }
        while (!q.empty(q_man) && !q.empty(q_woman)) {
            int man = q.front(q_man);
            int woman = q.front(q_woman);
            printf("男士 %d 与 女士 %d 舞伴配对成功\n", man, woman);
            q.pop(q_man);
            q.pop(q_woman);
        }
        printf("\n");
        if (q.empty(q_man)) printf("男士完全配对\n");
        else {
            printf("配对后男士剩余：");
            q.output(q_man);
        }
        if (q.empty(q_woman)) printf("女士完全配对\n");
        else {
            printf("配对后女士剩余：");
            q.output(q_woman);
        }
        sleep(5);
    }
    q.clear(q_woman);
    q.clear(q_man);
    return 0;
}
