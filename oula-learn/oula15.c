/*************************************************************************
	> File Name: oula15.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 11时31分18秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
//int a[21] = {0};
//int b[21] = {0};
//int c[21] = {0};
//int is_factorial[200] = {1,1};
/*int64_t init() {
   int64_t ans = 1;
    for(int i = 1; i < 21; i++) {
        a[i] = 1;
        b[i] = i + 20;
    }
    for(int i = 1; i < 21; i++) {
        ans *= b[i];
        int n = 2;
        while(ans % a[n] == 0&& a[n] != -1&& n <= 20) {
            ans /= a[n];
            a[n] = -1;
            printf("%"PRId64"\n",ans);
            n++;
            break;
        }
    }
    return ans;
}
*/
/*int jiecheng(int n) {
    for(int i = 1; i < 21; i++) {
        for(int j = 1; j <= is_factorial[0]; i++) {
            is_factorial[j] *= b[i];
        }
	    for(int k = 1; k <= is_factorial[0]; ++k) {
            if(is_factorial[k] >= 10) {
                is_factorial[k + 1] += is_factorial[k] / 10;
                is_factorial[k] %= 10;
                if(k == is_factorial[0])
                is_factorial[0] += 1;
            }
        }        
	}
}*/
int main() {
    int64_t ans = 1, n = 21, m = 2;
    while(n <= 40 || m <= 20) {
        if(ans % m != 0) {
            ans *= n;
            n++;
        }
        if(ans % m == 0 && m <= 20){
            ans /= m;
            m++;
        }
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
