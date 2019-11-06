/*************************************************************************
	> File Name: 176寻找字符串.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Tue Nov  5 00:07:22 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
    int ans = 0;
    char str[1005];
    char obj[1005];
    scanf("%[^\n]s", str);
    getchar();
    scanf("%[^\n]s", obj);
    char *pch = strstr(str, obj);
    while (pch != NULL) {
        ans++;
        pch = strstr(pch + 1, obj);
    }
    cout << ans << endl;
    return 0;
}
