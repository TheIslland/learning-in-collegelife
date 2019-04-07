/*************************************************************************
	> File Name: 指定运行练习.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月04日 星期四 15时56分39秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *error_mag = NULL;

int app_name_valid(int argc, char *argv[]) {
	int num = 0;
    char *name = argv[0];
    for (int i = 0; i < strlen(argv[0]); i++) {
        if (name[i] == '/') num = i;
    }
	int ret = strcmp(name + num + 1, "haizeix") == 0 ;
    error_mag = (char *)(ret ? NULL : "wrong app_name");
    return ret;
}

int user_name_valid(char **env) {
    int ret = 0;
	for (char **p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=mason") == 0;
    }
    error_mag = (char *)(ret ? NULL : "wrong user_name");
    return ret;
}

int main(int argc, char *argv[], char *env[]) {
    if (app_name_valid(argc, argv) == 0) {
        fprintf(stderr, "%s\n", error_mag);
        exit(0);
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_mag);
        exit(0);
    } 
    printf("hellow world\n");
    return 0;
}
