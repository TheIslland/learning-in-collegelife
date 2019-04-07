/*************************************************************************
	> File Name: test.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年01月22日 星期二 11时01分45秒
 ************************************************************************/
#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <queue>  
using namespace std;  

struct Node{  
    int x , y;  
    Node(int a = 0 , int b = 0){  
        x = a , y = b;  
    }  
    bool operator < (const Node& t)const{
        return x > t.x;
    }	
};  

void output(priority_queue<Node> &q) {
    while(!q.empty()){  
        Node t = q.top();  
        q.pop();  
        cout << t.x<<" " << t.y << endl;  
    }  
}
int main(){  
    priority_queue<Node> q;  
    q.push(Node(0 , 1));  
    q.push(Node(1 , 1));  
    q.push(Node(1 , 2));  
    output(q);
    Node temp = q.top();
    cout << temp.x << " " << temp.y;
    return 0;  
}  
