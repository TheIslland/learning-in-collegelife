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
#include "queue.h"

int main() {
    #define MAX_OP 2018
    srand (time (0));
    Queue *q_man = init(MAX_OP);
    Queue *q_woman = init(MAX_OP);
    while (1) {
        for (int i = 0; i < 20; i++) {
            int op = rand() % 4, value = rand () % 100;
            switch (op) {
                case 0:
                case 1:
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
            int man = front(q_man);
            int woman = front(q_woman);
            printf("男士 %d 与 女士 %d 舞伴配对成功\n", man, woman);
            pop(q_man);
            pop(q_woman);
        }
        sleep(5);
    }
    clear(q_woman);
    clear(q_man);
    return 0;
}
