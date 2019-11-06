/*************************************************************************
	> File Name: 173统计字符个数.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 23:34:34 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int main() {
    char str[1000] = {0};
    int a, b, c, d;
    a = b = c = d = 0;
    scanf("%[^\n]s", str);
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            a++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            b++;
        } else if (str[i] == ' ') {
            c++;
        } else {
            d++;
        }
    }
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
