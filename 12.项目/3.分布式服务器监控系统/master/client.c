/*************************************************************************
	> File Name: test_client.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月10日 星期一 19时08分14秒
 ************************************************************************/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void func(char *str, char *m, int sockfd) {
    char buf[BUFSIZ] = {0};
    char data[1000] = {0};
    FILE *fp = popen(m, "r");
    fread(data, sizeof(char), sizeof(data), fp);
    buf[0] = strlen(str) + '0';
    strncpy(buf + 1, str, strlen(str));
    strncpy(buf + 1 + strlen(str), data, strlen(data));
    while (send(sockfd, buf, strlen(buf), 0) < -1);
    pclose(fp);
    return ;
}

void func_w(char *m, int sockfd) {
    char buf[BUFSIZ] = {0};
    char data[1000] = {0};
    FILE *fp = popen(m, "r");
    fread(data, sizeof(char), sizeof(data), fp);
    strncpy(buf, data, strlen(data));
    if (buf[0] == '\0') {
        return ;
    }
    while (send(sockfd, buf, strlen(buf), 0) < -1);
    pclose(fp);
    return ;
    
}

char *IP_acquire() {
    char hname[128];
    struct hostent *hent;
    int i;
    hent = gethostbyname(hname);
    char *ip = inet_ntoa(*(struct in_addr*)(hent->h_addr_list[i]));
    return ip;
}

void *func1(void *argv) {
    struct sockaddr_in server;
    server.sin_family = AF_INET; // 初始化服务器地址
    server.sin_port = htons(8536);
    server.sin_addr.s_addr = inet_addr("192.168.2.163");
    bzero(&(server.sin_zero), 8);
    int fd;
    while ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // socket
    while (1) {
      while (connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1);
        func_w("./warning_monitoring.sh", fd);        
        func_w("./malicious_process_detection.sh", fd);
        if (fd != -1) close(fd);
        printf("cds\n");
        sleep(10);
    }
}

void *alert_func(void *argv) {
    struct sockaddr_in server;
    server.sin_family = AF_INET; // 初始化服务器地址
    server.sin_port = htons(8536);
    server.sin_addr.s_addr = inet_addr("192.168.2.163");
    bzero(&(server.sin_zero), 8);
    int fd, sockfd;
	
	while (1) {
		char buf[BUFSIZ] = {0};
		buf[0] = '1';
		char data[BUFSIZ] = {0};
        int flag = 0;
		FILE *fp = popen("./System_operation.sh", "r");
		fread(data, sizeof(char), sizeof(data), fp);
		char *str = strstr(data, "note");
		char *str2 = strstr(data, "waring"); 
		if(str || str2) {
			strncpy(buf + 1, data, strlen(data));
            flag = 1;
		}
		pclose(fp);
        memset(data, 0, sizeof(data));
		FILE *fp2 = popen("./malicious_process_detection.sh", "r");
		fread(data, sizeof(char), sizeof(data), fp);
		if(data[0]) {
			strncpy(buf + strlen(buf), data, strlen(data));
            flag = 1;
		}
		printf("%s\n", buf);
		pclose(fp2);
        if (flag) {
			buf[strlen(buf)] = '\n';
			buf[strlen(buf)] = 0;
		    while ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // socket
	        while ((sockfd = connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr))) == -1);
		    send(fd, buf, strlen(buf), 0);
        }
		if (fd != -1) close(fd);
    }
    return NULL;
}


void *soc_func(void *argv) {
    struct sockaddr_in server;
    server.sin_family = AF_INET; // 初始化服务器地址
    server.sin_port = htons(8765);
    server.sin_addr.s_addr = inet_addr("192.168.2.163");
    bzero(&(server.sin_zero), 8);
    int fd;
    while ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1); // socket
    while (connect(fd, (struct sockaddr*)&server, sizeof(struct sockaddr)) == -1);
    if (fd != -1) close(fd);
    printf("cds\n");
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    /*
    if (argc < 3) {
        printf("./Client 地址 端口\n");
        exit(1);
    }
    int port = atoi(argv[2]); // int型 端口
    char *host = argv[1]; // 地址
    */
    int fd, new_fd, struct_len, numbytes, i;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buff[BUFSIZ]; // 缓冲区

    server_addr.sin_family = AF_INET; // IP地址
    server_addr.sin_port = htons(8432); // 端口
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8); // 地址族协议
    struct_len = sizeof(struct sockaddr_in); 
    struct sockaddr_in *ser = &server_addr;
    pthread_t t, w;
    pthread_create(&w, NULL, alert_func, NULL);
    pthread_create(&t, NULL, soc_func, NULL);
    fd = socket(AF_INET, SOCK_STREAM, 0); // socket
    while(bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1); // bind 绑定
    printf("绑定成功\n");
    while(listen(fd, 10) == -1); // 进入监听状态
    printf("正在监听中......\n");
    new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
    while(1) {
        func("cpu.log", "./cpu_occupy.sh", new_fd);
        sleep(1);
        func("mem.log", "./MEM.sh", new_fd);
        func("disk.log", "./DISK.sh", new_fd);
        func("User.log", "./User_information_statistics.sh", new_fd);
        sleep(5);
        func("bad_proccess.log", "./malicious_process_detection.sh", new_fd);
    }
    return 0;
}
