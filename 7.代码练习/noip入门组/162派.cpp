/*************************************************************************
	> File Name: 162派.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 14:03:22 2019
 ************************************************************************/

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int flag, t;
	double item, pi;
	flag = 1;
	t = 1;
	item = 1.0;
	pi = 0;
	while (fabs(item) >= 1e-6) {
		item = flag * 1.0 / t;
		pi = pi + item;
		flag = -flag;
		t += 2;
	}
	pi *= 4;
	cout << setiosflags(ios::fixed) << setprecision(15) << pi << endl;
	return 0;
}