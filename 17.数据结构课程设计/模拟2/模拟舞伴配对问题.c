/*************************************************************************
	> File Name: 模拟舞伴配对问题.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月16日 星期日 17时50分04秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Heap.h"

int main() {
    #define MAX_OP 2018
    srand (time (0));
    Heap *q_man = (Heap *)malloc(sizeof(Heap));
    Heap *q_woman = (Heap *)malloc(sizeof(Heap));
    init(q_man, MAX_OP);
    init(q_woman, MAX_OP);
    while (1) {
        for (int i = 0; i < 20; i++) {
            int op = rand() % 4, value = rand () % 100;
            switch (op) {
                case 0: break;
                case 1: break;
                case 2:
                    push (q_man, value);
                    printf("push %d to man queue\n", value);
                    output(q_man);
                    break;
                case 3:
                    push (q_woman, value);
                    printf("push %d to woman queue\n", value);
                    output(q_woman);
                    break;
            }
        }
        while (!empty(q_man) && !empty(q_woman)) {
            int man = top(q_man);
            int woman = top(q_woman);
            printf("男士 %d 与 女士 %d 舞伴配对成功\n", man, woman);
            pop(q_man);
            pop(q_woman);
        }
        printf("\n\n\n");
        printf("配对后男士剩余：");
        output(q_man);
        printf("配对后女士剩余：");
        output(q_woman);
        sleep(4);
    }
    clear(q_woman);
    clear(q_man);
    return 0;
}
