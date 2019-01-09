/*************************************************************************
	> File Name: 函数模板swap.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月09日 星期三 16时27分24秒
 ************************************************************************/
#include <iostream>
using namespace std;
template<typename T>
void my_swap(T& a, T& b)
{
  	T c = a;
  	a = b;
  	b = c;
}
int main()
{
  	double a1 = 1.3, a2 = 2.1;
  	char b1 = 'a', b2 = 'b';
  	my_swap(a1, a2);
  	my_swap(b1, b2);
  	cout << a1 << " " << a2 << endl;
  	cout << b1 << " " << b2 << endl;
  	return 0;
}
