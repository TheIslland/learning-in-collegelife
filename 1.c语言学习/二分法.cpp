#include <iostream>
using namespace std;
int binary_search(int *arr, int l, int r, int x) {
	if (l > r) return -1;
	int mid = (l + r) >> 1;
	if (arr[mid] == x) return mid;
	else if (arr[mid] > x) return binary_search(arr, l, mid - 1, x);
	else return binary_search(arr, mid + 1, r, x);
}
int main() {
	int array[10], x;
	cin >> x;
	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}
	int ans = binary_search(array, 0, 10, x);
	if (ans != -1) {
		cout << "带查找数字是数组中的第" << ans + 1 << "个数，下标为：" << ans << endl;
	}
	else {
		cout << "数组中不存在带查找数字" << endl;
	}
	return 0;
}