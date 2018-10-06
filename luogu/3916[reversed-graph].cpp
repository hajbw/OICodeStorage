/*
	P3916 图的遍历
	AC
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

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

void dfs(int u,int s)
{
	if(ans[u])
		return;

	ans[u] = s;

	for(int i = head[u];i;i = e[i].n)
		dfs(e[i].v,s);
}

int main()
{
	int u,v;

	cin>>V>>E;
	for(int i = 1;i <= E;++i)
	{
		cin>>u>>v;
		addedge(v,u);
	}

	for(int i = V;i;--i)
		dfs(i,i);

	for(int i = 1;i <= V;++i)
		cout<<ans[i]<<' ';

	return 0;
}