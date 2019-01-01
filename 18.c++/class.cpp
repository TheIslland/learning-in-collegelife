/*************************************************************************
	> File Name: class.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 18时33分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
class Test {
    private:
        int i;
        int j;
    public:
        int a;
        int getI() {
            return i;    
        }
        int getJ() {
            return j;
        }
        int getA() {
            return a;    
        }
        void setI(int value) {
            i = value;
            return ;
        } 
};

int main() {
    Test t;
    Test *t1 = new Test;
    t.a = 5;
    t1->a = 10;
    t.setI(10);
    cout << t.a << " " << t1->a << endl;
    cout << t.getI() << endl;
    return 0;
}
