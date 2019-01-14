/*************************************************************************
	> File Name: 黑桃A.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 12时20分55秒
 ************************************************************************/
#include <iostream> 
#define LENGTH 15
 
using namespace std;
 
int main() {
    int num;
	cin >> num;
	while(num--) {
		int start, end, n;
		int a[LENGTH];
		cin >> n;
		start = end = 0;
		for(int i = n; i >= 1; i--) {
			a[start] = i;
			start = ( (start + LENGTH) - 1 ) % LENGTH;
			for(int j = 0; j < i; j++) {
				a[start] = a[end];
				start = ( (start + LENGTH) - 1 ) % LENGTH;
				end = ( (end + LENGTH) - 1 ) % LENGTH;
			}
		}
		for(int i = 1; i <= n; i++) {
			if( i == 1 )
				cout << a[ (start + i + LENGTH) % LENGTH ];
			else
				cout << " " << a[ (start + i + LENGTH) % LENGTH ];
		}
		cout << endl;
	}
} 

