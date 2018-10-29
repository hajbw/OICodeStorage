/*
	P1807 最长路_NOI导刊2010提高（07）
	AC
*/
#include <iostream>
#include <cstring>
#include <queue>

#define DEBUG 0

using std::cin;
using std::cout;
using std::queue;

const int MAXV = 1505,MAXE = 50010;

struct edge
{
	int v,w;
	edge *n;
}
edge_pool[MAXE],*iedge = edge_pool,
*head[MAXV];

int ind[MAXV],dis[MAXV],V,E;
queue<int> quq;

inline void addedge(int u,int v,int w)
{
	*(++iedge) = (edge){v,w,head[u]};
	head[u] = iedge;
}

template<class T> T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

template<class T> T min(const T &a,const T &b)
{
	return a < b ? a : b;
}

int main()
{
	int u,v,w;

	cin>>V>>E;

	std::memset(dis,128,sizeof(int) * (V + 1));

	for(int i = 1;i <= E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		++ind[v];
	}

	dis[1] = 0;
	for(int i = 1;i <= V;++i)
		if(!ind[i])
			quq.push(i);

	while(!quq.empty())
	{
		u = quq.front();
		quq.pop();

		for(edge *it = head[u];it;it = it->n)
		{
			v = it->v;
			dis[v] = max(dis[v],dis[u] + it->w);
			if(!--ind[v] && v != V)
				quq.push(v);
		}
	}

#if DEBUG
	for(int i = 1;i <= V;++i)
		cout<<i<<'\t'<<dis[i]<<'\n';

#else

	cout<<(dis[V] > 0 ? dis[V] : -1);

#endif

	return 0;
}