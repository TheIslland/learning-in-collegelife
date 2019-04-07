/*************************************************************************
	> File Name: common.c
	> Author:TheIslland 
    > Mail: 8:61436930@qq.com
	> Created Time: 2018年09月30日 星期日 16时33分15秒
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
#include "common.h"

int get_conf_value (char *path_name, char *key_name, char *value_name) {
    char *buff;
    char *linebuff;
    FILE *fp = fopen(path_name, "r");
    size_t len = 0;
    int read;
    if (fp == NULL) {
        printf("FILE OPEN ERROR\n");
        fclose(fp);
        return 1;
    }
    int key_judg = 0;
    while ((read = getline(&buff, &len, fp)) != -1) {
        if(buff[0] != '#' && (buff[0] != '/' || buff[1] != '/')) {
            if (strstr(buff, key_name) == NULL) continue;
            if (buff[strlen(key_name)] == '=') {
                strncpy(value_name, buff + 1 + strlen(key_name), strlen(buff) - strlen(key_name) - 2);
                printf("conf %s get success\n", key_name);
                fclose(fp);
                return 1;
            }
        }
    }
    printf("%s not found\n", key_name);
    fclose(fp);
    return 1;
}

int socket_create(int port);

int socket_accept(int sock_listen);

int socket_connect(int port, char *host);

int recv_data(int sockfd, char *buf, int bufsize);

/*int write_pi_log (char *PiHealthLog, const char *format, ...) {
    va_list arg;
    int done;
    FILE* pFile = fopen(PiHealthLog, "a+");
    va_start (arg, format);
    time_t time_log = time(NULL);
    struct tm* tm_log = localtime(&time_log);
    fprintf(pFile, "%04d-%02d-%02d %02d:%02d:%02d ", tm_log->tm_year + 1900.\
        tm_log->tm_mom + 1. tm_log->tm_mday, tm_log->tm_hour, tm_log->tm_min,\
        tm_log->tm_sec);
    done = vfprintf(pFile, format, arg);
    va_end (arg);

    fflush(pFile);
    fclose(pFile);
    return done;
*/
