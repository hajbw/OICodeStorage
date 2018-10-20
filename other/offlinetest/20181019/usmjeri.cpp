/*
	2. 树
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 300030,MAXM = 300030;

struct edge
{
	int v,n;
}
e[MAXN << 1];

int M,N,iedge = 1,ins[MAXN],jzm;

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

int main()
{
	int a,b;

	cin>>N>>M;

	for(int i = 1;i <= N;++i)
	{
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}

	for(int i = 1;i <= M;++i)
	{
		cin>>a>>b;
	}

	return 0;
}