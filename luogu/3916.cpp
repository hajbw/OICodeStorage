/*
	P3916 图的遍历
*/
#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

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

int dfs(int u)
{
	if(!ans[u])
	{
		ans[u] = u;
		for(int i = head[u];i;i = e[i].n)
		{
			ans[u] = max(ans[u],dfs(e[i].v));
		}
	}
	return ans[u];
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

	for(int i = 1;i <= V;++i)
		if(!ans[i])
			dfs(i);

	for(int i = 1;i <= V;++i)
		cout<<ans[i]<<' ';
}