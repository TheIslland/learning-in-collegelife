/*************************************************************************
	> File Name: LeetCode_202_快乐数.c
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2018年10月19日 星期五 20时32分07秒
 ************************************************************************/
int get_value(int x) {
    int ans = 0;
    while (x) {
        ans += (x % 10) * (x % 10);
        x /= 10;
    }
    return ans;
}

bool isHappy(int n) {
    int slow = n, fast = get_value(n);
    while (fast != 1) {
        slow = get_value(slow);
        fast = get_value(get_value(fast));
        if (slow == fast) return false;
    }
    return true;
}

/*关于快乐数使用快慢指针的证明，
 * 对于本题我们可以理解为有一函数ｘ＝ｆ（ｘ）
 * 当ｘ为什么时最终ｘ为１当ｘ为什么时最终ｘ不为１
 * 经过判断函数逐渐收敛时最终结果为１，但当函数循环不收敛时始终不唯一
 * 
