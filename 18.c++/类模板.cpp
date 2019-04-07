/*************************************************************************
	> File Name: 类模板.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 09时36分02秒
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
template <typename T>
class Test{
private:
    T a;
public:
    Test(T v) {
        a = v;
    }
    T get() {
        return a;
    }
    T add(T b) {
        T ret = a + b;
        return ret;
    }
    T sub(T b) {
        return a - b;
    }
    friend string operator-(const string &s1, const string &s2);
};
string operator-(const string &s1, const string &s2) {

}
int main() {
    Test<int> t(0);
    cout << t.get() << endl;
    cout << t.add(120) << endl; 
    string s1 = "mason";
    string s2 = "TheIslland";
    Test<string> t1(s1);
    cout << t1.get() << endl;
    cout << t1.add(" " + s2) << endl;
    cout << t1.sub(" " + s2);
    return 0;
}
