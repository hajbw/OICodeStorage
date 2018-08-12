#include <iostream>
#include <cstring>
#include <algorithm>

/**
	hajbw mega graph template
*/

#define KRUSKAL 1

using std::cin;
using std::cout;
using std::memset;

typedef int num_t;

const int MAXV = 10000,MAXE = 100000;

struct edge
{
#if KRUSKAL
	int from;
#endif
	int to,next;
	num_t weight;

	bool operator<(edge &a){return this->weight < a.weight;}
}
edges[MAXE];

template<class T1,class T2>struct hpair
{
	T1 first;
	T2 second;
	hpair(T1 a,T2 b):first(a),second(b){}
	hpair(T1 a):first(a),second(){}
	hpair():first(),second(){}
};

int
	V,E,
	iedge,
	head[MAXV],
	visited[MAXV];

template<class T>void read(std::istream &in,T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';in.get(ch);}
	if(flag)x = -x;
}

inline void addedge(int u,int v,num_t w)
#if KRUSKAL
{
	edges[++iedge] = (edge){u,v,head[u],w};
	head[u] = iedge;
}
#else
{
	edges[++iedge] = (edge){v,head[u],w};
	head[u] = iedge;
}
#endif

/**
void print_dfs(std::ostream &out,int start = 1)
{
	visited[start] = 1;
	out<<start;
	for(int j = head[start];j;j = edges[j].next)
	{
		if(!visited[edges[j].next])
		{
			out<<" -> ";
			print_dfs(out,edges[j].next);
		}
	}
}
*/

void print_traverse_edges(std::ostream &out,int V)
{
	for(int i = 0;i < V;++i)
	{
		out<<"vert "<<i;
		for(int j = head[i];j;j = edges[j].next)
			out<<"  - "<<edges[j].weight<<" -> "<<edges[j].to;
		out<<"\n";
	}
}

#if KRUSKAL
int mininum_spanning_tree_kruskal()
{
	edge *edges_cpy = new edge[V + 2];
	std::memcpy(edges_cpy,edges,(V + 1) * sizeof(int));
	std::sort(edges_cpy + 1,edges_cpy + V + 1);
}
#endif

int mininum_spanning_tree_prim()
{
	return 0;
}



int main()
{
	int u,v,w;

	read(cin,V);
	read(cin,E);
	for(int i = 0;i < E;++i)
	{
		read(cin,u);read(cin,v);read(cin,w);
		addedge(u,v,w);
	}
	return 0;
}