/*
	P3371 【模板】单源最短路径（弱化版）
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXV = 10005,MAXE = 500010;

struct edge
{
	int v,w,n;
}
edges[MAXE];

int
	V,E,S,
	iedge,head[MAXV],
	fin[MAXV],dist[MAXV];//is-finished[v],min-dist[v]

void addedge(const int &u,const int &v,const int &w)
{
	edges[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

void dijkstra()
{

}

int main()
{
	int u,v,w;

	cin>>V>>E>>S;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
}