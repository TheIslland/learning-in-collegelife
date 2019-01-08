/*************************************************************************
	> File Name: 代码复用.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月08日 星期二 19时52分59秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class Father {
protected:
    int i;
public:
    Father() {
        i = 100;
    }
    int get() {
        return i;
    }
    virtual void say() {
        cout << "I'm Father." << endl;
    }
};

class Son : public Father {
    private:
        int age;
    public:
    int getAge() {
        return age;
    }
    void say() {
        cout << "I'm Son." << endl;
    }
    int add(int v) {
        age = i + v;
        return age;
    }
};

void how_to_say(Father *f) {
    f->say();    
}

int main() {
    Father f;
    Son s;
    cout << s.getAge() << endl;
    cout << s.get() << endl;
    how_to_say(&f);
    how_to_say(&s);
    cout << s.add(100) << endl;
    return 0;
}
