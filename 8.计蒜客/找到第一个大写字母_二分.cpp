/*************************************************************************
	> File Name: 找到第一个大写字母_二分.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月09日 星期六 18时14分28秒
 ************************************************************************/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int find_first_capital_letter(string &str) {
    int ind = 0, l = 0, r = str.length() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (str[mid] >= 'A' && str[mid] <= 'Z') {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    string str;
    cin >> str;
    for (int i = 0; i < 100000; ++i) {
        find_first_capital_letter(str);
    }
    cout << find_first_capital_letter(str) << endl;
    return 0;
}
