/**
	P1330 封锁阳光大学
*/

#include <iostream>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define DEBUG 1

using std::cin;
using std::cout;

const int MAXE = 10010,MAXV = 100010,MAXL = 50;

struct edge
{
	int to;
	edge *next;

	edge():to(),next(){}
	edge(const int &to,edge *next):to(to),next(next){}
}
*head[MAXV];

#if DEBUG
int fault_u,fault_v;
#endif

int
	V,E,
	color[MAXV],
	color_cnt[4],
	flag_fail = false;

inline void read(int &a,int &b)
{
	static char buf[MAXL],*ch;
	a = b = 0;
	cin.getline(buf,49);
	ch = buf;
	while(*ch && (*ch < '0' || *ch > '9'))++ch;
	while(*ch >= '0' && *ch <= '9'){a = (a<<1) + (a<<3) + *ch - '0';++ch;}
	while(*ch && (*ch < '0' || *ch > '9'))++ch;
	while(*ch >= '0' && *ch <= '9'){b = (b<<1) + (b<<3) + *ch - '0';++ch;}
}

void dfs(const int &u)
{
#if DEBUG
	cout<<u;
#endif

	if(flag_fail)
		return;

	++color_cnt[color[u]];

	if(!head[u])
		return;

	for(edge *i = head[u];i;i = i->next)
	{
		if(!color[i->to])
		{
			color[i->to] = 1 ^ color[u];
			dfs(i->to);
		}
		else if(color[u] == color[i->to])
		{
			flag_fail = true;
#if DEBUG
			fault_u = u;
			fault_v = i->to;
#endif
			return;
		}
	}
}

int main()
{
	int u,v,ans = 0;

	cin>>V>>E;
	for(int i = 0;i < E;++i)
	{
		cin>>u>>v;
		head[u] = new edge(v,head[u]);
		head[v] = new edge(u,head[v]);
	}

	for(int i = 1;i <= V;++i)
	{
		if(!color[i])
		{
			color_cnt[2] = color_cnt[3] = 0;
			color[i] = 2;

			dfs(i);

			if(flag_fail)
				break;

			if(color_cnt[2])
			{
				if(color_cnt[3])
					ans += min(color_cnt[2],color_cnt[3]);
				else
					ans += color_cnt[2];
			}
			else if(color_cnt[3])
				ans += color_cnt[3];

		}
	}

#if DEBUG

	cout<<"\n";

	for(int i = 1;i <= V;++i)
		cout<<color[i];

	cout<<"\n"<<color_cnt[2]<<"\t"<<color_cnt[3]<<"\n";

	if(flag_fail)
		cout<<fault_u<<"\t"<<fault_v;
	else
		cout<<ans;

#else

	if(flag_fail)
		cout<<"Impossible";
	else
		cout<<ans;

#endif

	return 0;
}
