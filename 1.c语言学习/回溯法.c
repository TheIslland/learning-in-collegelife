#include <stdio.h>
#include <stdlib.h>
#define maxx 3
//递归实现回溯
//回溯就是递归的结束，返回上一层需要进行数据的返回类似于中断的断点保护
//子集树
//回溯法只要就是要有约束函数和限界函数（左，右）；
//限界函数：当前所有的价值+剩余的所有价值之和小于bestv，则减去右子树；
int c=30;
int cw=0;
int cv=0;
int w[maxx]={20,15,15};
int v[maxx]={40,25,25};
int bestv=0;
int n=3;
int flag=0;
int X[maxx];
void getBest(int i);
int Prize(int i);
int main()
{
    getBest(0);
    printf("最优的结果是%d\n",bestv);

    return 0;
}

void getBest(int i){
    int z;
    int j;
   if(i>=n){//递归结束的判断结束条件，在当前最后一个可执行条件的下一个
        if(cv>bestv)
        bestv=cv;
        flag=1;
    return ;
   }
   if(cw+w[i]<=c){//进入左子树//约束函数
       X[i]=1;
       cw+=w[i];
       cv+=v[i];
       getBest(i+1);
       cw-=w[i];//回溯的过程
       cv-=v[i];
   }
   if(flag==1){//减支函数，减去（i+1~n-1的价值+cw）<bestv的部分
    z=Prize(i);
    if(z<bestv-cv)
    {
        for(j=0;j<=i-1;j++)//判断的是i不装,然后需不需要继续讨论i不装的问题
            printf("%d",X[j]);
        printf("\n");
    return ;
    }
   }
   X[i]=0;//1.不经过左子树直接到右子树，2.计算过左子树，然后回溯到右子树
   getBest(i+1);
}
int Prize(int i){
   int j;
   int z=0;
   for(j=i+1;j<n;j++)
    z+=v[j];
   return z;
}
