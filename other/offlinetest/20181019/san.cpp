/*
	1. 跳跃
*/
#include <iostream>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 42;

struct edge
{
	int v,n;
}
e[MAXN * MAXN];
int
	N,sum,
	iedge,head[MAXN],
	h[MAXN],g[MAXN];//ans[MAXN],tans,

unsigned long long tans,ans[MAXN],K;

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

void dfs(int u)
{
	if(ans[u])
	{
		tans += ans[u];
		return;
	}

	ans[u] = tans;

	sum += g[u];

	if(sum >= K)
		++tans;

	for(int i = head[u];i;i = e[i].n)
	{
		dfs(e[i].v);
	}

	sum -= g[u];

	ans[u] = tans - ans[u];
}

int main()
{
#if !DEBUG

	freopen("san.in","r",stdin);
	freopen("san.out","w",stdout);

#endif

	cin>>N>>K;

	for(int i = 1;i <= N;++i)
	{
		cin>>h[i]>>g[i];
		for(int j = 1;j < i;++j)
			if(h[i] >= h[j])
			{
				cout<<i<<'\t'<<j<<'\n';
				addedge(i,j);
			}
	}

#if DEBUG

	for(int i = 1;i <= N;++i)
	{
		cout<<i;
		for(int j = head[i];j;j = e[j].n)
			cout<<" -> "<<e[j].v;
		cout<<'\n';
	}

#endif

	for(int i = 1;i <= N;++i)
		dfs(i);

	cout<<tans;

	return 0;
}