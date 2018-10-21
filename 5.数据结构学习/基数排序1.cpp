/*************************************************************************
	> File Name: 基数排序1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月21日 星期日 14时08分50秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void raddix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65536] = {0}; //2的16次方
    for(int i = 0; i < n; i++)  cnt[(num[i] & 0xffff) + 1]++;
    for(int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++)  cnt[((temp[i] >> 16 ) & 0xffff) + 1]++;
    for(int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    return ;
}
int main() {
 
    return 0;
}
