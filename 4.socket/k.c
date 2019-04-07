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

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("./Client 地址 端口\n");
        exit(1);
    }
    int sockfd, numbytes;
    int port = atoi(argv[2]); // int型 端口
    char *host = argv[1]; // 地址
    char buf[BUFSIZ];
    struct sockaddr_in server_addr;
    printf("请等待30s后退出......\n");
    while((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // 创建一个socket
    printf("准备访问......\n");

    server_addr.sin_family = AF_INET; // 初始化服务器地址
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);
    bzero(&(server_addr.sin_zero), 8);
    
    while(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1); // 链接服务器
    /*numbytes = recv(sockfd, buf, BUFSIZ, 0); // 接收服务器端信息  
    buf[numbytes] = '\0';  
    printf("%s", buf);*/
    char *str = argv[3];
    FILE *fd; 
    fd = fopen(str, "r");
    while(1) {
        printf("发送:");
        /*scanf("%[^\n]s", buf);
        getchar();
        send(sockfd, buf, strlen(buf), 0);*/
        /*if ((numbytes = recv(sockfd, buf, BUFSIZ, 0)) > 0) { // 接收服务器返回的数据  
            buf[numbytes] = '\0'; 
            printf("发送成功,对方接受到：%s\n", buf);  
        } else {
            printf("发送失败\n");
        }*/
        char data[BUFSIZ];
        fread(data, sizeof(char), sizeof(data), fd);
        buf[0] = strlen(str) + '0';
        strncpy(buf + 1, str, 100);
        strncpy(buf + 1 + strlen(str), data, strlen(data));
        send(sockfd, buf, strlen(buf), 0);
        fclose(fd);
        break;
    }
    close(sockfd);
    return 0;
}

