/*************************************************************************
	> File Name: 实现vector.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月19日 星期二 20时05分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

namespace my {
    template<typename T> 
    class vector_iterator {

    };
    template<typename T>
    class vector{
    private:
        T* data;
        size_t size, length;
    public:
        typedef vector_iterator<T> iterator;
        vector() {
            this->data = new T[10];
            this->size = 10;
            this->length = 0;
        }
        vector(int size) {
            
        }
        vector(const vector<T> &arr): data(nullptr), size(0), length(0) {
            clear();
            this->data = new(arr.size);
            for (int i=  0; i < arr.length; i++) {
                new(this->data + i) T(arr[i]);
            }
            this->size = arr.size;
            this->length = arr.length;
        }
        vector(vector<T> &&arr): 
            data(arr.data), 
            length(0), 
            size(arr.size) 
        {
            arr.data = nullptr;
            arr.size = 0;
            arr.length = 0;
        }
        T &operator[](size_t ind) {
            return this->data[ind];
        }
        void expand() {
            int new_size = size * 2 + 1;
            int raw_length = length;
            T* p_arr = new T[new_size];  
            for (int i = 0; i < this->length; i++) {
                new(p_arr + i) T[std::move(this->data[i])];
            }
            clear();
            data = p_arr;
            size = new_size;
            length = raw_length;
            return ;
        }
        void push_back(const T &obj) {
            if (this->length >= this->size) {
                this->expand();
            }
            new(this->data + this->length) T(obj);
            this->length += 1;
            return ;
        }
        void clear() {
            if (this->data != nullptr) {
                delete[] this->data;
            }
            this->data = nullptr;
            this->size = 0;
            this->length = 0;
        }
        ~vector() {
            if (this->data != nullptr) {
                delete[] this->data;
            }
            this->data = nullptr;
            this->size = 0;
            this->length = 0;
        }
        T* iterator() {
            
        }
        operator=
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
