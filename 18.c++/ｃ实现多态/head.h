/*************************************************************************
	> File Name: head.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 11时35分32秒
 ************************************************************************/
#ifndef _HEAD_H
#define _HEAD_H
typedef void demo;
typedef void deverid;

demo* demo_init(int i, int j);
int getA(demo *pthis);
int getB(demo *pthis);
int add(demo *pthis, int value);
void free_demo(demo *pthis);

deverid* deverid_init(int i, int j, int k);
int getC(deverid *pthis);
int add1(deverid *pthi, int value);
void free_deverid(deverid *pthis);
#endif
