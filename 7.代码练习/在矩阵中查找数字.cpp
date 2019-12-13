#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> a, int target) {
    int l = 0, r = a.size() - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
		if (target == a[mid]) return true;
        if (a[mid] > target) {
			r = mid - 1;
        } else {
			l = mid + 1;
    	}
	}
    return false;
}

bool find_target(vector< vector<int> >& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    if (target > matrix[n - 1][m - 1]) return false;
    int l = 0, r = n - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
		if (target <= matrix[mid][m - 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return binary_search(matrix[r], target);
}
int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > v(n);
	int tp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			cin >> tp;
			v[i].push_back(tp);
		}
	}
	int tot;
	cin >> tot;
	for (int i = 0; i < tot; ++i) {
		cin >> tp;
		if (find_target(v, tp)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}