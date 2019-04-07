/*************************************************************************
	> File Name: 字符串.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月09日 星期六 08时50分02秒
 ************************************************************************/
#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;
//把字符串里面的某个子串换成另一个子串
void Replace(string& str, const string& toFind, const string& toReplace)　{
    while (true)　{
        auto pos = str.find(toFind);
		if (pos == string::npos)　{
            break;
        }
        str.replace(begin(str) + pos, begin(str) + pos + toFind.size(), toReplace);
    }
}
int main() {
   /* char a[10] = "abcdefg";
    //memmove(a + 6, a + 5, strlen(a + 5) + 1);
    strncpy(a + 2, "XYZW", 4);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }*/
	//字符串插入方法
    string a = "abcdefg";
    //replace的使用方法，第一个参数选择插入位置，第二个参数复制后字符串接续位置，第三个参数插入字符串
	a.replace(begin(a) + 2, begin(a) + 3, "XYZW");
	string b = "abcdefg";
	b.replace(begin(b) + 2, begin(b) + 5, "UV");
    cout << a << " " << b << endl;
    //查找子字符串
	string s = "abcdefg";
	auto x = s.find("cde"); // x == 2
	auto y = s.find("CDE"); // y == string::npos
	return 0;
}
