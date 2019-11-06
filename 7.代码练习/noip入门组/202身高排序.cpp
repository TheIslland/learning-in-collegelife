/*************************************************************************
	> File Name: 202身高排序.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Wed Nov  6 16:16:42 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
typedef long long ll;
using namespace std;
#define SWAP(a, b) {\
    __typeof(a) c = a; a = b; b = a;\
}
class person {
public:
    int height, num;
    person() {
    }
    person(int height, int num = 0) {
        this->height = height;
        this->num = num;
    }
    bool operator>(const person& b) const {
        return  (this->height > b.height);
    }
};
int main() {
    int n, m;
    cin >> n;
    person *a = new person(105);
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[i] = person(m, i + 1);
        cout << a[i].num << (i < n - 1 ? " " : "");
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - i; j++) {
            if (a[j + 1].height < a[j].height) {
                SWAP(a[j + 1].height, a[j].height);
                SWAP(a[j + 1].num, a[j].num);
            }
        }
    }
 //   sort(&a, &a + n * sizeof(person));
    for (int i = 0; i < n; i++) {
        cout << a[i].num << (i < n - 1 ? " " : "");
    }
    return 0;
}
