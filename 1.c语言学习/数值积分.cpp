
#include<stdio.h>// Romberg外推法，
#include<math.h>
#define MAX 10
double func(double a){
double y;
if (a == 0)
return y=1;
else
return y=sin(a)/a;
}

int main(){
double T[MAX],S[MAX],C[MAX],R[MAX];
double t1,t2;
double a,b,e,s=0;
double h,x;
int i,k,m;

printf("input data a,b,e:");
scanf("%lf%lf%lf",&a,&b,&e);//例如实验输入的是-1?1?0.0000001

printf("\n");

h=b-a;
k=0;
t1=h/2*(func(a)+func(b));
T[k]=t1;
printf("T[i]\t\tk\n");
printf("%.10lf\t%d\n",T[k],k);


s=0;
x=a+h/2;
s+=func(x);
x+=h;
while(x<b)
{
s+=func(x);
x+=h;
}

t2=t1/2+h/2*s;

while(fabs(t2-t1)>=e)
{
h=h/2;
t1=t2;
k=k+1;
T[k]=t2;

printf("%.10f\t%d\n",T[k],k);


s=0;
x=a+h/2;
s+=func(x);
x+=h;
while(x<b)
{
s+=func(x);
x+=h;
}
t2=t1/2+h/2*s;
}
m=k-1;
for(i=0;i<m;i++)
{
S[i]=4*T[i+1]/3-T[i]/3;
}

m=k-2;
for(i=0;i<m;i++)
{
C[i]=16*S[i+1]/15-S[i]/15;
}

m=k-3;

printf("Romberg:\n");
printf("R[i]\t\tk\n");
for(i=0;i<m;i++)
{
R[i]=64*C[i+1]/63-C[i]/63;
printf("%.10lf\t%d\n",R[i-1],i);
}

return 0;
}
