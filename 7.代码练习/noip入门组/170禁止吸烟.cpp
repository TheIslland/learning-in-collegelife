/*************************************************************************
	> File Name: 170禁止吸烟.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Mon Nov  4 22:16:56 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;
char ans[1000][1000] = {0};

int main() {
    int n;
    cin >> n;
	char sub[] = "Ban_smoking";
	char object[] = "No_smoking";
    for (int i = 0; i < n; i++) {
		char str[1000];
		cin >> str;
		//str[i] = strrpc(&str[i], sub, object);
		char bstr[strlen(str)];//转换缓冲区
		memset(bstr, 0, sizeof(bstr));

		for (int i = 0; i < strlen(str); i++) {
			if (!strncmp(str + i, sub, strlen(sub))) {//查找目标字符串
				strcat(bstr, object);
				i += strlen(sub) - 1;
			}
			else {
				strncat(bstr, str + i, 1);//保存一字节进缓冲区
			}
		}
		strcpy(ans[i], bstr);

    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
