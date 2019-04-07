#include<iostream>
#include<algorithm>
using namespace std;
int main() 
{
	int i , j = 0 , n ,m,sum = 0,x;
	cin >> n>> m;
	int a[n];
	for(i = 0; i < n;i++) 
	{
	cin >> a[i];	
	}
	for(i = 0; i < n;i++) {
		sum = a[i] + sum;
		if(sum > m)
		{
		j = j + 1;
		sum = a[i]; 
		 } 
	}
	j = j+ 1;
	cout << j<< endl;
}
