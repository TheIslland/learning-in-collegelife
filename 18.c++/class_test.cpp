/*************************************************************************
	> File Name: class_test.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 18时42分30秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
//#include "class_test.h"

using std::cin;
using std::cout;
using std::endl;

class Test {
private:
    int a;
public :
    int getA() {
        return a;
    }
};

Test t1;

int main() {
    cout << t1.getA() << endl;
    Test t2;
    cout << t2.getA() << endl;
    Test *p = new Test;
    cout << p->getA() << endl;
    return 0;
}
