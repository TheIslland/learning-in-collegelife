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

#define BUFSIZE 1000

typedef struct H_Node {
    char *ip;
    int flag;
    struct H_Node *next;
}H_Node;

typedef struct Hashtable {
    H_Node **data;
    int size;
    pthread_mutex_t mutex;    
} Hashtable;

H_Node *init_H_Node (char *str, H_Node *head) {
    H_Node *node = (H_Node *)malloc(sizeof(H_Node));
    node->ip = strdup(str);
    node->flag = 1;
    node->next = head;
    return node;
}

Hashtable *init_hashtable (int n) {
    Hashtable *h = (Hashtable *)malloc(sizeof(Hashtable));
    h->size = n << 1;
    h->data = (H_Node **)calloc(sizeof(H_Node *), h->size);
    return h;
}

unsigned int APHash(char *str) {
    unsigned int hash = 0;
    int i;  
    for(i = 0; *str; i++) {
        if((i & 1) == 0) {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }      
    return hash;
}

int Hashtable_insert (Hashtable *h, char *str) {
    unsigned int hash = APHash(str);
    unsigned int ind = hash % h->size;
    H_Node *p = h->data[ind];
    while (p && strcmp(p->ip, str)) p = p->next;
    if (p != NULL && p->flag == 1) return 0;
    h->data[ind] = init_H_Node(str, h->data[ind]);
    return 1;
}

void change_Hashtable (Hashtable *h, char *str) {
    unsigned int hash = APHash(str);
    unsigned int ind = hash % h->size;
    H_Node *p = h->data[ind];    
    while (p && strcmp(p->ip, str)) p = p->next;
    if (p != NULL) p->flag = 0;
    return ;
}

void clear_node(H_Node *node) {
    if (!node) return ;
    H_Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->ip);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(Hashtable *h) {
    if (!h) return ;
    for (int i = 0; i < h->size; i++) clear_node(h->data[i]);
    free(h->data);
    free(h);
    return ;
}

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

typedef struct Var {
    Hashtable *h;
    Queue *q;
} Var;

int get_IP(char *filename, int cnt, char *v) {
    FILE *fd = fopen(filename, "r");
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int i = 0;
    while ((read = getline(&line, &len, fd)) != -1) {
        if (i == cnt) {
            strncpy(v, line, strlen(line) - 1);
        }
        i++;
    }
    free(line);
    fclose(fd);
    return 0;
}

int soc_con(char *IP, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // 创建一个socket
    if (sockfd < 0) return -1;
    server_addr.sin_family = AF_INET; // 初始化服务器地址
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    bzero(&(server_addr.sin_zero), 8);
    int k = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
    if (k < 0) return -1;
    return sockfd;
}

void *func1(void *arg) {
    int warn, new_warn, struct_len;
    struct sockaddr_in warn_addr;
    struct sockaddr_in connect_warn;
    char buff[10000];
    warn_addr.sin_family = AF_INET;
    //sin.family指协议族
    warn_addr.sin_port = htons(8536);
    //sin.port存储端口号
    warn_addr.sin_addr.s_addr = INADDR_ANY;
    //按照网络字节顺序存储ｉｐ地址
    bzero(&(warn_addr.sin_zero), 8);
    //为了让sockeaddr和sockaddr_in两个数据保持大小相同而保留空字节
    struct_len = sizeof(struct sockaddr_in);
    //获取sockaddr缓冲区长度
    warn = socket(AF_INET, SOCK_STREAM, 0);
    //socket函数创建新的套接字，如果创建成功就返回新创建的套接字描述符失败会返回－１
    while(bind(warn, (struct sockaddr *)&warn_addr, struct_len) == -1);
    //如果绑定成功返回０不成功返回－１无限循环
    printf("warn Bind Success!\n");
    while(listen(warn, 10) == -1);
    while (1) {
        int numbytes;
    	new_warn = accept(warn, (struct sockaddr *)&connect_warn, &struct_len);
        char *IP = inet_ntoa(connect_warn.sin_addr);
        if ((numbytes = recv(new_warn, buff, BUFSIZE, 0)) > 0) { // 接收数据
            char filename[200] = {0}, data[BUFSIZE] = {0};
            /*int t = buff[0] - '0', k = strlen(IP);
            strncpy(filename, IP, k);
            filename[k] = '/';
            strncpy(filename + 1 + k, buff + 1, t);
            strncpy(data, buff + 1 + t, strlen(buff + 1 + t));*/
            FILE *fd;
            fd = fopen("client_warn_information", "a+");
            fwrite(buff, sizeof(char), strlen(buff), fd);
            fclose(fd);
            memset(buff, 0, sizeof(buff));
        }    
    }
    sleep(2);
}

void *func(void *arg) {
    while (1) {
        Var *var = (Var *)arg;
        Queue *q = var->q;
        Hashtable *h = var->h;
        printf("wait, because queue is empty\n");
        if (empty(q)) {
            sleep(2);
            continue;
        }
        printf("queue is not empty\n");
        Node *temp = pop(q);
        int con_fd = soc_con(temp->IP, temp->port);
        if (con_fd < 0) {
        	change_Hashtable(h, temp->IP);
            printf("Device --> ip = %s  is not online, change IP state\n", temp->IP);
            continue;
        } else {
            printf("Device --> ip = %s online, start connect...\n", temp->IP);
        }
		char IP[100];
        int port, numbytes;
        char buff[BUFSIZE] = {0};
        strcpy(IP, temp->IP); 
        port = temp->port;
        printf("connect IP = %s...\n", temp->IP);
        while((numbytes = recv(con_fd, buff, BUFSIZE, 0)) > 0) { // 接收数据
            char filename[200] = {0}, data[BUFSIZE] = {0};
            int t = buff[0] - '0', k = strlen(IP);
            mkdir(IP, 0775); // 同linux mkdir建立目录后的权限一致
            strncpy(filename, IP, k);
            filename[k] = '/';
            strncpy(filename + 1 + k, buff + 1, t);
            strncpy(data, buff + 1 + t, strlen(buff + 1 + t));
            FILE *fd;
            fd = fopen(filename, "a+");
            fwrite(data, sizeof(char), strlen(data), fd);
            fclose(fd);
            memset(buff, 0, sizeof(buff));
        }    
        printf("Link ans related operation completed\n");
        	long long ans = pthread_self();
        	printf("线程　:%lld", ans);
        	printf("ip = %s port = %d\n", temp->IP, temp->port);
        	change_Hashtable(h, temp->IP);
        	printf("线程　:%lld", ans);
        	output(q);
        	printf("\n");
        	sleep(5);
    }
}

int main(int argc, char *argv[]) {
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
    Hashtable *hashtable = init_hashtable(2000);
    for (int i = 0; i < 5; i++) {
        char temp_IP[100] = {0};
        char temp_port[4] = {0};
        get_IP("IP.conf", i, temp_IP);
        get_IP("PORT.conf", i, temp_port);
        if (Hashtable_insert(hashtable, temp_IP)) {
            push(queue, temp_IP, atoi(temp_port));
        }
    }
	Var *var = (Var *)malloc(sizeof(Var));
    var->h = hashtable;
    var->q = queue;
    int local_port[1] = {8536}; 
	pthread_t t[5];
    pthread_t w;
    pthread_create(&w, NULL, func1, (void *)local_port );
    for (int i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, func, (void *)var);
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
        int port = 8432;
        if (Hashtable_insert(hashtable, ip)) {
            push(queue, ip, port);
            printf("ip:%s push Success!\n", ip);
        } else {
            printf("ip:%s already push into the  queue!\n", ip);
        }
        //开５个线程不关，队列空就阻塞，队列不空就提取出队
    }
    close(fd);
    return 0;
}
