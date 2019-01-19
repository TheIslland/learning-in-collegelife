/*************************************************************************
	> File Name: 蒜头君学英语.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月19日 星期六 20时12分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> s;
    string str;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp >> str;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
        if (temp == 0) s.insert(str);
        if (temp == 1) {
            if (s.count(str)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
