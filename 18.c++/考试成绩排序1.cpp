/*************************************************************************
	> File Name: 考试成绩排序1.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月06日 星期三 22时22分36秒
 ************************************************************************/
#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

using std::cin;

using std::cout;

using std::endl;

using std::vector;

using std::sort;

using std::string;

 

class People {

    public :

    string name;

    int score;

};

 

int main() {

    vector<People> arr;

    People temp;

    while (cin >> temp.name) {

        cin >> temp.score;

        arr.push_back(temp);

    }

    sort(

         arr.begin(),

         arr.end(),

         [](const People &a, const People &b) {

             if (a.score < b.score) return true;

             if (a.score == b.score && a.name < b.name) return true;

             return false;

         }

         );

    auto iter = arr.begin();

    for (; iter != arr.end(); ++iter) {

        cout << iter->name << " " << iter->score << endl;

    }

    cout << arr.size() << endl;

    return 0;

}
