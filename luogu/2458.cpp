#include <iostream>

/**
	P2458 [SDOI2006]保安站岗
*/

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

using std::cin;
using std::cout;

const int
	MAXN = 1505,
	INF = 19260817,
	STAT_THIS = 0,STAT_CHILD = 1,STAT_FATHER = 2;

struct edge
{
	int to,next;
}edges[MAXN];

int
	N,
	cost[MAXN],
	head[MAXN],
	edges_index,
	dp[MAXN][3];//dp(node n,stat s):min cost

inline addedge(int u,int v)
{
	edges[++edges_index] = {v,head[u]};
	head[u] = edges_index;
}

template<class T> void read(std::istream &in,T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

void dfs(int node)
{
	int flag = 0,minc = INF,i = head[node];

	dp[node][0] = cost[node];
	dp[node][2] = 0;

	if(!i)//leaf node
	{
		dp[node][1] = INF;
		return;
	}

	for(;i;i = edges[i].next)
	{
		dfs(edges[i].to);
		dp[node][0] += min(dp[edges[i].to][0],min(dp[edges[i].to][1],dp[edges[i].to][2]));
		dp[node][2] += min(dp[edges[i].to][0],dp[edges[i].to][1]);
		if((minc = min(minc,dp[edges[i].to][0] - dp[edges[i].to][1])) < 0)
		{
			dp[node][1] += dp[edges[i].to][0];
			flag = 1;
		}
		else
			dp[node][1] += dp[edges[i].to][1];
	}

	if(!flag)
	{
		dp[node][1] += minc;
	}
}

int main()
{
	int a,b,c;//temps

	read(cin,N);
	for(int i = 0;i < N;++i)
	{
		read(cin,a);
		read(cin,cost[a]);
		read(cin,b);
		for(int j = 0;i < b;++j)
		{
			read(cin,c);
			addedge(a,c);
		}
	}

	dfs(1);

	cout<<min(dp[1][0],dp[1][1]);
}