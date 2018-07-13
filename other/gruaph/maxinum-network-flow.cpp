#include <iostream>
#include <cstring>

#ifndef min
#define min(a,b) (a < b ? a : b)
#endif

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

#define rev(edg_index) (edg_index ^ 1)

/**
	template:maxinum-network-flow
	also passing luogu P3376
*/

using std::cin;
using std::cout;

const int MAXV = 10005,MAXE = 100010,READ_MAX_LINE_LENTH = 40;

struct Edge
{
	int to,next,cap;
}
edges[MAXE << 1];

/*
	NOTE:
		index(edge) % 2 == 0
		index(rev_edge) % 2 == 1
*/

int
	V,E,S,T,//Vertices,Edges,Start point,Terminate point
	edge_index,
	head[MAXV],
	visited[MAXV];


char buf[READ_MAX_LINE_LENTH];
template<class T> void read(T &x,T &y,T &z)
{
	x = y = z = 0;

	char *ptr = buf;
	cin.getline(buf,READ_MAX_LINE_LENTH);
	int flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		x = (x<<1) + (x<<3) + (*ptr-'0');//2x+8x+int(*ptr)
		++ptr;
	}
	if(flag)
		x = ~x + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		y = (y<<1) + (y<<3) + (*ptr-'0');//2y+8y+int(*ptr)
		++ptr;
	}
	if(flag)
		y = ~y + 1;
	flag = 0;
	while(*ptr < '0' || *ptr > '9')
	{
		flag ^= (*ptr == '-');
		++ptr;
	}
	while(*ptr >= '0' && *ptr <= '9')
	{
		z = (z<<1) + (z<<3) + (*ptr-'0');//2z+8z+int(*ptr)
		++ptr;
	}
	if(flag)
		z = ~z + 1;
}

void addedge(int u,int v,int cap)
{
	edges[edge_index].to = v;
	edges[edge_index].next = head[u];
	edges[edge_index].cap = cap;
	head[u] = edge_index;
	++edge_index;
	edges[edge_index].to = u;
	edges[edge_index].next = head[v];
	edges[edge_index].cap = 0;
	head[v] = edge_index;
	++edge_index;
}

int dfs(int u,int amount)
/**
	dfs to improve

	arguments:
		u:current point
		amount:how much could this dfs path improve(in previous step)

	return:
		how much could this dfs path improve
*/
{
	if(u == T)
		return amount;
	visited[u] = 1;

	int min_,t;

	for(int edge = head[u];edge != 0;edge = edges[edge].next)
	{
		if(!visited[edges[edge].to] &&
			edges[edge].cap > 0)
		{
			min_ = min(amount,edges[edge].cap);
			t = dfs(edges[edge].to,min_);
			if(t)
			{
				edges[edge].cap -= t;
				edges[rev(edge)].cap += t;
				return t;
			}
		}
	}

	return 0;
}

int main()
{
	int u,v,cap,temp,flow = 0;

	cin>>V>>E>>S>>T;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>cap;
		if(u != v)
			addedge(u,v,cap);
	}

	do
	{
		std::memset(visited,0,sizeof(visited));
		temp = dfs(S,1073741823);
		flow += temp;
	}
	while(temp);

	cout<<flow;

	return 0;
}
