#include<iostream>
#define MAX 100
using namespace std;
int main()
{
 int MAX_SIZE,i,j;
 double x[MAX],f[MAX];
//输入部分
 cout<<"请输入分段线性插值中x的插值个数:"<<endl;
 cin>>MAX_SIZE;
 cout<<"请依次输入x(i)的值"<<endl;
 for(i=1;i<MAX_SIZE+1;i++)
 {
  cin>>x[i];
 }
 cout<<"请依次输入f(x)的值:"<<endl;
 for(i=1;i<MAX_SIZE+1;i++)
 {
  cin>>f[i];
 }
//输出部分
 cout<<"x(i)";
 for(i=1;i<MAX_SIZE+1;i++)
  cout<<"\t"<<x[i];
 cout<<endl; 
 cout<<"f(x)";
 for(i=1;i<MAX_SIZE+1;i++)
  cout<<"\t"<<f[i];
 cout<<endl;
//计算部分
 //确定(x1,x2)区间
 double n,p;
 cout<<"请输入x的插值点:"<<endl;
 cin>>n;
 double def=0;
 for(i=1;i<MAX_SIZE+1;i++)
 {
  def=x[i]-n;
  if (def>0)
  {
   j=i;
   break;
  }
 }
 cout<<"区间范围为:["<<x[j-1]<<","<<x[j]<<"]"<<endl;
 //计算插值点数值
 p=((n-x[j])/(x[j-1]-x[j]))*f[j-1]+((n-x[j-1])/(x[j]-x[j-1]))*f[j];
 cout<<"该点插值P("<<n<<")="<<p<<endl;
 return 1;
}