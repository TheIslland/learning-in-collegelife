/*************************************************************************
	> File Name: 数组.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 20时16分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class shuzu {
private:
    int length;
    int *data;
public:
    shuzu();
    shuzu(int length);
    int getlength();
    int getvalue(int ind);
    int setdata(int ind, int value);
    void output();
};

shuzu::shuzu() {
    length = 10;
    data = new int[10];
    for (int i = 0; i < 10; i++) {
        data[i] = -1;
    }
}

shuzu::shuzu(int len) {
    length = len;
    data = new int[len];
    for (int i = 0; i < len; i++) {
        data[i] = -1;
    }
}
int shuzu::getlength() {
    return length;
}

int shuzu::getvalue(int ind) {
    if (ind > length) {
        cout << "数组越界" << endl;
        return -1;
    }
    return data[ind];
}

int shuzu::setdata(int ind, int value) {
    if (ind > length) {
        cout << "位置错误" << endl;
        return -1;
    }
    data[ind] = value;
    cout << "更改成功" << endl;
    return 1;
}

void shuzu::output() {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
int main() {
    shuzu t;
    t.output();
    cout << t.getlength() << endl;
    t.setdata(2, 23);
    t.output();
    t.setdata(11, 22);
    t.output();
    cout << t.getvalue(2) << endl;
    cout << endl;
    shuzu t1(20);
    t1.output();
    cout << t1.getlength() << endl;
    t1.setdata(2, 23);
    t1.output();
    t1.setdata(11, 22);
    t1.output();
    cout << t1.getvalue(2) << endl;
    return 0;
}
