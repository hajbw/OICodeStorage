/*
	P3371 【模板】单源最短路径（弱化版）
*/
#include <iostream>
#include <utility>
#include <queue>
//use INT_MAX directly???
//not on luogu.org :(
#include <climits>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;
using std::priority_queue;

const int MAXV = 20005,MAXE = 600010;

struct edge
{
	int v,w,n;
}
edges[MAXE];

int
	V,E,S,
	head[MAXV],
	vis[MAXV],dist[MAXV];//is-finished[v],min-dist[v]

void addedge(const int &i,const int &u,const int &v,const int &w)
{
	edges[i] = (edge){v,w,head[u]};
	head[u] = i;
}

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
	priority_queue<int,std::vector<int>,cmp> quq;
	int u,v;

	for(int i = 1;i <= E;++i)
		dist[i] = INT_MAX;
	dist[S] = 0;

	quq.push(S);

	while(!quq.empty())
	{
		u = quq.top();
		quq.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int i = head[u];i;i = edges[i].n)
		{
			v = edges[i].v;
			dist[v] = min(dist[v],dist[u] + edges[i].w);
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
		addedge(i,u,v,w);
	}

	dijkstra();

	for(int i = 1;i <= V;++i)
		cout<<dist[i]<<' ';

	return 0;
}