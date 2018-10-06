/*
	P3916 图的遍历
*/
#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXV = 100005,MAXE = 100005;

struct edge
{
	int v,n;
}
e[MAXE];

int head[MAXV],iedge,ans[MAXV],V,E;

inline void addedge(const int &u,const int &v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

void dfs(int u)
{
	ans[u] = u;
	for(int i = head[u],v;i;i = e[i].n)
	{
		if(!ans[e[i].v])
			dfs(e[i].v);
		ans[u] = max(ans[u],ans[e[i].v]);
	}
}

int main()
{
	int u,v;

	cin>>V>>E;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v;
		addedge(u,v);
	}

#if DEBUG
	for(int i = 1;i <= V;++i)
	{
		cout<<i;
		for(int j = head[i];j;i = e[j].n)
		{
			cout<<" -> "<<e[j].v;
		}
		cout<<"\\\n";
	}
#endif

	for(int i = 1;i <= V;++i)
		if(!ans[i])
			dfs(i);

	for(int i = 1;i <= V;++i)
		cout<<ans[i]<<' ';
}