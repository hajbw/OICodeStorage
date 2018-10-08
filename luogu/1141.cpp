/*
	P1141 01迷宫
*/
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::pair;
using std::queue;
using std::make_pair;

const int MAXN = 1005,MAXM = 100005;

int
	map[MAXN][MAXN],M,N,
	dx[] = {-1,1,0,0},dy[] = {0,0,-1,1},
	fa[MAXN * MAXN],ans[MAXN * MAXN];
char buf[MAXN];

inline int find(int a)
{
	while(fa[a] != fa[fa[a]])
		fa[a] = fa[fa[a]];

	return a;
}

int bfs(int x,int y)
{
	queue<pair<int,int> > quq;
	pair<int,int> a;

	quq.push(make_pair(x,y));

	while(!quq.empty())
	{
		a = quq.front();
		quq.pop();


	}
}

int main()
{
	int i,j;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
	{
		cin.getline(buf,MAXN);
		for(int j = 1;j <= N;++j)
			map[i][j] = buf[j - 1] - '0';
	}

	for(int i = 0;i < M;++i)
	{
		cin>>i>>j;
	}
}