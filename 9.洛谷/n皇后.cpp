/*************************************************************************
	> File Name: n皇后.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月02日 星期六 16时13分40秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n;  // 棋盘大小
int ans = 0;  // 解的个数
int a[30] = {0};  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
int x1[30] = {0};  // 左下-右上 对角线的占用情况
int y1[30] = {0};  // 左上-右下 对角线的占用情况
int num[30];
void print() {
    if (ans <= 2) {
        for (int i = 0; i < n; i++) {
            cout << num[i] + 1 << " ";
        }
            cout << endl;
    }
    ans++;
}
void dfs(int deep) {  // deep 表示当前搜索到第几行
    if (deep >= n) {  // 搜索完最后一行，说明找到了一组合法解
        print();
        return;  // 回溯
    }
    for (int i = 0; i < n; i++) {  // 枚举当前行的皇后放置到第 i 列
        if (x1[i + deep] == 0 && y1[i - deep + n] == 0 && a[i] == 0) {  // 判断该皇后是否与已放置的皇后发生冲突
            num[deep] = i;
            // 放置皇后 (deep, i)，一共需要修改三个标记数组
            x1[deep + i] = y1[i - deep + n] = a[i] = 1;
            dfs(deep + 1);  // 当前行枚举完毕，搜索下一行
            // 恢复放置皇后 (deep, i) 前的状态
            a[i] = x1[deep + i] = y1[i - deep + n] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    cout << ans;
    return 0;
}
