/*************************************************************************
	> File Name: common.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月30日 星期日 11时39分40秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

int get_conf_value (char *path_name, char *key_name, char *value_name);

int socket_create(int port);

int socket_accept(int sock_listen);

int socket_connect(int port, char *host);

int recv_data(int sockfd, char *buf, int bufsize);

int write_pi_log (char *PiHealthLog, const char *format, ...);

int send_response(int sockfd, int rq);

int recv_response(int sockfd);

int grenerate_logname(int code, char *logname, char *logdir);

int check__size (char *filename, int size, char *dir);

#endif
