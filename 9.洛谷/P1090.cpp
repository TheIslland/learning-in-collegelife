#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
int main() {
	int i , j, n, m;
	priority_queue<int ,vector<int>,greater<int> >q;
	cin >> n;
	while(n--) {
		cin >> m;
		q.push(m);
	}
	int sum = 0,mid = 0,qwq = 0,qaq = 0;
	while(q.size() > 1) {
		mid = q.top();
		q.pop();
		sum = q.top();
		q.pop(); 
		qwq = mid + sum;
		qaq = qaq + qwq;   
		q.push(qwq);
	} 
	cout << qaq<<endl;
}
