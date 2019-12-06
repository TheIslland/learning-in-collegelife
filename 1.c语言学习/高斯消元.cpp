#include<cstdio>
#include<cmath>

void zhu(float *c,int n,float x[])
{
    int i,j,t,k;
    float p;
    for(i=0;i<=n-2;i++)
    {
        k=i;
        for(j=i+1;j<=n-1;j++)
            if(fabs(*(c+j*(n+1)+i))>(fabs(*(c+k*(n+1)+i))))
                k=j;

        if(k!=i)
            for(j=i;j<=n;j++)
            {
                p=*(c+i*(n+1)+j);
            *(c+i*(n+1)+j)=*(c+k*(n+1)+j);
                *(c+k*(n+1)+j)=p;
            }                                            //找最大的调换位置
        for(j=i+1;j<=n-1;j++)
        {
            p=(*(c+j*(n+1)+i))/(*(c+i*(n+1)+i));         //求系数
            for(t=i;t<=n;t++)
                *(c+j*(n+1)+t)-=p*(*(c+i*(n+1)+t));
        }
    }

    for(i=n-1;i>=0;i--)
    {
            for(j=n-1;j>=i+1;j--)
                (*(c+i*(n+1)+n))-=x[j]*(*(c+i*(n+1)+j));  //求解
                x[i]=(*(c+i*(n+1)+n))/(*(c+i*(n+1)+i));
    }   
}
int main()
{
void zhu(float *,int,float[]);   

int i;  
float x[4];                      
float c[4][5]={1,1,0,3,4,        
               2,1,-1,1,1,
               3,-1,-1,3,-3,
               -1,2,3,-1,4};
float y[4];
float d[4][5]={1,-1,2,-1,-8,
               2,-2,3,-3,-20,
               1,1,1,0,-2,
               1,-1,4,3,4};

zhu(c[0],4,x);
zhu(d[0],4,y);
for(i=0;i<=3;i++)
printf("x[%d]=%f\n",i+1,x[i]);  

printf("\n");
for(i=0;i<=3;i++)
printf("y[%d]=%f\n",i+1,y[i]);
};