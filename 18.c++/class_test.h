/*************************************************************************
	> File Name: class_test.h
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 18时44分25秒
 ************************************************************************/

#ifndef _CLASS_TEST_H
#define _CLASS_TEST_H
class operation {
private:
    int a;
    int b;
    int judg;
public:
    operation();
    bool right();
    bool add();
    bool sub();
    bool cheng();
    bool chu();
    void set(int a, int b);
};

operation() {
    judg = 0;
}

void operation::set(int i, int j) {
    a = i;
    b = j;
    judg = 1;
    return ;
}

bool operation::add() {
    if (!judg) {
        cout << "set failed" << end;
        return false;
    }
    int ans = a + b;
    cout << "set success" << endl;
    cout << "a + b = " << ans << endl;
    return true;
}

bool operation::sub() {
    if (!judg) {
        cout << "set failed" << end;
        return false;
    }
    int ans = a - b;
    cout << "set success" << endl;
    cout << "a - b = " << ans << endl;
    return true;
}


bool operation::cheng() {
    if (!judg) {
        cout << "set failed" << end;
        return false;
    }
    int ans = a * b;
    cout << "set success" << endl;
    cout << "a * b = " << endl;
    return true;
}

bool operation::chu() {
    if (!judg) {
        cout << "set failed" << end;
        return false;
    }
    int ans = a / b;
    cout << "set success" << endl;
    cout << "a / b = " << endl;
    return true;
}

#endif
