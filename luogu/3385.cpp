/*
	P3385 【模板】负环
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::memset;

const int MAXV = 2005,MAXE = 6006;

struct edge
{
	int v,w,n;
}
edges[MAXE];

int head[MAXV],iedge,V,E;

inline void addedge(const int &u,const int &v,const int &w)
{
	edges[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

int main()
{
	cin>>T;
	while(T--)
	{
		int u,v,w;
		iedge = 0;
		for(int i = 1;i <= V;++i)
			head[i] = 0;
		for(int i = 1;i <= iedge;++i)
			edges[i] = (edge){};

		cin>>V>>E;
		for(int i = 0;i < E;++i)
		{
			cin>>u>>v>>w;
			addedge(u,v,w);
			if(w >= 0)
				addedge(v,u,w);
		}
	}
}