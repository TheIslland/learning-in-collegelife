/*************************************************************************
	> File Name: 蒜头君的随机数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月11日 星期五 14时19分53秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, num[1010] = {0}, temp, ind = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
		cin >> temp;
        if (!num[temp]) {
            num[temp] = temp;
			ind++;
        }
    }
    int a[ind] = {0};
    for (int i = 0, j = 0; i < 1010; i++) {
		if (num[i]) {
            a[j] = num[i];
        	j++;
        }
    }
    sort(a, a + ind);
    cout << ind << endl;
    for (int i = 0; i < ind; i++) {
		cout << a[i];
        if (i < ind - 1) cout << " ";
    }
    return 0;
}
