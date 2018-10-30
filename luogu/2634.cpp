/*
	P2634 [国家集训队]聪聪可可
*/
#include <iostream>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXN = 20020;

struct edge
{
	int v,w;
	edge *n;
}
e[MAXN << 1],
*iedge = e,
*head[MAXN];

int dp[MAXN][3],ans[MAXN],N;
long long gcd_,N_;

inline void addedge(int u,int v,int w)
{
	*(++iedge) = (edge){v,w,head[u]};
	head[u] = iedge;
}

template<class T> T gcd(T a,T b)
{
	return b ? gcd(b,a % b) : a;
}

void dfs(int u,int fa = 0)
{
	++dp[u][0];

	for(edge *it = head[u];it;it = it->n)
	{
		if(it->v == fa)
			continue;

		dfs(it->v,u);

		ans[u] += ans[it->v];

		for(int i = 0;i < 3;++i)
			ans[u] += dp[u][(i + it->w) % 3] * dp[it->v][i];

		for(int i = 0;i < 3;++i)
			dp[u][(i + it->w) % 3] += dp[it->v][i];

		//for(edge *iit = head[u];iit != it;iit = iit->n)
		//	ans[u] += dp[it->v][(i + it->w) % 3] * dp[iit->v][(6 - i - it->w + iit->w) % 3];

#if DEBUG

		cout<<">\t"<<u;
		for(int i = 0;i < 3;++i)
			cout<<'\t'<<dp[u][i];
		cout<<'\n';

#endif
	}

	ans[u] += dp[u][0];//link subtree with u

#if DEBUG

	cout<<"->\t"<<u;
	for(int i = 0;i < 3;++i)
		cout<<'\t'<<dp[u][i];
	cout<<'\t'<<ans[u]<<'\n';

#endif
}

int main()
{
	int u,v,w;

	cin>>N;
	for(int i = 1;i < N;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}

#if DEBUG

	cout<<"\tu\tdp[0]\tdp[1]\tdp[2]\tans\n----------------------------------------------\n";

	dfs(1);

	// for(int i = 0;i < 3;++i)
	// {
	// 	for(int j = 1;j <= N;++j)
	// 		cout<<dp[j][i]<<'\t';
	// 	cout<<'\n';
	// }

#else

	dfs(1);

#endif
	
	//ans[1] += N;
	N_ = (long long)N * N;
	gcd_ = gcd(N_,(long long)ans[1]);
	cout<<(ans[1] / gcd_)<<'/'<<(N_ / gcd_);

	return 0;
}