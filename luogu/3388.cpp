#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

/**
	P3388 【模板】割点（割顶）
*/

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define DEBUG 1

#if DEBUG
#include <windows.h>
#endif

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int MAXV = 100010,MAXE = 200020;

struct edge
{
	int to,next;
}
edges[MAXE];

int
	V,E,
	head[MAXV],
	edge_cnt = 1,
	dfn[MAXV],low[MAXV],
	dfs_son[MAXV],
	jzm_clock;

vector<int> vcuts;

template<class T>void read(T &x)
{
	char ch;int flag = 0;x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');cin.get(ch);}
	while(ch >='0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
	if(flag)x = -x;
}

#if DEBUG
void printgraph(std::ostream &out = cout)
{
	for(int i = 0;i < V;++i)
	{
		out<<"vert "<<i;
		for(int j = head[i];j;j = edges[j].next)
			out<<" -> "<<edges[j].to;
		out<<"\n\n";
	}

	for(int i = 0;i <= edge_cnt;++i)
		out<<i<<" : "<<edges[i].to<<" "<<edges[i].next<<endl;
	out<<endl;
}
#endif

inline void addedge(int u,int v)
{
	edges[++edge_cnt] = (edge){v,head[u]};
	head[u] = edge_cnt;
}

void tarjan(int u,int backedge)
{
	dfn[u] = low[u] = ++jzm_clock;
	if(DEBUG)
		cout<<"dfs:"<<u<<" be:"<<backedge<<" cl:"<<jzm_clock<<endl;
	for(int i = head[u];i;i = edges[i].next)
		if(i != backedge)
		{
			if(!dfn[edges[i].to])
			{
				tarjan(edges[i].to,i ^ 1);
				++dfs_son[u];
				low[u] = min(low[u],low[edges[i].to]);
				if(low[edges[i].to] >= dfn[u])
				{
					if(DEBUG)
						cout<<u<<" -> "<<edges[i].to<<endl,
						cout<<low[edges[i].to]<<" "<<dfn[u]<<endl;
					vcuts.push_back(u);
				}
			}
			else
				low[u] = min(low[u],dfn[edges[i].to]);
		}

	if((!backedge) && dfs_son[u] > 1)//is root
	{
		if(DEBUG)cout<<u<<" root "<<endl;
		vcuts.push_back(u);
	}
}

int main()
{
	int u,v;

	read(V);read(E);
	for(int i = 1;i <= E;++i)
	{
		read(u);read(v);
		addedge(u,v);
		addedge(v,u);
	}

#if DEBUG
		printgraph();
#endif

	for(int i = 0;i < V;++i)
		if(!dfn[i])
			tarjan(i,0);

	std::sort(vcuts.begin(), vcuts.end());
	cout<<vcuts.size()<<endl;
	for(vector<int>::iterator it = vcuts.begin();it != vcuts.end();++it)
		cout<<*it<<" ";

#if DEBUG
	system("pause");
#endif

	return 0;
}