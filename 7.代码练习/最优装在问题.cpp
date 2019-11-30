
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

typedef int Status;
typedef int Type;

int n=0;
Type *x=(Type*)malloc((50)*sizeof(Type));
Type *bestx=(Type*)malloc((50)*sizeof(Type));
Type c=0,
  cw=0,
  bestw=0,
  r=0,
  *w=(Type*)malloc((50)*sizeof(Type));
  
int Backtrack(int i)
{
  int j_index;
  if(i>n)
  {
    if(cw>bestw)
    {
      for(j_index=1; j_index<=n; j_index++)
         bestx[j_index]=x[j_index]; bestw=cw;
    }
    return 1;
  }
  r-=w[i];
  if(cw + w[i] <= c) {
    x[i] = 1;
    cw += w[i];
    Backtrack(i + 1);
    cw = w[i];
  } 
  if(cw + r > bestw) {
    x[i] = 0;
    Backtrack(i + 1);
  }
  r += w[i];
}
Type * Initiate() {
  int index = 1;
  printf("输入集装箱个数：");
  scanf("%d", &n);
  printf("输入轮船重量：");
  scanf("%d", &c);
  
  while(index <= n) {
    printf("输入集装箱%d的重量：",index);
    scanf("%d", &w[index]);
    index++;
  } 
  bestw = 0;
  cw = 0;
  r = 0;
  for(index = 1; index <= n; index++) {
    r += w[index];
    printf("n = %d c = %d cw = %d bestw = %d r = %d\n",n, c, cw,bestw, r);
    for(index = 1; index <= n; index++) {
      printf("w[%d] = %d", index, w[index]);
    }
    printf("\n");
    return w;
  }
}int main () {
  int i;
  Initiate();
  Backtrack(1);
  for(i = 1; i <= n; i++) {
    printf("%d", w[i]);
    printf("%d\n",bestx[i]);
  }
  return bestw;
}