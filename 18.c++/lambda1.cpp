/*************************************************************************
	> File Name: lambda.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月16日 星期六 19时08分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>

using namespace std;

class FUNC {
public:
    FUNC(int x, int &y) : x(x), y(y) {}
    void operator()() {
        x += 1, y += 2;
    }
private:
    int x;
    int &y;
};

int main() {
    int x = 1, y = 2;
    //auto func = FUNC(x, y);
    auto func = [x, &y]() mutable -> void { x += 1, y += 2;};
    cout << x << " " << y << endl;
    func();
    cout << x << " " << y << endl;
    return 0;
}
