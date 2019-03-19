/*************************************************************************
	> File Name: vector_iterator.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月19日 星期二 21时20分00秒
 ************************************************************************/

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
    class vector_iterator {
    public:
        vector_iterator() : p(nullptr) {}
        vector_iterator(T *p) : p(p) {}
        vector_iterator(const vector_iterator<T> &obj) : p(obj.p) {}
        vector_iterator(vector_iterator<T> &&obj) : p(obj.p) {}
        bool operator!=(const vector_iterator<T> &obj) {
            return this->p != obj.p;
        }
        bool operator==(const vector_iterator<T> &obj) {
            return this->p == obj.p;
        }
        T &operator*() {
            return *p;
        }
        vector_iterator<T> &operator++() {
            p++;
            return *this;
        }
        vector_iterator<T> operator++(int x) {
            vector_iterator<T> ret(*this);
            p++;
            return ret;
        }

    private:
        T *p;
    };
    template<typename T>
    class vector {
    public :
        typedef vector_iterator<T> iterator;
        vector() {
            this->data = nullptr;
            this->__begin = nullptr;
            this->__end = nullptr;
            this->size = 0;
            this->length = 0;
        }
        vector(const vector<T> &arr) {
            clear();
            this->data = new T[arr.size];
            for (int i = 0; i < arr.length; i++) {
                new(this->data + i) T(arr[i]);
            }
            this->size = arr.size;
            this->length = arr.length;
            this->__begin = new iterator(this->data);
            this->__end = new iterator(this->data + this->length);
        }
        vector(vector<T> &&arr) : 
            data(arr.data), 
            size(arr.size), 
            length(arr.length),
            __begin(arr.__begin),
            __end(arr.__end)
        {
            arr.data = nullptr;
            arr.__begin = nullptr;
            arr.__end = nullptr;
            arr.size = 0;
            arr.length = 0;
        }
        T &operator[](size_t ind) {
            return this->data[ind];
        }
        void expand() {
            int new_size = size * 2 + 1;
            int raw_length = length;
            T *p_arr = new T[new_size];
            for (int i = 0; i < length; i++) {
                new(p_arr + i) T(std::move(data[i]));
            }
            clear();
            data = p_arr;
            size = new_size;
            length = raw_length;
            __begin = new iterator(data);
            __end = new iterator(data + length);
            return ;
        }
        iterator begin() {
            return iterator(this->data);
        }
        iterator end() {
            return iterator(this->data + this->length);
        }
        void push_back(const T &obj) {
            if (this->length >= this->size) {
                this->expand();
            }
            new(this->data + this->length) T(obj);
            this->length += 1;
            ++(*(this->__end));
            return ;
        }
        void clear() {
            if (this->data != nullptr) {
                delete[] this->data;
                delete this->__begin;
                delete this->__end;
            }
            this->data = nullptr;;
            this->__begin = nullptr;
            this->__end = nullptr;
            this->size = 0;
            this->length = 0;
        }
        ~vector() {
            clear();
        }
    private:
        T *data;
        size_t size, length;
        iterator *__begin, *__end;
    };

    void test() {
        vector<int> arr;
        for (int i = 0; i < 10; i++) {
            arr.push_back(i);
        }
        for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
            cout << *iter << endl;
        }
        return ;
    }
}

int main() {
    my::test();
    return 0;
} 
