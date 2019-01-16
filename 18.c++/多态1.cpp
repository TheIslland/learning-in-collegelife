/*************************************************************************
	> File Name: 多态1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 09时54分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class CompannyA_Boss {
public:
    int battle () {
        int ret = 10;
        cout << "CompannyA_Boss::battle = " << ret << endl;
        return ret;
    }
};
class CompannyB_Boss {
public:
    virtual int fight() {
        int ret = 8;
        cout << "CompannyB_Boss::fight = " << ret << endl;
        return ret;
    }
};
class CompannyB_NewBoss : public CompannyB_Boss {
public:
    int fight() {
        int ret = this->CompannyB_Boss::fight() * 2;
        cout << "New Boss::fight = " << ret << endl;
        return ret;
    }
};
void vs(CompannyA_Boss *c1, CompannyB_Boss *c2) {
    int a = c1->battle();
    int b = c2->fight();
    if (a > b) {
        cout << "Companny A is winner" << endl;
    } else {
        cout << "Companny B is winner" << endl;
    }
    return ;
}
int main() {
    CompannyA_Boss c1;
    CompannyB_Boss c2;
    vs(&c1, &c2);
    cout << "one years later.." << endl;
    CompannyB_NewBoss nb; //new Boss
    vs(&c1, &nb);
    return 0;
}
