/*************************************************************************
	> File Name: 网络交友.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年02月26日 星期二 02时36分34秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<set>
using namespace std;
int pa[10010];

void inline init(){//有五千组朋友关系，最多有10000个人
    for(int i = 1; i <= 10000;i++)
     pa[i] = i;
}

int find(int x){
    if(x != pa[x]) pa[x] = find(pa[x]);
    return pa[x];
}

void unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) pa[fx] = fy;
}

int main(){
    int T;
    cin >> T; 
    string a , b;
    set<string>se;//建立一个集合
    map<string,int>mp;//建立一个映射
    int p = 1;
    init();
    while(T--){
        cin >> a >> b;
        if(!se.count(a)){//判断a这个人有没有出现过
            se.insert(a);//没出现就加入集合
            mp[a] = p++;//没出现就给一个新的编号
        }
        if(!se.count(b)){//同上判断b
            se.insert(b);
            mp[b] = p++;
        }
        unite(mp[a],mp[b]);//联合
        int ans = 0;
        for(int i = 1; i < p; i++) //判断和以这个为根节点的人有多少个
         if(find(i) == find(mp[b])) ans++;
        cout << ans << endl; 
    }
    return 0;
} 

