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

void dfs(int u)
{
	ans[u] = u;
	for(int i = head[u],v;i;i = e[i].n)
	{
		if(!ans[e[i].v])
			dfs(e[i].v);

		if(u == 5)
			cout<<ans[u]<<'\t'<<ans[e[i].v]<<'\n';
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

	for(int i = 1;i <= V;++i)
	{
		cout<<i;
		for(int j = head[i];j;i = e[j].n)
		{
			cout<<" -> "<<e[j].v;
		}
		cout<<"\\\n";
	}

	for(int i = 1;i <= V;++i)
		if(!ans[i])
			dfs(i);

	for(int i = 1;i <= V;++i)
		cout<<ans[i]<<' ';
}