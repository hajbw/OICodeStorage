/*
	P1529 回家 Bessie Come Home
*/
#include <iostream>
#include <queue>
#include <utility>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::priority_queue;

const int MAXV = 55,MAXE = 10000,INF = 2147483647;

struct edge
{
	int v,w,n;
}
e[MAXE];

int V = 52,E,iedge = 1,head[MAXV]

inline int convert(char ch)
{
	if(ch >= 'a' && ch <= 'z')//['a','z'] => [1,26]
		return ch - 'a' + 1;
	if(ch >= 'A' && ch <= 'Z')//['A','Z'] => [27,52]
		return ch - 'A' + 27;
	return 0;
}

pair<int,int> bfs()
{
	priority_queue<pair<int,int>> quq;//dist,v
	pair<int,int> ans(INF,0);

	quq.push(make_pair(0,convert('Z')));

	while(!quq.empty())
	{
		pair<int,int> u = quq.top();
		quq.pop();

		if(u.second > 26 && u.second < 52)
			ans = min(ans,u);
		else
			for(int i = head[u.second];i;i = e[i].n)
				quq.push(make_pair(u.first + e[i].w,e[i].v));

		return ans;
	}
}

inline void addedge(int u,int v,int w)
{
	e[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

int main()
{
	char u,v;
	int w;
	pair<int,int> ans;

	cin>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>w;
		addedge(convert(u),convert(v),w);
		addedge(convert(v),convert(u),w);
	}

	ans = bfs();

	cout<<char(ans.first - 27 + 'A')<<' '<<ans.second;

	return 0;
}