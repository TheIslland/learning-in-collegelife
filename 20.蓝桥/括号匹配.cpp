/*************************************************************************
	> File Name: 括号匹配.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月20日 星期三 15时45分15秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;

typedef struct Node {
    char symbol;
    int value;
} Node;

int main() {
    stack<Node> sta; 
    string str;
    cin >> str;
    int ans[str.length() + 10];
    int num = 0, flag = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            Node temp;
            temp.symbol = '(';
            temp.value = i + 1;
            sta.push(temp);
        } else {
            if (sta.empty()) {
                flag = 1;
                break;
            }
            Node temp = sta.top();
            ans[num++] = temp.value;
            ans[num++] = i + 1;
            sta.pop();
        }
    }
    if (flag || !sta.empty()) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < num; i += 2) {
            cout << ans[i] << " " << ans[i + 1];
            if (i < num - 1) cout << endl;
        }                            
    }
    return 0;
}
