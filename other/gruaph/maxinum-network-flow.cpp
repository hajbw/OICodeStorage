#include <iostream>
#include <cstring>

/**
	template:maxinum-network-flow
	also passing luogu P3376
*/

using std::cin;
using std::cout;

const MAXV = 10005,MAXE = 100010;

struct Edge
{
	int to,next,cap,flow;
}
edges[MAXE],rev_edges[MAXE];

int
	V,E,S,T,//Vertices,Edges,Start point,Terminate point
	edge_index,
	rev_edge_index,
	head[MAXV]
	rev_head[MAXV],
	visited[MAXV];

void addedge(int u,int v,int cap)
{
	edges[edge_index] = {v,head[u],cap};
	head[u] = edge_index;
	++edge_index;
	rev_edges[rev_edge_index] = {u,rev_head[v],cap};
	rev_head[v] = rev_edge_index;
	++rev_edge_index;
}

int dfs(int s,int amount)
/**
	dfs to improve

	arguments:
		s:current point
		amount:how much could this dfs path improve(in previous step)

	return:
		how much could this dfs path improve
*/
{
	if(s == T)
		return amount;
	for(int edge = head[s];edge != 0;edge = edges[edge].next)
	{

	}
}

int main()
{
	int u,v,cap,temp,flow = 0;

	cin>>V>>E>>S>>T;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>cap;
		addedge(u,v,cap);
	}

	do
	{
		std::memset(visited,0,sizeof(visited));
		temp = dfs(S,19260817);
		flow += temp;
	}
	while(temp);

	cout<<flow;

	return 0;
}
