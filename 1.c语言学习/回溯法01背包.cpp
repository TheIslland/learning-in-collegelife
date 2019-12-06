#include <bits/stdc++.h>
 
using namespace std;
 
int counts;//物品数量
int m;//背包
int cw=0;//当前重量
int cp=0;//当前价值
int bestp=0;//当前最优价值
 
typedef struct Node
{
    double pValue;//物品价值
    double pWeight;//物品重量
}Goods;
 
Goods goods[1000];
 
//计算在前k-1件物品已经做出决策的前提下，可能达到的最大的效益值，返回一个上界，
 
 
double Bound(int k)//k代表是考虑第几个物品，
{
    double bound=(double) cp;
    int a=cw;
    while(k<=counts)
    {
        a+=goods[k].pWeight;
        if(a<=m)
            bound+=goods[k].pValue;
        else //此时只填入部分第k个物品，使背包满
        {
            double yu=(double)(m-cw)*(double)(goods[k].pValue/goods[k].pWeight);
            return bound+yu;
        }
 
        ++k;
    }
    return bound;
}
 
bool cmp(Goods a,Goods b)
{
    return (a.pValue/a.pWeight)>(b.pValue/b.pWeight);
}
 
void BackKnap(int i)
{
 
    if(i>counts)//到达叶节点
    {
        bestp=cp;
        return;
    }
    if(cw+goods[i].pWeight<=m)//进入左子树
    {
        cw+=goods[i].pWeight;
        cp+=goods[i].pValue;
        BackKnap(i+1);
        cw-=goods[i].pWeight;
        cp-=goods[i].pValue;
    }
    if(Bound(i+1)>bestp)
        BackKnap(i+1);
}
 
int main()
{
    cout<<"请输入物品个数以及背包容量"<<endl;
    cin>>counts>>m;
    goods[0].pValue=0;
    cout<<"请输入物品的重量"<<endl;
    for(int i = 1; i <= counts; i++)
	{
		cin>>goods[i].pWeight;
	}
	cout<<"请输入物品的价值"<<endl;
	for(int i = 1; i <= counts; i++)
	{
		cin>>goods[i].pValue;
	}
 
	sort(goods,goods+counts+1,cmp);
 
	BackKnap(1);
    cout<<"最大价值为"<<endl;
    cout << bestp<< endl;
    return 0;
}