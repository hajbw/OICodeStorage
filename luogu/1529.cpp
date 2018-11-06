/*
	P1529 回家 Bessie Come Home
*/
#include <iostream>
#include <cstring>
#include <queue>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXV = 127,MAXE = 20005,INF = 0x3f3f3f3f;

struct edge
{
	int v,w;
	edge *n;
}
edge_pool[MAXE],
*iedge = edge_pool,
*head[MAXV];

int P,dist[MAXV],vis[MAXV];

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}

inline void addedge(const int &u,const int &v,const int &w)
{
	*(++iedge) = (edge){v,w,head[u]};
	head[u] = iedge;
}

void SPFA()
{
	std::queue<int> quq;
	int u;

	quq.push('Z');
	vis['Z'] = 1;

	while(!quq.empty())
	{
		u = quq.front();
		quq.pop();

		for(edge *it = head[u];it;it = it->n)
		{
			if(dist[u] + it->w >= dist[it->v])
				continue;

			dist[it->v] = dist[u] + it->w;

			if(vis[it->v])
				continue;

			vis[it->v] = 1;
			quq.push(it->v);
		}

		vis[u] = 0;
	}
}

int main()
{
	char u,v;
	int w,ans = INF;

	cin>>P;
	for(int i = 1;i <= P;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}

	std::memset(dist,0x3f,sizeof(dist));
	dist['Z'] = 0;

	SPFA();

	for(char i = 'A';i <= 'Z';++i)
		cout<<i<<" "<<dist[i]<<'\n';

	for(int i = 'A';i < 'Z';++i)
		if(dist[i] < ans)
			ans = dist[i],
			u = i;

	cout<<u<<" "<<ans;

	return 0;
}