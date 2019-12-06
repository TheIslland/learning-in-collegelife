#include<iostream>  
#include<string>  
#include<vector>  
using namespace std;
 
double ChaShang(int n, vector<double>&X, vector<double>&Y);
void Newton(int n1, vector<double>& xp, vector<double>&X, vector<double>&Y, vector<double> &result);
 
int main()
{
	char a = 'n';
	do
	{int n,n1;
	cout << "请输入插值点的个数" << endl;
	cin >> n;
	vector<double>X(n, 0);
	vector<double>Y(n, 0);
	
	cout << "请输入插值点X[i]的值" << endl;
	for (int i = 0; i<n; i++)
	{
		cin >> X[i] ;
	}
	cout << "请输入插值点Y[i]的值" << endl;
	for (int i = 0; i<n; i++)
	{
		cin >> Y[i];
	}
	cout << "请输入所求点的个数" << endl;
	cin >> n1;
	vector<double> xp(n1, 0);
	vector<double> result(n1, 0);
	cout << "请输入所求插值点xp[i]的值：" << endl;
	for (int i = 0; i<n1; i++)
	{
		cin >> xp[i];
	}
	Newton(n1,xp, X, Y,result);
	cout << "输出所求插值点的函数值：" << endl;
	for (int h = 0; h < n1; h++)
	{
		cout<< result[h]<<endl;
	}
	cout << "是否要继续？(y/n)：";
	cin >> a;
	} while (a == 'y');
	return 0;
}
 
double ChaShang(int n, vector<double>&X, vector<double>&Y)
{
	double f = 0;
	double temp = 0;
	for (int i = 0; i<n + 1; i++)
	{
		temp = Y[i];
		for (int j = 0; j<n + 1; j++)
			if (i != j) temp /= (X[i] - X[j]);
		f += temp;
	}
	return f;
}
 
void Newton(int n1, vector<double>& xp, vector<double>&X, vector<double> &Y, vector<double> &result)
{
	double temp1 = 0;
	for (int h = 0; h < n1; h++)
	{
		for (int i = 0; i < X.size(); i++)
		{
			double temp = 1;
			double f = ChaShang(i, X, Y);
			for (int j = 0; j < i; j++)
			{
				temp = temp*(xp[h] - X[j]);
			}
			temp1 += f*temp;
		}
		result[h] = temp1;
		temp1 = 0;
	}
}