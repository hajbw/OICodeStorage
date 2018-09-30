/*
	P3366 【模板】最小生成树
	AC
*/

#include <algorithm>
#include <iostream>

#define DEBUG 0

using std::cin;
using std::cout;
using std::ostream;

const int MAXV = 5050,MAXE = 200020;

struct edge
{
	int u,v,w,n;

	friend ostream& operator<<(ostream &out,edge &a)
	{
		return out<<a.u<<'\t'<<a.v<<'\t'<<a.w;
	}
}
edges[MAXE<<1];

struct hpair
{
	int x,y;

	bool operator<(hpair &a)
	{
		return x == a.x ? y < a.y : x < a.x;
	}

	friend ostream& operator<<(ostream &out,hpair &a)
	{
		return out<<a.x<<'\t'<<a.y<<'\t'<<edges[a.y];
	}
}
weights[MAXE];

int fa[MAXV],head[MAXV],iedge = 1,V,E;

inline void addedge(const int &u,const int &v,const int &w)
{
	edges[++iedge] = (edge){u,v,w,head[u]};
	head[u] = iedge;
}

inline int find(const int &a)
{
	while(fa[a] != fa[fa[a]])
		fa[a] = fa[fa[a]];
	return fa[a];
}

int main()
{
	int u,v,w,ans = 0,flag = false;

	cin>>V>>E;
	for(int i = 1;i <= V;++i)
		fa[i] = i;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
		weights[iedge >> 1] = (hpair){w,iedge};
	}

	std::sort(weights + 1,weights + E + 1);

#if DEBUG
	cout<<"w\tiedge\tu\tv\tw\n_________________________________\n";
	for(int i = 1;i <= E;++i)
		cout<<weights[i]<<'\n';
#endif

	for(int i = 1,cnt = 0,curr;/*i <= E && */cnt < V - 1;++i)
	{
		if(i > E)//"index out of range"
		{
			flag = true;
			break;
		}

#if DEBUG
		cout<<i<<'\t'<<cnt<<'\t'<<ans<<'\n';
#endif
		curr	= weights[i].y;
		u		= edges[curr].u;
		v		= edges[curr].v;

		if(find(u) == find(v))
			continue;

		fa[find(u)] = find(v);
		
		ans += edges[curr].w;
		++cnt;
	}

	if(flag)
		cout<<"orz";
	else
		cout<<ans;

	return 0;
}