/*
	P4779 【模板】单源最短路径（标准版）
*/
#include <iostream>
#include <cstring>
#include <queue>

using std::cin;
using std::cout;

const int MAXV = 100000,MAXE = 200000,INF = 1000000007;

struct edge
{
	int v,w;
	edge *n;
}
edge_pool[MAXE],
*iedge = edge_pool,
*head[MAXV];

int
	V,E,S,
	vis[MAXV],dist[MAXV];

void addedge(const int &u,const int &v,const int &w)
{
	*(++iedge) = (edge){v,w,head[u]};
	head[u] = iedge;
}

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}

struct cmp
{
	bool operator()(const int &a,const int &b)
	{
		return dist[a] > dist[b];
	}
};

void dijkstra()
{
	//intitalize
	std::priority_queue<int,std::vector<int>,cmp> quq;
	int u,v;

	quq.push(S);

	while(!quq.empty())
	{
		u = quq.top();
		quq.pop();

		if(vis[u])
			continue;
		++vis[u];

		for(edge *it = head[u];it;it = it->n)
		{
			v = it->v;
			dist[v] = min(dist[v],dist[u] + it->w);
			quq.push(v);
		}
	}
}

int main()
{
	int u,v,w;

	cin>>V>>E>>S;
	for(int i = 1;i <= E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
	}

	//init
	//std::memset(dist,0x3f,sizeof(int) * (V + 2));
	for(int i = 1;i <= V;++i)
		dist[i] = INF;
	dist[S] = 0;

	dijkstra();
	//SPFA();

	for(int i = 1;i <= V;++i)
		cout<<dist[i]<<' ';

	return 0;
}