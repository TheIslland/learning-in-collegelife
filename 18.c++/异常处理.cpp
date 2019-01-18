/*************************************************************************
	> File Name: 异常处理.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 14时48分07秒
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Base {};
class Exception : public Base {
    private :
    int i;
    string info;
    public:
    Exception(int v1, string s1) {
        i = v1;
        info = s1;
    }
    void what() {
        cout << "exception id is " << i << endl;
        cout << "exception information is " << info << endl;
    }
};

void func(int i) {
    if(i < 10) {
        throw -1;
    } else if(i < 20) {
        throw -2;
    } else if(i < 30) {
        throw -3;
    }
    return ;
}

/*void myfunc (int i) {
    try {
        func(i);
    } catch (int i) {
        switch(i) {
            case -1 : {
                throw "Run Erro";
                break;
            }
            case -2 : {
                throw "Parameter Erro";
                break;
            }
            case -3 : {
                throw "Segment fault";
                break;
            }
        }
    }
}*/
void myfunc (int i) {
    try {
        func(i);
    } catch (int i) {
        switch(i) {
            case -1 : {
                throw Exception(-1, "Run Erro");
                break;
            }
            case -2 : {
                throw Exception(-2, "Parameter Erro");
                break;
            }
            case -3 : {
                throw Exception(-3, "Segment fault");
                break;
            }
        }
    }
}

int main() {
    int i ;
    cin >> i;
    /*try {
        myfunc(i);
    } catch(const char *s) {
        cout << "exception information is :" << s << endl;
    }
    cout << "done" << endl;*/
    try {
        myfunc(i);
    } catch(Exception &e) {
        cout << "exception information is :" << endl;
        e.what();
    } catch(Base &b) {
        cout << "Base Exception" << endl;
    } /*catch(Base &b) {
        cout << "Base Exception" << endl;
    }*/ catch(...) {
        cout << "Other Exception" << endl;
    }
    cout << "done" << endl;
    return 0;
}
