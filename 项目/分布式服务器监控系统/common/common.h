/*************************************************************************
	> File Name: common.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月30日 星期日 11时39分40秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
#endif
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
