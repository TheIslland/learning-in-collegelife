/*************************************************************************
	> File Name: vector_example_arr_sum.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月16日 星期三 10时48分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;
void c_arr_sum_method() {
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
        sum += a[i];
    }
    cout << "c arr sum method: " << sum << endl;
}
void caddadd_arr_sum_method() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = { 3, 4, 5, 6, 7  };
    auto it = find_first_of(begin(a), end(a), begin(b), end(b));
    bool found = (it != end(a));
}
int main() {
    c_arr_sum_method();
    caddadd_arr_sum_method();
    return 0;
}
