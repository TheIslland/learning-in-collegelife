/*************************************************************************
	> File Name: arr.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 20时38分17秒
 ************************************************************************/

#ifndef _ARR_H
#define _ARR_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class arr {
private:
    int length;
    int *data;
public:
    arr();
    arr(int length);
    int getlength();
    int getvalue(int ind);
    int setdata(int ind, int value);
    void output();
};

arr::arr() {
    length = 10;
    data = new int[10];
    for (int i = 0; i < 10; i++) {
        data[i] = -1;
    }
}

arr::arr(int len) {
    length = len;
    data = new int[len];
    for (int i = 0; i < len; i++) {
        data[i] = -1;
    }
}
int arr::getlength() {
    return length;
}

int arr::getvalue(int ind) {
    if (ind > length) {
        cout << "数组越界" << endl;
        return -1;
    }
    return data[ind];
}

int arr::setdata(int ind, int value) {
    if (ind > length) {
        cout << "位置错误" << endl;
        return -1;
    }
    data[ind] = value;
    cout << "更改成功" << endl;
    return 1;
}

void arr::output() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

#endif
