/*
	P3371 【模板】单源最短路径（弱化版）
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using std::cin;
using std::cout;

const int MAXV = 1000050,MAXE = 5000100;

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

void SPFA()
{
	std::queue<int> quq;
	int u;

	//note: vis now means inqueue
	vis[S] = 1;
	quq.push(S);

	while(!quq.empty())
	{
		u = quq.front();
		quq.pop();

		for(edge *it = head[u];it;it = it->n)
		{
			if(dist[u] >= dist[it->v] - it->w)
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
	int u,v,w;

	cin>>V>>E>>S;
	for(int i = 1;i <= E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
	}

	//init
	std::memset(dist,0x3f,sizeof(int) * (V + 2));
	dist[S] = 0;

	dijkstra();
	//SPFA();

	for(int i = 1;i <= V;++i)
		cout<<dist[i]<<' ';

	return 0;
}