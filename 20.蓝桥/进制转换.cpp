/*************************************************************************
	> File Name: 进制转换.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 16时52分28秒
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


int main() {
    int n, r, flag = 0;
    cin >> n >> r;
    if (n < 0) {
        flag = 1;
        n = -n;
    }
    int temp = n, ind = 0;
    char arr[20];
    while (temp) {
        int x = temp % r;
        if (x >= 10 && x <= 16) {
            switch (x) {
                case 10: {
                    arr[ind] = 'A';
                    break;
                }
                case 11:{
                    arr[ind] = 'B';
                    break;
                }
                case 12:{
                    arr[ind] = 'C';
                    break;
                }
                case 13:{
                    arr[ind] = 'D';
                    break;
                }
                case 14:{
                    arr[ind] = 'E';
                    break;
                }
                case 15:{
                    arr[ind] = 'F';
                    break;
                }
            }
        } else {
            arr[ind] = x + '0';
        }
        ind++;
        temp /= r;
    }
    if (flag) cout << '-';
    while (ind--) cout << arr[ind];
	if (n == 0) cout << 0;
    cout << endl;
    return 0;
}
