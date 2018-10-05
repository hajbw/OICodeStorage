/*
	P2458 [SDOI2006]保安站岗
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 1505;

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

int main()
{
	int N,u,c,v,w;

	cin>>N;

	for(int i = 1;i <= N;++i)
	{
		cin>>u>>w>>c;
		fee[u] = w;
		for(int j = 0;i < c;++j)
		{
			cin>>v;
			tree[u] = new node(v,tree[u]);
		}
	}
}