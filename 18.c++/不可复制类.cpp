/*************************************************************************
	> File Name: 不可复制类.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月21日 星期四 20时47分12秒
 ************************************************************************/

#include <cstdlib>
#include <string>

using namespace std;
class NotCopyable{
    NotCopyable()=default;
    NotCopyable(const NotCopyable&)=delete;
    NotCopyable(NotCopyable&&)=delete;
    NotCopyable& operator=(const NotCopyable&) = delete;
    NotCopyable& operator=(NotCopyable&&) = delete;
};
struct Student: private NotCopyable
{
    string name;
    time_t birtyday;
};

int main()
{
    Student a;
    Student b = a;
    a = b;
    return 0;
}
