/*************************************************************************
	> File Name: 水果店.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月17日 星期日 11时45分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, map<string,int> > count;
    map<string, map<string, int> > :: iterator it;
    map<string, int> :: iterator it1; 
    while (n--) {
        string str1, str2;
        int num;
        cin >> str1 >> str2 >> num;
        count[str2][str1] += num;    
    }
    for (it = count.begin(); it != count.end(); it++) {
        cout << it->first << endl;
        for (it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            cout << "   |----" << it1->first << "(" << it1->second << ")" << endl;
        }
    }
    return 0;
}
