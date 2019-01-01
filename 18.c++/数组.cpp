/*************************************************************************
	> File Name: 数组.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 20时16分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include "arr.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    arr t;
    t.output();
    cout << t.getlength() << endl;
    t.setdata(2, 23);
    t.output();
    t.setdata(11, 22);
    t.output();
    cout << t.getvalue(2) << endl;
    cout << endl;
    arr t1(20);
    t1.output();
    cout << t1.getlength() << endl;
    t1.setdata(2, 23);
    t1.output();
    t1.setdata(11, 22);
    t1.output();
    cout << t1.getvalue(2) << endl;
    return 0;
}
