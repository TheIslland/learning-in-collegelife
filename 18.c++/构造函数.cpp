/*************************************************************************
	> File Name: 构造函数.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月01日 星期二 19时48分44秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Clock{
public:
    Clock(){
        second = 0;
        minute = 0;
        hour = 0;
    }
    Clock(int newS, int newM, int newH);
    void setTime(int newS,int newM,int newH){
        second=newS;
        minute=newM;
        hour=newH;
    }
    void showTime();
private:
    int second,minute,hour;
};
void Clock::showTime(){
    cout << hour << ":" << minute << ":" << second << endl;
}

Clock::Clock(int newS, int newM, int newH){
    second=newS;
    minute=newM;
	hour=newH;
}
int main(){
    Clock MyClock;
    //构造函数不能采用Clock MyClock(); 这种形式会被理解为函数
    MyClock.showTime();
    int second,minute,hour;
    cin >> second >> minute >> hour;
    MyClock.setTime(second,minute,hour);
    MyClock.showTime();
    Clock MyClock2(1, 2, 3);
    MyClock2.showTime();
    return 0;
}

