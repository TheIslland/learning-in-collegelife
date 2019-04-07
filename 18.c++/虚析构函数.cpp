/*************************************************************************
	> File Name: 虚析构函数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月23日 星期六 11时40分14秒
 ************************************************************************/

#include <bits/stdc++.h>

class A
{
public:
    virtual ~A() = default;
    virtual void F() = 0;
};

class B : public A
{
public:
    void F() = 0;
};

int main()
{
    B b;
    return 0;
}

