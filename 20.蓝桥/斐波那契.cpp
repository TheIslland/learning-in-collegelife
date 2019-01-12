/*************************************************************************
	> File Name: 斐波那契.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月10日 星期四 10时23分41秒
 ************************************************************************/
#include <stdio.h>

/*long long int fb(int n) {
    if (n == 1 || n == 2) return 1;
    int a = 0, b = 1;
    n -= 1;
	while (n--) {
        long long int temp = (a % 1000000007 + b % 1000000007) % 1000000007;
    	a = b;
        b = temp;
    }
    return b;
}
*/
long long int fb(int n, int a, int b) {
    if (n == 0) return a;
	fb(n - 1, b % 1000000007, (a % 1000000007 + b % 1000000007) % 1000000007);
}

int main() {
    long long int n, ans = 0;
    scanf("%d", &n);
	ans = fb(n, 0, 1);  
    printf("%lld\n", ans);
	return 0;
} 
