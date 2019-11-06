/*************************************************************************
	> File Name: 181大小写翻转.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 00:56:53 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int main() {
    char str[1000] = {0};
    cin >> str;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    printf("%s\n", str);
    return 0;
}
