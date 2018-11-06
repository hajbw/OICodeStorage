/*
	P1037 产生数
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXK = 16;

struct edge
{
	int v;
	edge *n;
}
edge_pool[MAXK],
*iedge = edge_pool,
*head[MAXK];

int cnt[10],ins[10];

inline void addedge(const int &u,const int &v)
{
	*(++iedge) = (edge){v,head[u]};
	head[u] = iedge;
}

int dfs(int u)
{
	if(cnt[u])
		return cnt[u];

	++cnt[u];
	++ins[u];

	for(edge *it = head[u];it;it = it->n)
	{

		cnt[u] += dfs(it->v);
	}

	--ins[u];
}