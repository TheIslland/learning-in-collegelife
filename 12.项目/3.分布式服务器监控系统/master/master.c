/*************************************************************************
	> File Name: master.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月20日 星期二 17时49分23秒
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
#include <errno.h>
#include <pthread.h>

typedef struct Node {
    char *IP;
    int port;
} Node;

typedef struct Queue {
    int head, length, tail, cnt, flag;
    Node **data;
    pthread_mutex_t  mutex;
    pthread_cond_t is_full;
    pthread_cond_t is_empty;
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
    q->flag = 0;
    pthread_mutex_init(&q->mutex, NULL);
    pthread_cond_init(&q->is_full, NULL);
    pthread_cond_init(&q->is_empty, NULL);
    return q;
}

int push (Queue *q, char *ip, int port) {
    if (pthread_mutex_lock(&q->mutex) != 0) {
        return -1;       
    }
	while (q->cnt == q->length) {
		pthread_cond_wait(&q->is_full, &q->mutex);	
    }
    //if (q->cnt == q->length) return 0;
    q->tail += 1;
    if (q->tail >= q->length) q->tail -= q->length;
    q->cnt += 1;
    q->data[q->tail] = getNode(ip, port);
    pthread_cond_signal(&q->is_empty);
    if (pthread_mutex_unlock(&q->mutex) != 0) {
		return -1;
    }
    return 1;
}

int empty (Queue *q) {
    return q->cnt == 0;
}

int run (Queue *q) {
    return q->flag;
}

Node *pop (Queue *q) {
    if (pthread_mutex_lock(&q->mutex) != 0) {
		return (Node *)-1;
    }
    //if (empty(q)) return;
	while (empty(q)) {
		pthread_cond_wait(&q->is_empty, &q->mutex);	
    }
    Node *ret = q->data[q->head];
    q->head += 1;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    pthread_cond_signal(&q->is_full);
    if (pthread_mutex_unlock(&q->mutex) != 0) {
		return (Node *)-1;
    }
    return ret;
}


Node *front (Queue *q) {
    if (pthread_mutex_lock(&q->mutex) != 0) {
		return (Node *)-1;
    }
    if (empty(q)) return 0;
    Node *ret = q->data[q->head];
    if (pthread_mutex_unlock(&q->mutex) != 0) {
		return (Node *)-1;
    }
    return ret;
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

void *func(void *arg) {
    while (1) {
    Queue *q = (Queue *)arg;
    if (empty(q)) continue;
    Node *temp = pop(q);
    if (empty(q)) printf("empty\n");
    printf("ip = %s port = %d\n", temp->IP, temp->port);
    long long ans = pthread_self();
    printf("线程　%lld", ans);
    output(q);
    sleep(2);
    }
}

void 

int main(int argc, char *argv[])
{

    Queue *queue = init(1000);    
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
    printf("建立５个线程\n");
    int num = 0, onli, q = -1;
    pthread_t t[5];
    for (int i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, func, (void *)queue);
    }
    while (1) {
    	new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
        //接收连接请求，成功返回客户端的文件描述符，失败返回－１
        num += 1;
        printf("Get the client num is %d:\n", num);
        numbytes = send(new_fd,"Welcome to my server\n",21,0); 
        printf("新增连接按序号入队");
        //有新连接就进入队列
        char *ip = inet_ntoa(client_addr.sin_addr);
        int port = htons(client_addr.sin_port);
        push(queue, ip, port);
        //开５个线程不关，队列空就阻塞，队列不空就提取出队
    }
    close(fd);
    return 0;
}
