/*************************************************************************
	> File Name: 自由之翼.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月09日 星期三 16时58分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct Point {
    int value, ind;
    string name;
} Point;

class People {
private:
    int Time;
    int Minerals;
    Point cost[3];
public:
    People(int minerals) {
        Time = 0;
        Minerals = minerals;
    }
    void Set_cost(Point a, Point b, Point c) {
        cost[0] = a;
        cost[1] = b;
        cost[2] = c;
    } 
    void Builded(string str) {
        int num = 0, flag = 0;
        while (1) {
            if (flag >= 3) break;
            if (Minerals - cost[num].value < 0) {
                flag++;
                num = (num + 1) % 3;
                continue ;
            }
            flag = 0;
            cout << "Time: " << Time << "  " << str << " " << cost[num].name << " " << Time << " born with HP " << cost[num].value << " " << cost[num].ind << " " << cost[num].name << " in base " << str << endl;
            Time += 1;
            cost[num].ind += 1;
            Minerals -= cost[num].value;
            num = (num + 1) % 3;
        }
        cout << "Time: " << Time - 1 << "  " << str << " base stop training troopers." << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Point a, b, c;
    a.value = 10;
    a.ind = 1;
    a.name = "SCV";
    b.value = 5;
    b.ind = 1;
    b.name = "Marine";
    c.value = 4;
    c.ind = 1;
    c.name = "Medic";
    People Raynor(n);
    Raynor.Set_cost(a, b, c);
    Raynor.Builded("Raynor");
    People Mengsk(n);
    Mengsk.Set_cost(b, c, a);
    Mengsk.Builded("Mengsk");
    return 0;
}
