/*
	小奇回地球(earth)
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

const int MAXV = 105,MAXE = 10000;

struct edge
{
	int v,w,n;
}
e[MAXE];

int T,V,E,head[MAXV],iedge;

inline void addedge(const int &u,const int &v,const int &w)
{
	e[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

int main()
{
	int u,v,w;

	cin>>T;

	while(T--)
	{
		std::memset(e,0,sizeof(edge) * iedge);
		std::msmset(head,0,sizeof(int) * V);
		iedge = 0;

		cin>>V>>E;
		for(int i = 0;i < E;++i)
		{
			cin>>u>>v>>w;
			addedge(u,v,w);
		}

		
	}

	return 0;
}