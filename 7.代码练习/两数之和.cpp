/*************************************************************************
	> File Name: 两数之和.cpp
	> Author: TheIslland
	> Mail: voidland@163.com, 861436930@qq.com
	> Created Time: Sun Oct 27 19:58:30 2019
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
vector<int> get_two_sum(vector<int>& numbers, int target) {
	int l = 0, r = numbers.size() - 1, mid;
	while (l < r) {
		if (numbers[l] + numbers[r] == target) {
			vector<int> ans;
			ans.push_back(l);
			ans.push_back(r);
			return ans;
		}
		else if (numbers[l] + numbers[r] > target) {
			r--;
		}
		else {
			l++;
		}
	}
}
int main() {
	int n;
	vector<int> v;
	cin >> n;
	int tp;
	for (int i = 0; i < n; ++i) {
		cin >> tp;
		v.push_back(tp);
	}
	int x;
	cin >> x;
	vector<int> ans = get_two_sum(v, x);
	if (ans.size() == 2) {
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;
}