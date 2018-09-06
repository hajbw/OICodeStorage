/**
	P1330 封锁阳光大学
*/

#include <iostream>

using std::cin;
using std::cout;

const int MAXE = 10010,MAXV = 100010,MAXL = 50;

struct edge
{
	int to,next;

	//edge():to(),next(){}
	//edge(const int &to,const int &next):to(to),next(next){}
}
edges[MAXE];

char buf[MAXL],*ch;
int
	V,E,head[MAXV],iedge = 1,
	color[MAXV],color_cnt[4],flag_fail = false;

inline void read(int &a,int &b)
{
	a = b = 0;
	cin.getline(buf,49);
	ch = buf;
	while(*ch < '0' || *ch > '9' && *ch)++ch;
	while(*ch >= '0' && *ch <= '9'){a = (a<<1) + (a<<3) + *ch - '0';++ch;}
	while(*ch < '0' || *ch > '9' && *ch)++ch;
	while(*ch >= '0' && *ch <= '9'){b = (b<<1) + (b<<3) + *ch - '0';++ch;}
}

inline void addedge(const int &u,const int &v)
{
	edges[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

void dfs(const int &u)
{
	if(flag_fail)
		return;

	int v;

	for(int i = head[u];i;i = edges[i].next)
	{
		v = edges[i].to;
		if(!color[v])
		{
			color[v] = 1 ^ color[u];
			dfs(v);
		}
		else if(color[u] == color[v])
		{
			flag_fail = true;
			return;
		}
	}
}

int main()
{
	int u,v;

	cin>>V>>E;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}

	color[1] = 2;
	++color_cnt[2];
	dfs(1);

	if(flag_fail)
		cout<<"";
	else
		cout<<(color_cnt[2] < color_cnt[3] ? color_cnt[2] : color_cnt[3]);
	
	return 0;
}
