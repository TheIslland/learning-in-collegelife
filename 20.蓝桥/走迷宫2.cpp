/*************************************************************************
	> File Name: 走迷宫2.cpp
	> Author:TheIslland 
	> Mail: 861436930@qq.com
	> Created Time: 2019年03月02日 星期六 20时22分44秒
 ************************************************************************/
#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct point{
	int x, y, sum;
	point(int tmp_x, int tmp_y, int dd) 
	{
		x = tmp_x;
		y = tmp_y;
		sum = dd;
	}
};
char mp[110][110];
int val = -1, star_x, star_y, n, m, vis[110][110];
int Go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int x,int y)
{
	queue<point> S;
	S.push(point(x,y,0));
	vis[x][y] = 1;
	while(!S.empty())
	{
		point tmp = S.front();
		int tmp_x = tmp.x;
		int tmp_y = tmp.y;
		S.pop();
		if(mp[tmp_x][tmp_y] == 'T')//表示到达终点
		{
			val = tmp.sum;
			return ;
		} 
		for(int i = 0; i<4; i++)
		{
			int tmp_xx = tmp_x + Go[i][0];
			int tmp_yy = tmp_y + Go[i][1];
			if(mp[tmp_xx][tmp_yy] != '#' && tmp_xx>=1 && tmp_xx <=n && tmp_yy>=1 && tmp_yy<=m && vis[tmp_xx][tmp_yy]==0)//条件都满足的情况下 
			{
				vis[tmp_xx][tmp_yy] = 1;
				S.push(point(tmp_xx,tmp_yy,tmp.sum+1));
			}
		}
	}
	return ; 
}
int main()
{
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin>>mp[i][j];
			if(mp[i][j] == 'S')
			{
				star_x = i;
				star_y = j;
			}
		}
	}
	bfs(star_x,star_y);
	if(val == -1)
	cout<<-1;
	else
	cout<<val;
	return 0;
}

