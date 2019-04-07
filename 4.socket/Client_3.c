/*************************************************************************
	> File Name: h.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月23日 星期日 16时21分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>

void func(char *str, char *m, int sockfd) {
    char buf[BUFSIZ] = {0};
    char data[1000] = {0};
	FILE *fp = popen(m, "r");
    fread(data, sizeof(char), sizeof(data), fp);
    buf[0] = strlen(str) + '0';
    strncpy(buf + 1, str, strlen(str));
    strncpy(buf + 1 + strlen(str), data, strlen(data));
    send(sockfd, buf, strlen(buf), 0);
    pclose(fp);
    return ;
}


int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    int port = atoi(argv[2]); // int型 端口
    char *host = argv[1]; // 地址
    struct sockaddr_in server_addr;
    printf("请等待30s后退出......\n");
    while((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // 创建一个socket
    printf("准备访问......\n");

    server_addr.sin_family = AF_INET; // 初始化服务器地址
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);
    bzero(&(server_addr.sin_zero), 8);
    
    while(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1); // 链接服务器
	while(1) {
        printf("发送:\n");
        func("cpu.log", "./cpu_occupy.sh", sockfd);
        func("mem.log", "./MEM.sh", sockfd);
        func("disk.log", "./DISK.sh", sockfd);
        sleep(5);
    }
    close(sockfd);
    return 0;
}

