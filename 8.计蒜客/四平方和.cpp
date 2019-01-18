/*************************************************************************
	> File Name: 四平方和.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月18日 星期五 11时52分29秒
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int i,j,sum=0,a,b,c,d,e, flag = 0;
	cin >> i;
	for(a = 0;a * a <= i;a++) {
        int va = a * a;
		for(b =0;va + b * b <= i;b++) {
			int vb = va + b * b;
            for(c = 0;vb + c * c <= i;c++) {
                int vc = vb + c * c;
				int temp = i - vc;
                int judg = sqrt(temp);
                if (temp == judg * judg) {
					cout<<a<<' '<<b<<' '<<c<<' '<<judg<<endl;
                	flag = 1;
                    break;
                }
			}
            if (flag) break;
		}
        if (flag) break;
	}
}
