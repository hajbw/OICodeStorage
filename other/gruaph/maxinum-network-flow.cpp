#include <iostream>

/**
	template:maxinum-network-flow
	also passing luogu P3376
*/

using std::cin;
using std::cout;

const MAXV = 10000,MAXE = 50000;

struct Edge
{
	int to,next,cap;
}
edges[MAXE];

int
	V,E,S,T,//Vertices,Edges,Start point,Terminate point
	edge_index,
	head[MAXV];



void addedge(int u,int v,int cap)
{
	edges[edge_index] = {v,head[u],cap};
	head[u] = edge_index;
	++edge_index;
}

int main()
{
	int u,v,cap;

	cin>>V>>E>>S>>T;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>cap;
		addedge(u,v,cap);
	}

	//cout<<ans;

	return 0;
}