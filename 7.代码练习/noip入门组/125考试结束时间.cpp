/*************************************************************************
	> File Name: 125考试结束时间.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sat Nov  2 18:57:41 2019
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
    int h, m, s, t, flag = 0;
    h = m = s = 0;
    cin >> h >> m >> s >> t;
    s += t;
    m += s / 60;
    s %= 60;
    h = (h + m / 60) % 24;
    m %= 60;
    if (h == 0) {
        flag = 1;
        h = 12;
    } else if (h > 0 && h < 12) {
        flag = 1; 
    } else if (h >= 13){
        h -= 12;
    }
    cout << h << ':' << m << ':' << s << (flag ? "am" : "pm") << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << t * 100.0 / 86400.0 << "%" << endl;
    return 0;
}
