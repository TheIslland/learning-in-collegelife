#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;
void Lagrange(int N, int N1, vector<double>&X, vector<double>&Y, vector<double>&xp, vector<double> &result);
int main(){
	char a = 'n';
	do{
	cout << "请输入所需插值点N的值：" << endl;
	int N;
	int N1;
	cin >> N;
	vector<double>X(N, 0);
	vector<double>Y(N, 0);
	cout << "请输入"<<N<<"个插值点对应的值X[i]：" << endl;
	for (int a = 0; a<N; a++){
		cin >> X[a];
		if (a >= N)
		break;}
	cout << "请输入" << N << "个插值点对应的函数值Y[i]：" << endl;
	for (int a = 0; a<N; a++){
		cin >> Y[a];
		if (a >= N)
		break; }
	cout << "请输入所求xp次数N1的值：" << endl;
	cin >> N1;
	vector<double>xp(N1, 0);
	vector<double> result(N1, 0);
	cout << "请输入" << N1 << "个所求向量xp[i]的值：" << endl;
	for (int a = 0; a<N1; a++){
		cin >> xp[a];
		if (a >= N1)
		break;
	  }
	Lagrange(N, N1, X, Y, xp, result);
	for (int a = 0; a < N1; a++) {
		cout << result[a] << endl;
	  }
	cout << "是否要继续？(y/n)：";
	cin >> a;
	  } while (a == 'y');
	return 0;
}
void Lagrange(int N, int N1,vector<double>&X, vector<double>&Y, vector<double>&xp, vector<double> &result){
	double temp1=0;
	for (int h = 0; h < N1; h++){
		for (int i = 0; i < N; i++){
			double temp = Y[i];
			for (int j = 0; j < N; j++) {
				if (i != j){
					temp = temp*(xp[h] - X[j]);
					temp = temp/(X[i] - X[j]);
				 }
			}
			temp1 += temp;
		    }
		result[h] = temp1;
		temp1 = 0 ;
	}
}