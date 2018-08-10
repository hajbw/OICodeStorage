#include <iostream>

/**
	hajbw mega tree template
	actually a graph
	rootless,also works with root
*/

#define AOE 0
#define AOV 0
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

using std::cin;
using std::cout;

typedef int num_t;

const int MAXV = 10000,MAXE = 100000;

template<class T1,class T2> struct hpair
{
	T1 first;
	T2 second;
	hpair():first(),second(){}
	hpair(T1 a):first(a),second(){}
	hpair(T1 a,T2 b):first(a),second(b){}
}

struct edge
{
	int to,next;
#if AOE
	num_t weight;
#endif
}edges[MAXE];

int iedge,head[MAXV];

#if AOE
void addedge(int u,int v,num_t weight)
{
	edges[++iedge] = (edge){v,head[u],weight};
	head[u] = iedge;
}
#else
void addedge(int u,int v)
{
	edges[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}
#endif

template<class T>void read(std::istream &in,T &x)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';}
	if(flag)x = -x;
}

hpair<int,num_t> furthest(int v,int dist)
/**
	find furthest point (with weight) from v
	usage furthest(v,0);
	return: int furthest_point,num_t distance
*/
{
	hpair<int,num_t> result(v,dist),temp;
	for(int i = head[v];i;i = edges[i].next)
	{
		temp = furthest(v,dist + 1);
		if(temp.second > result.second)
			result = temp;
	}
	return result;
}

int get_diameter()
{
	return furthest(furthest(1,0).first,0).second;
}

int main()
{
	return 0;
}