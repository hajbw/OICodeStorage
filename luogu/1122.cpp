/*
	P1122 最大子树和
	AC
*/
#include <iostream>
#include <climits>

using std::cin;
using std::cout;

const int MAXN = 16061;

struct edge
{
	int v,n;
}
e[MAXN << 1];

int
	head[MAXN],iedge = 1,N,
	dp[MAXN];//max-val[node]

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

template<class T>T max(const T &a,const T &b)
{
	return a > b ? a : b;
}

void dfs(int u,int last)
{
	int v;
	for(int i = head[u];i;i = e[i].n)
	{
		v = e[i].v;
		if(v == last)
			continue;
		dfs(v,u);
		dp[u] += dp[v];
	}

	if(dp[u] & INT_MIN)//if dp[u] < 0
		dp[u] = 0;
}

int main()
{
	int a,b;

	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>dp[i];

	for(int i = 1;i < N;++i)
	{
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}

	a = 1;
	while(dp[a] <= 0)
		++a;
	dfs(a,0);

	cout<<dp[a];

	return 0;
}