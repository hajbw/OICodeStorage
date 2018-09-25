/*
	P3366 【模板】最小生成树
*/

#include <algorithm>
#include <iostream>

#define DEBUG 0

using std::cin;
using std::cout;

const int MAXV = 5050,MAXE = 200020;

struct edge
{
	int from,to,weight;
}
edges[MAXE<<1];

struct hpair
{
	int x,y;

	bool operator<(hpair &a)
	{
		return x == a.x ? y < a.y : x < a.x;
	}
}
pairs[MAXE];

int head[MAXV],iedge = 1,V,E,fa[MAXV];

inline void addedge(const int &u,const int &v,const int &w)
{
	edges[++iedge] = (edge){u,v,w};
	head[u] = iedge;
}

inline void addpair(const int &w)
{
	pairs[iedge>>1] = (hpair){w,iedge};
}

inline int find(const int &a)
{
	return fa[a] = fa[fa[a]];
}

int main()
{
	int u,v,w,a,cnt = 1,ans = 0;

	cin>>V>>E;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(u,v,w);
		addpair(w);
	}

	for(int i = 1;i <= E;++i)
		fa[i] = i;

	std::sort(pairs + 1,pairs + E + 1);

	for(int i = 1;i <= E && cnt < V;++i)
	{
		a = pairs[i].y;
		if(find(edges[a].from) != find(edges[a].to))
		{
			fa[find(edges[a].from)] = find(edges[a].to);
			ans += edges[a].weight;
			++cnt;

#if DEBUG
			cout<<edges[a].from<<'\t'<<edges[a].to<<'\t'<<edges[a].weight<<'\n';
#endif
		}
	}

	cout<<ans;

	return 0;
}
