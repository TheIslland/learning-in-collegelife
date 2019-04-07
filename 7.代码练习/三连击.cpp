/*************************************************************************
	> File Name: 三连击.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月08日 星期一 19时39分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a, b, c, count = 0;
    cin >> a >> b >> c;
    int d = a * b * c;
    a = d / a;
    b = d / b;
    c = d / c;
    do {
        if ((100 * num[0] + 10 * num[1] + num[2]) * a == (100 * num[3] + 10 * num[4] + num[5]) * b && (100 * num[0] + 10 * num[1] + num[2]) * a == (100 * num[6] + 10 * num[7] + num[8]) * c ) {
            cout << num[0] << num[1] << num[2] << " "<< num[3] << num[4] << num[5] << " " << num[6] << num[7] << num[8] << "\n";
            count++;
        }
    } while(next_permutation(num, num + 9));
    if(!count) cout << "NO!!!\n";
    return 0;
}
