/*************************************************************************
	> File Name: P1003.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年09月01日 星期六 19时19分05秒
 ************************************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int shuzu[10001][10001];
int main()
{
    int n,x,y;
    int b=1;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int ii=1;ii<=4;++ii)
        cin>>shuzu[i][ii];                               //输入数据
    }
    cin>>x>>y;
    for(int q=n;q>=1;--q)
    {
        if((shuzu[q][1]<=x)&&(shuzu[q][3]+shuzu[q][1]>=x)&&(shuzu[q][2]<=y)&&(shuzu[q][2]+shuzu[q][4]>=y))    //比较，如果包含了，就继续。
        {
            cout<<q;
        b=2    ;
        }
        if(b==2)
        break;
        if(q==1)
        {
            cout<<-1;
        break;
        }
    }
    return 0;
}
