/*************************************************************************
	> File Name: 回文数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 15时19分46秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int num[100] = {0};
void huiwen(int a, int &ind) {
	int temp = a, judg = 0;
    while (a) {
		judg = judg * 10 + a % 10;
        a /= 10;
    }
    num[ind] = temp;
    if (temp != judg) {
        ind += 1;
		huiwen(temp + judg, ind);
    }
}
int main() {
	int ans = 0, n, temp, ind = 0;
    string str;
    cin >> n;
    temp = n;
    huiwen(temp, ind);
    cout << ind << endl;
    for (int i = 0 ; i <= ind; i++) {
		cout << num[i];
        if (i < ind) cout << "--->";
    }
	return 0;
}
