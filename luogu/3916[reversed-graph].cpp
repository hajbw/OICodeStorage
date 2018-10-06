/*
	P3916 图的遍历
*/
#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXV = 100005,MAXE = 100005;

struct edge
{
	int v,n;
}
e[MAXE];

int head[MAXV],iedge,ans[MAXV],V,E;

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

int main()
{
	cin>>V>>E;

	for
}