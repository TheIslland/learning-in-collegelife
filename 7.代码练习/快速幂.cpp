/*************************************************************************
	> File Name: 快速幂.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月14日 星期一 09时33分32秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N=1000200;
const int pr_num=100200;

int prime[pr_num],temp;
bool is_prime[pr_num];

char B[MAX_N];
LL A,C;

void init(){
    for(int i = 0; i < pr_num; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    temp = 0;
    for(int i = 2; i < pr_num;i++){
        if(is_prime[i]) prime[temp++] = i;
        for(int j = 0; j < temp && i * prime[j] < pr_num; j++){
            is_prime[i * prime[j]] = false;
            if(!(i % prime[j])) break;
        }
    }
}

LL mypow(LL a,LL b,LL c){
    LL sum=1;
    while(b){
        if(b & 1) sum = sum * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return sum;
}

int main(){
    int n;
    init();
    scanf("%d", &n);
    while(n--){
        scanf("%lld %s %lld",&A,B,&C);
        LL newC = C;
        LL phiC = C;
        for(int i = 0;i < temp; i++){
            if(1LL * prime[i] * prime[i] > C) break;
            if(C % prime[i] == 0){
                while(C % prime[i] == 0) C /= prime[i];
                phiC = phiC / prime[i] * (prime[i] - 1);
            }
        }
        if(C != 1) phiC = phiC / C * (C-1);
        int len = strlen(B);
        LL tmpB = 0;
        for(int i = 0;i < len; i++) tmpB = (tmpB * 10 + B[i] - '0') % phiC;
        printf("%lld\n", mypow(A, tmpB + phiC, newC));
    }
}
