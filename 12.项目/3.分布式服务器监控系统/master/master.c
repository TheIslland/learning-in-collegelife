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
#include "../common/function.h"

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid > 0) exit(0);
    Queue *queue = init(1000);    
    int fd, new_fd, numbytes,i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[10000];
    int struct_len;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8765);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);
    struct_len = sizeof(struct sockaddr_in);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1);
    printf("Bind Success!\n");
    while(listen(fd, 10) == -1);
    printf("Listening....\n");
    printf("Ready for Accept,Waitting...\n");
    printf("建立10个线程\n");
    int num = 0, onli, q = -1;
    Hashtable *hashtable = init_hashtable(2000);
    for (int i = 0; i < 5; i++) {
        char temp_IP[100] = {0};
        char temp_port[4] = {0};
        get_conf_value("/etc/pihealthd.conf", "IP", temp_IP);
        get_conf_value("/etc/pihealthd.conf", "PORT", temp_port);
        if (Hashtable_insert(hashtable, temp_IP)) {
            push(queue, temp_IP, atoi(temp_port));
        }
    }
	Var *var = (Var *)malloc(sizeof(Var));
    var->h = hashtable;
    var->q = queue;
	pthread_t t[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&t[i], NULL, func, (void *)var);
    }
    while (1) {
    	new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
        num += 1;
        printf("Get the client num is %d:\n", num);
        numbytes = send(new_fd,"Welcome to my server\n",21,0); 
        printf("新增连接按序号入队");
        char *ip = inet_ntoa(client_addr.sin_addr);
        int port = 8432;
        if (Hashtable_insert(hashtable, ip)) {
            push(queue, ip, port);
            printf("ip:%s push Success!\n", ip);
        } else {
            printf("ip:%s already push into the  queue!\n", ip);
        }
    }
    close(fd);
    return 0;
}
