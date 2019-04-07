/*************************************************************************
	> File Name: P1196.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年08月31日 星期五 17时13分16秒
 ************************************************************************/

#include<cstring>
#include<iostream>
#include<cmath>
using namespace std; 
int par[30005],num[30005],save[30005];
int find(int x)
{
	if(x==par[x])
	return x;
	int fn=find(par[x]);   
    save[x]+=save[par[x]];  
    return par[x]=fn;
}
int main()
{
	int n,m,i,j,t;
    for(int i = 0; i < 30000; i++) {
        par[i] = i;
        num[i] = 1;
        save[i] = 0;
    }
		cin >> t;
		
		for(i = 0;i < t;i++) {
		char code;
		int num1,num2;
			cin >> code;		
			cin >>num1>>num2;
				int a = find(num1);
				int b = find(num2);
			if(code == 'M') {
			    save[a]+=num[b];        
                par[a]=b;                                   
                num[b]+=num[a];                            
                num[a]=0;    
			}
			else {
				
				if(a != b) {
					cout << -1 <<endl;
				}
				else{					
				cout <<abs(save[num1] - save[num2]) -1<<endl;					
				}				
			}
		}
	
}
