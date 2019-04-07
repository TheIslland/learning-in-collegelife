/*************************************************************************
	> File Name: k.c
	> Author: x
	> Mail: x.com
	> Created Time: 2018年09月23日 星期日 16时36分46秒
 ************************************************************************/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd, new_fd, struct_len, numbytes, i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[BUFSIZ]; // 缓冲区

    server_addr.sin_family = AF_INET; // IP地址
    server_addr.sin_port = htons(8000); // 端口
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8); // 地址族协议
    struct_len = sizeof(struct sockaddr_in);

    fd = socket(AF_INET, SOCK_STREAM, 0); // socket
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1); // bind 绑定
    printf("绑定成功\n");
    while(listen(fd, 10) == -1); // 进入监听状态
    printf("正在监听中......\n");
    int connect;
    pid_t pid;
    while(1) {
        connect = accept(fd, (struct sockaddr *)&client_addr, &struct_len); // 接收客户请求
        printf("出现访客\n");

        numbytes = send(new_fd, "欢迎,祝您愉快!\n", 21, 0);
        pid = fork();
        if (pid == -1) {
            printf("fork出错\n");
        } else if (pid == 0) {
            close(fd);
            char IP[100];
            int port;
            while((numbytes = recv(connect, buff, BUFSIZ, 0)) > 0) { // 接收数据
                strcpy(IP, inet_ntoa(client_addr.sin_addr)); 
                port = htons(client_addr.sin_port);
                printf("%s %d: %s\n", inet_ntoa(client_addr.sin_addr), htons(client_addr.sin_port), buff);
                char filename[200] = {0}, data[BUFSIZ] = {0};
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
            printf("访客\"%s %d\"退出\n", IP, port);
            exit(EXIT_SUCCESS);
        } else {
            close(connect);
        }
    }
    return 0;
}
