/*************************************************************************
	> File Name: luogu-P1579.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年08月22日 星期三 14时13分05秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
int y;
int p[30000];
int n[20000];
int main()
{
	int judg = 0,x = 0;
	cin >> y;
	p[0] = 1;
	p[1] = 1;
for (int i = 2; i < 20000; ++i) {
        if (!p[i]) {
            n[x++] = i;
        }
        for (int j = 0; j < x; ++j) {
            if (n[j] * i > 20000) break;
            p[n[j] * i] = 1;
            if (i % n[j] == 0) break;
        }
    }
	for(int i = 0;i < x;i++) {
	for(int j = i;j < x;j++) {
		
		if(n[j] >= y) {
			break;
		}
		if(!p[y - n[i] - n[j]]) {
			cout << n[i]<<' '<< n[j]<<' '<<y - n[i] - n[j]<<endl;
			judg = 1;
			break; 
		}
	}
	if(judg) break;
}
return 0; 
}        
