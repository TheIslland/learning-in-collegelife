/*************************************************************************
	> File Name: new.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 18时08分47秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;

namespace my_lib {
    int i = 10;
    namespace my_lib1 {
        int i = 100;
    }
}

using namespace my_lib;
using my_lib::my_lib1::i;

int main() {
    /*
     * type *name = new type;　单个空间申请
     * delete name; 收回
     * type *name = new type(value); 单个空间带初值申请
     * delete name; 收回
     * type *name = new type[length]; 申请连续空间
     * delete[] name;　连续空间释放
     * new 申请空间，申请的空间大于等于length
     */
    int *p = new int(100);
    cout << *p << endl;
    int *p1 = new int[10];
    for (int i = 0 ; i < 10; i++) {
        p1[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << p1[i] << " ";
    }
    cout << endl;
    delete p;
    delete[] p1;
    cout << my_lib::i << endl;
    cout << my_lib::my_lib1::i << endl;
    return 0;
}
