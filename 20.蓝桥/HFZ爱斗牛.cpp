/*************************************************************************
	> File Name: HFZ爱斗牛.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月17日 星期四 19时18分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstring> 
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int four_boom(int *a) {
    int b[20] = {0};
    for (int i = 0; i < 5; i++) {
        b[a[i]]++;
        if(b[a[i]] >= 4) return 1;
    }
    return 0;
}

int five_beef(int *a) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] >= 5) return 0;
        sum += a[i];
    }
    if (sum <= 10) return 1;
    else return 0;
}

int beef_beef(int *a) {
    do {
        int sum1 = a[0] + a[1] + a[2];
        int sum2 = a[3] + a[4];
        if (sum1 % 10 == 0 && sum2 % 10 == 0) return 1;
    } while(next_permutation(a, a + 5));
    sort(a, a + 4);
    return 0;
}

int beef_x(int *a, int *ret) {
    do {
        int sum1 = a[0] + a[1] + a[2];
        int sum2 = a[3] + a[4];
        if (sum1 % 10 == 0 && sum2 != 10 && sum2 != 20) {
            *ret = sum2 % 10;
            return 1;
        }
    } while(next_permutation(a, a + 5));
    sort(a, a + 4);
    return 0; 
}

int main() {
    int a[5], flag, temp;
    for (int i = 0 ; i < 5; i++) {
        cin >> temp;
        if (temp > 10) a[i] = 10;
        else a[i] = temp;
    }
    sort(a, a + 4);
    if (four_boom(a)) cout << "quadra bomb orz" << endl;
    else if (five_beef(a)) cout << "penta calf" << endl;
    else if (beef_beef(a)) cout << "you can you up" << endl;
    else if (beef_x(a, &flag)) cout << "too young too simple:calf " << flag << endl;
    else cout << "gg" << endl;
    return 0;
}
