# include<cstdio>
# include<cmath>
# define N 6
 
/*
*使用雅可比迭代法和高斯-赛德尔迭代法 求解线性方程组 
*/ 
main(){
  float NF2(float *x,float *y);
  float A[N][N],b[N],sum=0;
 float x[N],y[N]={0},x0[N];
    int i,j,n=0;
  
    //输入系数矩阵 
   for(i=0;i<N;i++){
      for(j=0;j<N;j++){
          scanf("%f",&A[i][j]);
       }
   }
   
    //输入常数矩阵
    for(i=0;i<N;i++){
      scanf("%f",&b[i]);
  } 
  
    //输入解的初值
     for(i=0;i<N;i++){
         scanf("%f",&x0[i]);
     } 
  
    //输出系数矩阵
    printf("输出该方程组的系数矩阵：\n");
    for(i=0;i<N;i++){
     for(j=0;j<N;j++){
          printf("4%3.1f    ",A[i][j]);
        }
       printf("\n");
   } 
  
    //输出成数矩阵
    printf("输出该方程组的常数矩阵：\n");
   for(i=0;i<N;i++){
      printf("%3.1f\n",b[i]);
 } 
  
    //输出解的迭代初值
  printf("解该方程组的的迭代初值是：\n");
  for(i=0;i<N;i++) 
  {
               printf("%3.1f\n",x0[i]);
    }
   /*
 *利用雅可比迭代法求解线性方程组 
 */
   for(i=0;i<N;i++)
   {
       x[i]=x0[i];
 }
   for(n=0;;n++){
                //计算下一个值 
   for(i=0;i<N;i++){
      sum=0;
        for(j=0;j<N;j++){
          if(j!=i){
               sum=sum+A[i][j]*x[j];
           }
       }
       y[i]=(1/A[i][i])*(b[i]-sum);
      //sum=0;
    }
   //判断误差大小 
       if(NF2(x,y)>0.01){
             for(i=0;i<N;i++){
      x[i]=y[i];
  }
   } 
          else
            break;
  } 
  printf("经过%d次雅可比迭代解出方程组的解：\n",n+1);
   for(i=0;i<N;i++){
      printf("%f      ",y[i]);
    }
   /*
 *利用高斯-赛德尔迭代法求解线性方程组 
  */
   for(i=0;i<N;i++)
   {
       x[i]=x0[i];
     y[i]=0;
   }
       for(n=0;;n++){
                //计算下一个值 
   for(i=0;i<N;i++){
      sum=0;
        for(j=0;j<i;j++){
              sum=sum+A[i][j]*y[j];
       }
       for(j=i+1;j<N;j++){
               sum=sum+A[i][j]*x[j];
      }
      y[i]=(1/A[i][i])*(b[i]-sum);
     //sum=0;
   }
  //判断误差大小 
      if(NF2(x,y)>0.01){
                for(i=0;i<N;i++){
     x[i]=y[i];
 }
  } 
         else
           break;
 } 
 printf("\n经过%d次高斯-赛德尔迭代解出方程组的解：\n",n+1);
 for(i=0;i<N;i++){
     printf("%f      ",y[i]);
   }
}
//求两个向量差的二范数函数 
float NF2(float *x,float *y){
int i;
float z,sum1=0;
for(i=0;i<N;i++){
 sum1=sum1+pow(y[i]-x[i],2);
}
z=sqrt(sum1);   
return z;
}

