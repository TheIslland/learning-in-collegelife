/*************************************************************************
	> File Name: []重载.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 19时45分10秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::stack;
class Test {
private:
    int a[10];
public:
    int& operator[](int index) {
        return a[index];
    }
    int& operator[](const string &s) {
        if (s == "1st") return a[0];
        else if (s == "2st") return a[1];
        else if (s == "3st") return a[2];
        else if (s == "4st") return a[3];
        else if (s == "5st") return a[4];
        return a[0];
    }
};
int main() {
    Test t;
    for (int i = 0; i < 5; i++) {
        t[i] = i + 1;
    }
    cout << t["1st"] << endl;
    cout << t["2st"] << endl;
    cout << t["3st"] << endl;
    cout << t["4st"] << endl;
    cout << t["5st"] << endl;
    return 0;
}
