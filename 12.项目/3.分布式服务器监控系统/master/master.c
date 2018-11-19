/*************************************************************************
	> File Name: master.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月13日 星期二 19时39分18秒
 ************************************************************************/

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <errno.h>
#include "shm.h"

typedef struct Node {
    char *IP;
    char port;
} Node;

typedef struct Queue {
    int head, length, tail, cnt;
    Node **data;
} Queue;

Node *getNode (char *ip, int port) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->IP = strdup(ip);
    node->port = port;
    return node; 
}

Queue *init (int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->data = (Node **)malloc(sizeof(Node) * n);
    q->cnt = 0;
    q->head = 0;
    q->tail = -1;
    return q;
}

int push (Queue *q, char *ip, int port) {
    if (q->cnt == q->length) return 0;
    q->tail += 1;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = getNode(ip, port);
    return 1;
}

int empty (Queue *q) {
    return q->cnt == 0;
}

void pop (Queue *q) {
    if (empty(q)) return;
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return ;
}

Node *front (Queue *q) {
    if (empty(q)) return 0;
    return q->data[q->head];
}

/*void clear (Queue *q) {
    if (q == NULL) return ;
    free(q->IP);
    free(q->port);
    free(q);
    return;
}*/

void output (Queue *q) {
    printf("Queue = [");
    for (int i = 0; i < q->cnt; i = (i + 1) % q->length) {
        int ind = (q->head + i) % q->length;
        printf(" %s %d\n", q->data[ind]->IP, q->data[ind]->port);
        i + 1 == q->cnt || printf(",");
    }
    printf("]\n");
    return ;
}

int main(int argc, char *argv[])
{

    Queue *queue[5];
    for (int i = 0; i < 5; i++) {
        queue[i] = init(1000);    
    }
    int fd, new_fd, numbytes,i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[10000];
    int struct_len;
    server_addr.sin_family = AF_INET;
    //sin.family指协议族
    server_addr.sin_port = htons(8765);
    //sin.port存储端口号
    server_addr.sin_addr.s_addr = INADDR_ANY;
    //按照网络字节顺序存储ｉｐ地址
    bzero(&(server_addr.sin_zero), 8);
    //为了让sockeaddr和sockaddr_in两个数据保持大小相同而保留空字节
    struct_len = sizeof(struct sockaddr_in);
    //获取sockaddr缓冲区长度

    fd = socket(AF_INET, SOCK_STREAM, 0);
    //socket函数创建新的套接字，如果创建成功就返回新创建的套接字描述符失败会返回－１
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1);
    //如果绑定成功返回０不成功返回－１无限循环
    printf("Bind Success!\n");
    while(listen(fd, 10) == -1);
    //监听套接字同一时刻监听上限为１０如果成功返回０失败返回－１
    printf("Listening....\n");
    printf("Ready for Accept,Waitting...\n");
    pid_t pid, pid1, pid2, pid3, pid4;
    printf("建立５个对应５个进程的队列\n");
    int num = 0, onli, q = -1;
    int shmid = creat_shm(1000);
    Queue *buf = NULL;
    for (int i = 0; i < 5; i++) {
        q++;
        pid = fork();
        buf = (Queue *)shmat(shmid, NULL, 0);
    }
    while (1) {
    	new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
        //接收连接请求，成功返回客户端的文件描述符，失败返回－１
        num += 1;
        printf("Get the client num is %d:\n", num);
        numbytes = send(new_fd,"Welcome to my server\n",21,0); 
        printf("新增连接按序号入队");
        if (pid != 0) {
            int stat = num % 5;
            char *ip = inet_ntoa(client_addr.sin_addr);
            int port = htons(client_addr.sin_port);
            switch (stat) {
                case 0: {
                    printf("入进程０队列\n");
                    push(queue[0], ip, port); 
                } break;
                case 1: {
                    printf("入进程１队列\n");
                    push(queue[1], ip, port);
                } break;
                case 2: {
                    printf("入进程２队列\n");
                    push(queue[2], ip, port);
                } break;
                case 3: {
                    printf("入进程３队列\n");
                    push(queue[3], ip, port);
                } break;
                case 4: {
                    printf("入进程４队列\n");
                    push(queue[4], ip, port);
                } break;
            }
        } else {
            switch (q) {
                case 0: {
                        
                } break;
                case 1: {

                } break;
                case 2: {

                } break;
                case 3: {
                    
                } break;
                case 4: {

                } break;
            }
        }
        //printf("动态分配用户, 将第i户分配到对长较小队列\n");
        //printf("对应入队\n");
        //printf("当对应队列不为空时顺序出队执行，执行后出队\n");
        //printf("当队列为空时结束循环结束进程\n");
	}
        return 0;
}
