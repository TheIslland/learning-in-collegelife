/*************************************************************************
	> File Name: 机器人.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 20时46分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
void add(int &x, int &y, int temp, int vector) {
    switch (vector) {
        case 0: {
            y += temp;
            if (y < 0 )
            break;
        }
        case 1: {
            x += temp;
            break;
        }
        case 2: {
            y -= temp;
            break;
        }
        case 3: {
            x -= temp;
            break;
        }
    }

    cout << "X = " << x << "Y = " << y << endl;
}
int main() {
    int n, temp, x = 0, y = 0;
    cin >> n;
    int vector = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> temp;
        if (s == "forward") {
            add(x, y, temp, vector);
        }
        else if (s == "back") {
            add(x, y, temp, vector);
        }
        else if (s == "left") {
            vector -= 1;
            if (vector < 0) vector = 3;
            add(x, y, temp, vector);
        }
        else if (s == "right") {
            vector += 1;
            if (vector > 3) vector = 0;
            add(x, y, temp, vector);
        }
    cout << x << " " << y << endl;
    }
}
