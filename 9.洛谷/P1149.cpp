#include<stdio.h>
int main()
{
        int a[2020]={6},b,c[10]={6,2,5,5,4,5,6,3,7,6},s=0,i,j;
        scanf("%d",&b);
        for(i=1;i<=2010;i++)
        {
                j=i;
                while(j>=1)//求每个数所用的火柴棒
                {
                        a[i]=a[i]+c[j%10];
                        j=j/10;
                }
        }
        for(i=0;i<=1010;i++)
        {
                for(j=0;j<=1010;j++)
                if(a[i]+a[j]+a[i+j]+4==b)s++;//还有加号与等号
        }
        printf("%d",s);
        return 0;
}
