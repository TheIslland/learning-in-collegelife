/*************************************************************************
	> File Name: 网页跳转.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月20日 星期三 16时21分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
int main() {
    int n;
    cin >> n;
    stack<string> forward, back;
    string temp;
    while (n--) {
        string operate, web;
        cin >> operate;
        if (operate == "VISIT") {
            cin >> web;
            while (!forward.empty()) forward.pop();
            if (!temp.empty()) back.push(temp);
            temp = web; 
            cout << web << endl;
        } else if (operate == "BACK") {
            if (back.empty()) {
                cout << "Ignore" << endl;
            } else {
                if (!temp.empty()) forward.push(temp);
                string url = back.top();
                temp = url;
                cout << url << endl;
                back.pop();
            }
        } else {
            if (forward.empty()) {
                cout << "Ignore" << endl;
            } else {
                if (!temp.empty()) back.push(temp);
                string url = forward.top();
                temp = url;
                cout << url << endl;
                forward.pop();
            }
        }
    }
    return 0;
}
