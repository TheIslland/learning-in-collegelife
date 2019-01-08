/*************************************************************************
	> File Name: 组合关系.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月08日 星期二 19时25分56秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
class Mem {
public:
    Mem() {
        cout << "Mem" << endl;
    }
    ~Mem() {
        cout << "~Mem" << endl;
    }
};
class Disk {
public:
    Disk() {
        cout << "Disk" << endl; 
    }
    ~Disk() {
        cout << "~Disk" << endl;
    }
};
class CPU {
public:
    CPU() {
        cout << "CPU" << endl;
    }
    ~CPU() {
        cout << "CPU" << endl;
    }
};
class Computer {
private:
    Mem m;
    Disk d;
    CPU c;
public:
    Computer() { 
        cout << "Computer" << endl;
    }
    void PowerOn() {
        cout << "Power on" << endl;
    }
    ~Computer() {
        cout << "~Computer" << endl;
    }
};
int main() {
    Computer c;
    return 0;
}
