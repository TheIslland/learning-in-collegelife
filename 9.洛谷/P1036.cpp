#include<iostream>
#include<cmath>
using namespace std;
int a[20],n,m;
bool is_prime(int x) {
	int y = sqrt(double(x));
	for(int i = 2;i <= y; i++) {
		if(x%i == 0) return false;
	}
	return true;
}
int judg(int k,int sum,int start,int end) {
	if(k == 0) return is_prime(sum);
	int num = 0;
	for(int i = start;i <= end;i++) {
		num += judg(k - 1,sum + a[i],i + 1,end);
	}
	return num;
}

int main() {
	cin >> n>>m;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cout << judg(m,0,0,n -1)<<endl;
} 
