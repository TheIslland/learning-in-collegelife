/*************************************************************************
	> File Name: luogu-P1217.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年08月22日 星期三 19时44分02秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define maxn 9989899+1
bool Prime[maxn+1];
int ans[800];
void getPrime()
{
    memset(Prime,true,sizeof(Prime));
    for (int i=2;i<maxn ;i++ )
    {
        if(Prime[i])
        {
                for (int j=i+i;j<maxn ;j+=i )
            {
                Prime[j]=false;
            }
        }
    }
}
bool Huiwen(int n)
{
    int sum=0,nn=n;
    while (n)
    {
        sum=sum*10+n%10;
        n/=10;
    }
    return sum==nn;
}
int main()
{
   int a,b;
   getPrime();
   int k=0;
   for(int i=2;i<maxn;i++)
   {
       if(Prime[i]&&Huiwen(i))
        ans[k++]=i;
   }
   while (cin>>a>>b)
   {
        for (int i=0;i<=k ;i++ )
        {
            if(ans[i]<a)
                continue;
            else if(ans[i]>b)
                break;
            else
                cout<<ans[i]<<endl;
        }
        cout<<endl;
   }

    return 0;
}

