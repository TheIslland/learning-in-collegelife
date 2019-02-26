/*************************************************************************
	> File Name: 找出所有谎言.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月26日 星期二 14时42分53秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int maxn=50001;
int n,K,ans,father[maxn],rns[maxn];
/*
0表示与根节点相同，
1表示被根节点战胜，
2表示战胜根节点，
可以发现a到b和b到c的关系加起来模3就是a到c的关系，也就是这里算rnk的原理。

A --0-> B 【表示A和B相同】
B --1-> C 【表示B可以战胜C】 推导出 【A也可以战胜C】
A --(0+1)%3=1-> 【rns运算出A可以战胜C】 
*/

void init() //初始化 
{
    for(int i=1;i<=n;++i)
    {
        father[i]=i;
    }
}

int get(int x) //get父节点+当前节点和父节点之间的关系 
{
    if(father[x]==x)return x; //如果当前x的根节点就是x，则返回 
    else
    {
        int y=father[x]; //让y=x的父节点 
        father[x]=get(father[x]);//直接把当前x的父节点从y改成get(y),也就是y的父节点 --> 路径压缩 
        rns[x]=(rns[x]+rns[y])%3; //之前x的父节点与之前的x的父节点的父节点【爷爷节点？】的关系 
        return father[x]; //返回x的父节点 
    }
    
}

void merge(int x,int y,int d)
{
    int fx,fy;  
    fx=get(x); //获取x的根节点 
    fy=get(y); //获取y的根节点 
    if(fx!=fy) //如果x的根没有等于y的根，持续操作直至相等，因为根相等，故在同一个set内，合并完成 
    {
        father[fx]=fy; // 把x的父节点变成y，下一次循环就是把y的父节点变成y的爷爷节点，直到找到y的根儿为止
        
        rns[fx]=(rns[y]-rns[x]+d+3)%3; 
        /*
        这里求的是fx【x的*根*节点】的与fy之间的关系，因为要合并两个根节点嘛 
        假设x可以战胜y，则关系记为1， 
        那么y被x战胜，关系即位2，
        现在输入1XY，D=1表示X战胜Y，
        那么x的根节点fx推到出来的关系应该是：(1-2+1+3)%3=1,那么fx也可以战胜y 
        */
    }
    else if((rns[x]-rns[y]+3)%3!=d) //当fx=fy【合并完成？】的时候，如果 x对y的关系 和 y对x的关系  推到出来的结果不是D的话，则为谎言 
    {
        ans++;  
    }
    return;
}
int main()
{
    cin>>n>>K;
    init();//这个一定要放在输入n后面，不然就没有初始化 
    for(int i=0;i<K;i++)
    {
        int D,X,Y;
        cin>>D>>X>>Y;
        if(X>n||Y>n||(D==2&&X==Y))
        {
            ans++;
            //continue;
        }
        else
        {
            merge(X,Y,D-1);
        }
        
    }
    cout<<ans<<endl;
    return 0;
} 
