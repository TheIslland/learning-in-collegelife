/*************************************************************************
	> File Name: main.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年12月25日 星期二 22时37分53秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "LinkList.h"
using namespace std;

int main() {
    Link L(1000);
    int judg = 1;
    while (1) {
        char a[10] = {0}, b[10] = {0};
        int n;
        printf("欢迎来到通讯录管理系统\n");
        printf("请选择功能：\n");
        if (judg) printf("1.建立\n");
        printf("2.插入\n");
        printf("3.删除\n");
        printf("4.查询\n");
        printf("5.输出\n");
        cin >> n;
        switch (n) {
            case 1: {
                if (!judg) {
                    printf("通讯录已建立，请勿重复建立\n");
                    break;
                }
                printf("成功建立通讯录\n");
                judg = 0;
            } break;
            case 2: {
                if (judg) {
                    printf("通讯录未建立，请先建立通讯录\n");
                    break;
                }
                printf("请输入姓名\n");
                scanf("%s", a);
                printf("请输入号码\n");
                scanf("%s", b);
                int temp = L.Hashtable_insert (a, b);
                if (temp) {
                    printf("插入成功\n");
                } else {
                    printf("已存在\n");
                }
            }break;
            case 3: {
                if (judg) {
                    printf("通讯录未建立，请先建立通讯录\n");
                    break;
                }
                printf("请输入姓名\n");
                scanf("%s", a);
                int judg = L.Hashtable_del(a);
                if (judg) {
                    printf("此人不存在\n");
                } else {
                    printf("已删除\n");
                }
            }break;
            case 4: {
                if (judg) {
                    printf("通讯录未建立，请先建立通讯录\n");
                    break;
                }
                printf("请输入姓名\n");
                scanf("%s", a);
                int judg = L.Hashtable_find(a);
                if (judg) {
                    printf("此人不存在\n");
                } else {
                    printf("已存在\n");
                }
            }break;
            case 5: {
                if (judg) {
                    printf("通讯录未建立，请先建立通讯录\n");
                    break;
                }
                printf("请输入姓名\n");
                scanf("%s", a);
                int judg = L.Hashtable_put(a);
                if (judg) {
                    printf("此人不存在\n");
                }
            }break;
        }
    }
    return 0;
}
