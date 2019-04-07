/*************************************************************************
	> File Name: put_cmp.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月24日 星期日 08时36分30秒
 ************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
int main(){
    ifstream op;
    string str1,str2;
    op.open("output1.txt");
    while(!op.eof())
        str1+=op.get();
    op.close();
    op.open("output3.txt");
    while(!op.eof())
        str2+=op.get();
    op.close();
	int num = 1;
    if(str1==str2)
        puts("YES");
    else
        puts("NO");
    return 0;
}
