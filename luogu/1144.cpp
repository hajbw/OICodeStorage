/*
	P1144 最短路计数
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXV = 1000005,MAXE = 2000005;

struct edge
{
	int v;
	edge *n;
}
edge_pool[MAXE],
*iedge = edge_pool,
*head[MAXV];

int
	V,E,
	vis[MAXV],dist[MAXV],cnt[MAXV],heap[MAXV << 1],*r = heap;

inline void addedge(const int &u,const int &v)
{
	*(++iedge) = (edge){v,head[u]};
	head[u] = iedge;
}

inline bool cmp(const int &a,const int &b)
{
	return dist[a] > dist[b];
}

inline void push(const int &a)
{
	*(r++) = a;
	std::push_heap(heap,r,cmp);
}

inline void pop()
{
	std::pop_heap(heap,r,cmp);
	--r;
} 

void dijkstra()
{
	register int u,v;

	push(1);
	++vis[1];

	while(r != heap)
	{
		u = *heap;
		pop();

		if(vis[u])
			continue;

		++vis[u];

		for(edge *it = head[u];it;it = it->n)
		{
			v = it->v;
			if(dist[u] < dist[v] - it->w)
			{
				dist[v] = dist[u] + it->w;
				cnt[v] = 1;
			}
			else if(dist[u] == dist[v] - it->w)
				++cnt[v];
			push(v);
		}
	}
}