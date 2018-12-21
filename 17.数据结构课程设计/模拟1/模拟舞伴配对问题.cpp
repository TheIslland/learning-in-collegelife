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
    Queue q_man(MAX_OP);
    Queue q_woman(MAX_OP);
    printf("请输入舞曲轮数\n");
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < 20; i++) {
            int op = rand() % 4, value = rand () % 100;
            switch (op) {
                case 0: break;
                case 1:
                    q_man.push (value);
                    printf("push %d to man queue\n", value);
                    q_man.output();
                    break;
                case 2:
                    q_woman.push (value);
                    printf("push %d to woman queue\n", value);
                    q_woman.output();
                    break;
            }
        }
        while (!q_man.empty() && !q_woman.empty()) {
            int man = q_man.front();
            int woman = q_woman.front();
            printf("男士 %d 与 女士 %d 舞伴配对成功\n", man, woman);
            q_man.pop();
            q_woman.pop();
        }
        printf("\n");
        if (q_man.empty()) printf("男士完全配对\n");
        else {
            printf("配对后男士剩余：");
            q_man.output();
        }
        if (q_woman.empty()) printf("女士完全配对\n");
        else {
            printf("配对后女士剩余：");
            q_woman.output();
        }
        sleep(5);
    }
    q_woman.clear();
    q_man.clear();
    return 0;
}
