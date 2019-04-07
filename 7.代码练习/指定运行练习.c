/*************************************************************************
	> File Name: 指定运行练习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月05日 星期五 14时58分19秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *error_mag = NULL;

int app_name_value(int argc, char *argv[]) {
    int num = 0;
    char *str = argv[0];
    for (int i = 0; i < strlen(argv[0]); i++) {
        if (str[i] == '/') num = i;
    }
    int ret = (strcmp(str + num + 1, "haizeix") == 0);
    error_mag = (char *)(ret ? NULL:"app_name_error");
    return ret;
}
int env_name_value(char **env) {
    int num = 0;
    for (char **p = env; p[0] != NULL; p++) {
        num = num || strcmp(p[0], "USER=mason") == 0;
    }
    error_mag = (char *)(num ? NULL:"app_name_error");
    return num;
}

int main(int argc, char *argv[], char *env[]) {
    if (app_name_value(argc, argv) == 0) {
        fprintf(stderr, "%s\n", error_mag);
        exit(0);
    }    
    if (env_name_value(env) == 0) {
       fprintf(stderr, "%s\n", error_mag);
       exit(0);
    }    
    printf("hellow world\n");   
    return 0;
}
