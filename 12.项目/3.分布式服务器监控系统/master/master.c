/*************************************************************************
	> File Name: master.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年11月13日 星期二 19时39分18秒
 ************************************************************************/

#include <sys/stat.h>
#include <fcntl.h>
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

int main(int argc, char *argv[])
{
    int fd, new_fd, numbytes,i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[10000];
    int struct_len;
    printf("socket函数创建新的套接字\n");
    printf("create Success\n");
    printf("绑定套接字\n");
    //如果绑定成功返回０不成功返回－１无限循环
    printf("Bind Success!\n");
    printf("监听套接字并发数为5\n");
    //监听套接字同一时刻监听上限为１０如果成功返回０失败返回－１
    printf("Listening....\n");
    printf("Ready for Accept,Waitting...\n");
    pid_t pid1, pid2, pid3, pid4, pid5;
    printf("读取配置文件获取并行总数\n");
    printf("\n");
    printf("创建5个队列对应5个进程\n");
    printf("开启５个进程\n");
    printf("一个死循环\n");
    int n = 0;
    while (1) {
        n++;
        //new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
        printf("接收连接请求,第%d个用户连接\n", n);
        //接收连接请求，成功返回客户端的文件描述符，失败返回－１
        printf("动态分配用户, 将第i户分配到对长较小队列\n");
        printf("对应入队\n");
        printf("当对应队列不为空时顺序出队执行，执行后出队\n");
        printf("当队列为空时结束循环\n");
    }
        return 0;
}
