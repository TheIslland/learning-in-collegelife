/*************************************************************************
	> File Name: 左值与右值.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月17日 星期日 18时08分31秒
 ***********************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

namespace my {
    template<typename T>
    class vector{
    public :
        vector() {
            this->data = new T[10];
            this->size = 10;
            cout << "constructor " << this << endl;
        }
        vector(const vector<T> &arr) : data(nullptr), size(0) {
            cout << "copy" << endl;
            if (this->data) {
                delete[] this->data;
            }
            this->data = new T[arr.size];
            this->size = arr.size;
            for (int i = 0; i < this->size; i++) {
                new(this->data + i) T(arr.data[i]);
            }
        }
        T &operator[](int ind) {
            return this->data[ind];
        }

    private:
        T *data;
        int size;
    };
    
    vector<int> func( vector<int> *p = nullptr) {
        vector<int> temp;
        temp[4] = 5678;
        return temp;
    }
    class A {
    public:
        virtual void test(int x) {
            cout << "bye bye" << endl;
        }
        void test1() {
            cout << "bye bye" << endl;
        }
    };
    class B : public A {
    public :
        virtual void test(int x) {
            cout << "my name is class B" << endl;
            cout << this << endl;
            cout << x << endl;
        }
        void test1() {
            cout << "my name is class B" << endl;
        }
    };
    typedef void (*FUNC)(void *, int);
    int test() {
        B b;
        A *p = &b;
        b.test(5);
        ((FUNC**)(&b))[0][0](&b, 5);
        vector<int> d(func());
        cout << &d << endl;
        cout << d[4] << endl;
        my::vector<my::vector<int>> a;
        a[5][5] = 16384;
        my::vector<my::vector<int>> c(a);
        cout << (c[5][5] == a[5][5]) << endl;
        c[5][5] = 16;
        cout << c[5][5] << endl;
        cout << (c[5][5] != a[5][5]) << endl;
        return 0;
    }
}

int main() {
    return my::test();
}

