/*************************************************************************
	> File Name: 运算符重载.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Thu Oct 24 19:11:29 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct Data {
    Data(int x, int y) : x(x), y(y) {
        
    }
    /*第二种
    Data operator+(Data &a) {
        return Data(x + a.x, y + a.y);
    }*/
    int x, y;
};

Data operator+(Data &, Data &);
ostream &operator<<(ostream &, const Data &);
int main() {
    Data a(2, 4), b(5, 6);
    //cout << a + b << endl; == cout << a.operator+(b) << endl;
    (cout << a + b) << endl; //operator+(a + b) == a + b
    return 0;
}

//第一种
Data operator+(Data &a, Data &b) {
    return Data(a.x + b.x, a.y + b.y);
}

ostream &operator<<(ostream &out, const Data &a) {
    out << "class<Data> " << a.x << " " << a.y;
    return out;
}
