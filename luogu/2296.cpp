/*
	P2296 寻找道路
*/
#include <iostream>
#include <cstring>
#include <queue>

using std::cin;
using std::cout;

const int MAXV = 10005,MAXE = 200010;
const int T_UNDEF = 0,T_A = 1,T_NA = -1,INF = 0x3f3f3f3f;

struct edge
{
	int v;
	edge *n;
}
edge_pool[MAXE],
*iedge = edge_pool,
*head[MAXV];

int V,E,S,T,tag[MAXV],dist[MAXV],vis[MAXV];

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}

inline void addedge(int u,int v)
{
	*(++iedge) = (edge){v,head[u]};
	head[u] = iedge;
}

void dfs1(const int &u)
{
	++tag[u];

	for(edge *it = head[u];it;it = it->n)
		if(!tag[it->v])
			dfs1(it->v);
}

void dfs2(const int &u)
{
	if(u == S)
		return;

	tag[u] = T_NA;

	for(edge *it = head[u];it;it = it->n)
		if(tag[it->v] != T_NA)
			dfs2(it->v);
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
	std::priority_queue<int,std::vector<int>,cmp> quq;
	register int u;

	std::memset(dist,0x3f,sizeof(int) * (V + 2));
	dist[T] = 0;

	quq.push(T);

	while(!quq.empty())
	{
		u = quq.top();
		quq.pop();

		if(vis[u])
			continue;
		++vis[u];

		for(edge *it = head[u];it;it = it->n)
		{
			if(tag[it->v] == T_NA)
				continue;
			dist[it->v] = min(dist[it->v],dist[u] + 1);
			quq.push(it->v);
		}
	}
}

int main()
{
	register int u,v;

	cin>>V>>E;
	for(register int i = 1;i <= E;++i)
	{
		cin>>u>>v;
		if(u != v)
			addedge(v,u);
	}
	cin>>S>>T;

	dfs1(T);
	for(register int i = 1;i <= V;++i)
		if(!tag[i])
			dfs2(i);

	dijkstra();

	cout<<(dist[S] >= INF ? -1 : dist[S]);

	return 0;
}