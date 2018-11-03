/*
	P1991 无线通讯网
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXP = 512;

struct edge
{
	int u,v,w;
	edge *n;
}
edge_pool[MAXP * MAXP],
*iedge = edge_pool,
*head[MAXP];

struct hpair
{
	int x,y;

	friend std::istream& operator>>(std::istream &in,hpair &a)
	{
		return in>>a.x>>a.y;
	}
}
station[MAXP];

int S,P,fa[MAXP];

inline void addedge(const int &u,const int &v,const int &w)
{
	*(++iedge) = (edge){u,v,w,head[u]};
	head[u] = iedge;
}

inline bool cmp(const edge &a,const edge &b)
{
	return a.w < b.w;
}

inline int find(const int &a)
{
	while(fa[a] != fa[fa[a]])
		fa[a] = fa[fa[a]];
	return fa[a];
}

inline int sqa(const int &a)
{
	return a * a;
} 

inline int dist(const hpair &a,const hpair &b)
{
	return sqa(a.x - b.x) + sqa(a.y - b.y);
}

int main()
{
	cin>>S>>P;

	for(int i = 1;i <= P;++i)
	{
		fa[i] = i;
		cin>>station[i];
		for(int j = 1;j < i;++j)
			addedge(i,j,dist(station[i],station[j]));
	}

	std::sort(edge_pool + 1,iedge + 1,cmp);

	P -= S;
	int cnt = 0,a,b,ans = 0;
	edge *it = edge_pool + 1;

	for(;cnt < P && it <= iedge;++it)
	{
		if((a = find(it->u)) == (b = find(it->v)))
			continue;
		fa[a] = b;
		ans = it->w;
		++cnt;
	}

	printf("%.2f",sqrt(ans));

	return 0;
}