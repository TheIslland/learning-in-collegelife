/*************************************************************************
	> File Name: 实现cout.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月17日 星期日 20时14分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>

namespace mylib {
    
    class file {
    public :
        file(FILE *f) : f(f) {}
        file(const char *s) {
            this->f = fopen(s, "w");
        }
        FILE *get() const { return this->f; }
        ~file() {
            if (this->f != NULL) fclose(this->f);
        }
    private:
        FILE *f;
    };

    class Charactor {
    public :
        Charactor(char c) : c(c) {}
        char get() const { return this->c; }
    private:
        char c;
    };

    class ostream {
    public :
        ostream() { 
            this->fout = stdout;
        }
        ostream &operator<<(const int &x) {
            fprintf(this->fout, "%d", x);
            return *this;
        }
        ostream &operator<<(const double &x) {
            fprintf(this->fout, "%lf", x);
            return *this;
        }
        ostream &operator<<(const char *x) {
            fprintf(this->fout, "%s", x);
            return *this;
        }
        ostream &operator<<(const char x) {
            fprintf(this->fout, "%c", x);
            return *this;
        }
        ostream &operator<<(const Charactor &x) {
            (*this) << x.get();
            return *this;
        }
        ostream &operator<<(const file &x) {
            this->fout = x.get();
            return *this;
        }
    private:
        FILE *fout;
    };

    file STDIN(stdin), STDOUT(stdout), STDERR(stderr);
    Charactor endl('\n');
    ostream cout;
}

typedef std::pair<int, int> PII;

class A {
public :
    A(int x) : x(x) {}
    friend mylib::ostream &operator<<(mylib::ostream &out, const A &obj);
private:
    int x;
};

mylib::ostream &operator<<(mylib::ostream &out, const A &obj) {
    out << "object : " << obj.x;
    return out;
}

int main() {
    A obj(123);
    mylib::cout << obj << " " << mylib::endl;
    mylib::file fout("output");
    mylib::cout << 123 << fout << 456 << mylib::STDOUT << 789 << mylib::endl;
    /* std::set<PII> s;
    int op, val, cnt = 0;
    while (std::cin >> op >> val) {
        switch (op) {
            case 1: s.insert(PII(val, cnt++)); break;
            case 2: 
                mylib::cout << (*s.begin()).first << " " << (*s.begin()).second << mylib::endl;
                s.erase(s.begin());
                break;
        }
    } */
    return 0;
}
