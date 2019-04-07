/*************************************************************************
	> File Name: head.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 20时25分49秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
typedef void demo;
demo* demo_init(int i, int j);
int getI(demo* pthis);
int getJ(demo* pthis);
int add(demo *pthis, int value);
void free_demo(demo *pthis);
#endif
