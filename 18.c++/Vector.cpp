/*************************************************************************
	> File Name: Vector.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月09日 星期三 15时58分23秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int main() {
    vector<int> arr;
    int input, num = 0;
    while (cin >> input) {
        auto it = find(arr.begin(), arr.end(), input);
        if (it == arr.end()) {
			arr.push_back(input);
        	num++;
        }
    }
    sort(begin(arr), end(arr), [](int x, int y) {return x >= y;});
    for (int i = 0; i < num; i++) {
        cout << arr[i] << endl;
    }
    cout << num << endl;
	return 0;
}
