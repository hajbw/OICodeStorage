#include <iostream>
#include <cstring>

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

/**
	template:maxinum-network-flow
	also passing luogu P3376
*/

using std::cin;
using std::cout;

const int MAXV = 10005,MAXE = 100010;

struct Edge
{
	int to,next,cap,flow;
}
edges[MAXE],rev_edges[MAXE];

int
	V,E,S,T,//Vertices,Edges,Start point,Terminate point
	edge_index,
	head[MAXV],
	rev_head[MAXV],
	visited[MAXV];

void addedge(int u,int v,int cap)
{
	edges[edge_index].to = v;
	edges[edge_index].next = head[u];
	edges[edge_index].cap = cap;
	head[u] = edge_index;
	++edge_index;
	rev_edges[edge_index].to = v;
	rev_edges[edge_index].next = rev_head[u];
	rev_edges[edge_index].cap = cap;
	rev_head[v] = edge_index;
}

int* f(int u,int v)
/**
	adapter for sgq's f[][] (flow martix)
	hope it would never be useful
*/
{
	int edge = head[u];
	for(;edge != 0;edge = edges[edge].next)
		if(edges[edge].to = v)
			break;
	return edge ? &edges[edge].flow : (int*)0;
}

int dfs(int u,int amount)
/**
	dfs to improve

	arguments:
		u:current point
		amount:how much could this dfs path improve(in previous step)

	return:
		how much could this dfs path improve
*/
{
	if(u == T)
		return amount;
	visited[u] = 1;

	int min_,t;

	for(int edge = head[u];edge != 0;edge = edges[edge].next)
	{
		if(!visited[edges[edge].to] && edges[edge].cap > edges[edge].flow)
		{
			min_ = min(amount,edges[edge].cap - edges[edge].flow);
			t = dfs(edges[edge].to,min_);
			if(t)
			{
				edges[edge].flow += t;
				return t;
			}
		}
	}
	for(int edge = rev_head[u];edge != 0;edge = edges[edge].next)
	{
		if(!visited[edges[edge].to] && edges[edge].flow > 0)
		{
			min_ = min(amount,edges[edge].flow);
			t = dfs(edges[edge].to,min_);
			if(t)
			{
				edges[edge].flow -= t;
				return t;
			}
		}
	}

	return 0;
}

int main()
{
	int u,v,cap,temp,flow = 0;

	cin>>V>>E>>S>>T;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>cap;
		if(u != v)
			addedge(u,v,cap);
	}

	do
	{
		std::memset(visited,0,sizeof(visited));
		temp = dfs(S,1073741823);
		flow += temp;
	}
	while(temp);

	cout<<flow;

	return 0;
}
