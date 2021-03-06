/*************************************************************************
	> File Name: socket_client1.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月25日 星期二 19时42分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include<time.h> 
#define MAXSIZE 4096

void sys_err(const char *ptr,int num)
{
    perror(ptr);
    exit(num);
}

void transport(int sockfd, char *name, char *process) {
		char data[MAXSIZE] = {0};
        char buf[MAXSIZE] = {0};
        FILE *fd;
        //char process[10] = "MEM.log";
        fd = popen(process, "r");
        fread(data, sizeof(char), sizeof(data), fd);
        buf[0] = strlen(name) + '0';
        int t = buf[0] - '0';
        strncpy(buf + 1, name, t);
        strncpy(buf + 1 + strlen(name), data, strlen(data));
        send(sockfd, buf, strlen(buf), 0);
        //memset(buf, '\0', sizeof(buf));
        pclose(fd);
}
int main(int argc,char **argv)
 {
    int sockfd;
    //char buf[MAXSIZE];
    struct sockaddr_in addr;
    int SERV_PORT = atoi(argv[1]);
    char *IP = argv[2];
    //建立socket套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        sys_err("socket",-1);

    //bzero(&addr,sizeof(addr));

    //初始化ip+port
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERV_PORT);
    addr.sin_addr.s_addr = inet_addr(IP);
    bzero(&(addr.sin_zero), 8);
    //connect将sockfd套接字描述符与服务器端的ip+port联系起来
    if(connect(sockfd,(struct sockaddr *)&addr,sizeof(addr)) < 0)
        sys_err("connect",-2);
    while(1) {
    printf("send\n");
	transport(sockfd, "CPU.log", "./cpu_occupy.sh");
    sleep(1);
    transport(sockfd, "MEM.log", "./MEM.sh");
    sleep(1);
    transport(sockfd, "DISK.log", "./DISK.sh");
    sleep(5);
    }
    close(sockfd);
    return 0;
 }
