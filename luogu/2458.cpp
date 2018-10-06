/*
	P2458 [SDOI2006]保安站岗
	AC
*/
#include <iostream>
#include <climits>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1505,INF = 16000000;

struct edge
{
	int v;
	edge *n;

	edge():v(),n(){}
	edge(int v,edge *n):v(v),n(n){}
}
*tree[MAXN];

int
	fee[MAXN],
	dp[MAXN][3];//min-cost[v][curr/son/fa]

void dfs(int u,int fa)
{
	int
		v,
		a,				//min (dp[v][0],dp[v][1])
		curr_b,b = INF,	//min(dp[v][0] - dp[v][1])
		flag_1 = false;	//flag_son_volunteer

	dp[u][0] = fee[u];

	for(edge *it = tree[u];it;it = it->n)
	{
		v = it->v;
		if(v == fa)
			continue;
		dfs(v,u);
		dp[u][2] += (a = min(dp[v][0],dp[v][1]));
		dp[u][0] += min(a,dp[v][2]);

		if(dp[v][0] <= dp[v][1])//son volunteers
		{
			dp[u][1] += dp[v][0];
			flag_1 = true;
		}
		else
		{
			dp[u][1] += dp[v][1];
			//min cost amoung childs to be
			if(!flag_1 && (curr_b = dp[v][0] - dp[v][1]) < b)
				b = curr_b;
		}
	}

	if(!flag_1)//no sons volunteers
		dp[u][1] += b; 

}

int main()
{
	int N,u,c,v,w;

	cin>>N;

	for(int i = 1;i <= N;++i)
	{
		cin>>u>>w>>c;
		fee[u] = w;
		for(int j = 0;j < c;++j)
		{
			cin>>v;
			tree[u] = new edge(v,tree[u]);
			tree[v] = new edge(u,tree[v]);
		}
	}

	dfs(1,0);

	cout<<min(dp[1][0],dp[1][1]);

	return 0;
}