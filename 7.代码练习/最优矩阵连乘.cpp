/*************************************************************************
	> File Name: 最优矩阵连乘.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Fri Oct 25 14:25:06 2019
 ************************************************************************/
#include<iostream>
using namespace std;
const int N=7;
void MatrixChainOrder(int *p,int m[N][N],int s[N][N],int length) {
    int n=length-1;
    int l,i,j,k,q=0;
    for(i=1;i<length;i++) {
        m[i][i]=0; 
    }
    for(l=2;l<=n;l++) {
        for(i=1;i<=n-l+1;i++) { 
            j=i+l-1; 
            m[i][j]=0x7fffffff;    
            for(k=i;k<=j-1;k++) { 
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];   
                if(q<m[i][j]) {  
                    m[i][j]=q;    
                    s[i][j]=k;    
                }   
            }  
        } 
    }
    cout << m[1][N-1] << endl;
}
void PrintAnswer(int s[N][N],int i,int j) {
    if(i==j) {
        cout<<"A"<<i; 
    }
    else {
        cout<<"("; 
        PrintAnswer(s,i,s[i][j]); 
        PrintAnswer(s,s[i][j]+1,j); 
        cout<<")"; 
    }
}
int main() {
    int p[N]={30,35,15,5,10,20,25};
    int m[N][N],s[N][N];
    MatrixChainOrder(p,m,s,N);
    PrintAnswer(s,1,N-1);
    return 0;
}
