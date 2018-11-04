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

const int MAXV = 130,MAXE = 10000,INF = 2147483647;

struct edge
{
	int v,w,n;
}
e[MAXE*2];

int V = 52,E,iedge = 1,head[MAXV],dist[MAXV];

pair<int,int> bfs()
{
	std::queue<pair<int,int>> quq;//dist,v
	pair<int,int> ans(INF,0);

	quq.push(make_pair(0,(int)'Z'));

	while(!quq.empty())
	{
		pair<int,int> u = quq.front();
		quq.pop();

		dist[u.second] = u.first;

		if(u.second >= 'A' && u.second < 'Z')
			ans = min(ans,u);
//		else
//		{
			for(int i = head[u.second];i;i = e[i].n)
			{
				if(dist[e[i].v])
					dist[e[i].v] = min(dist[e[i].v],u.first + e[i].w);
				else
					quq.push(make_pair(u.first + e[i].w,e[i].v));
			}
//		}
	}

	return ans;
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
		addedge(u,v,w);
		addedge(v,u,w);
	}

	ans = bfs();

	cout<<(char)ans.second<<' '<<ans.first;

	return 0;
}