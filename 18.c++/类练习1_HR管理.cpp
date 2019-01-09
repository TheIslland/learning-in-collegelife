/*************************************************************************
	> File Name: 类练习1_HR管理.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月09日 星期三 16时43分23秒
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class People {
private:
    int number;
    string name;
    string gender;
    string ID;
    double salary;
public:
    People(int num, string nam, string gen, string id, double sal) {
		cout << "calling the constructor" << endl;
    	number = num;
        name = nam;
        gender = gen;
        ID = id;
        salary = sal;
    }
    People(People &p) {
		cout << "calling the copy constructor" << endl;
        number = p.number + 1;
        name = p.name;
        gender = p.gender;
        ID = p.ID;
        salary = p.salary;
    }
    void set_name(string str) {
		name = str;
    }
    void set_salary(double money) {
		salary = money;
    }
    void show() {
		cout << number << " " << name << " " << gender << " " << ID << " " << salary << endl;
    }
    ~People() {
        cout << "calling the destructor" << endl;
    }
};

int main() {
    People p1(01, "qratosone", "Male", "2010201326", 4800.0);
    People p2(p1);
    p2.set_name("He");
    p2.set_salary(301.301);
    p1.show();
    p2.show();
    string new_name;
    cin>>new_name;
    People p3(p2);
    p3.set_name(new_name);
    p3.show();
    return 0;
}
