#include <iostream>
#include <stack>

#define DEBUG 0

#define min(a,b) ((a) < (b) ? (a) : (b))

#if DEBUG
#include <windows.h>
#endif
/**
	contest 1 problem 3 #24
	C. 传话(message)
	AC
*/

using std::cin;
using std::cout;
using std::stack;

const int MAXV = 1005,MAXE = 10010;

struct edge
{
	int to,next;
}
edges[MAXE];

int
	V,E,edge_cnt,head[MAXV],
	ans[MAXV],//is-in-a-SCC
	dfn[MAXV],low[MAXV],jzm_clock;

stack<int> st;

template<class T> void read(T &x,std::istream &in = std::cin)
{
	char ch = '\0';int flag = 0;x = 0;
	in.get(ch);
	while(ch < '0' || ch > '9'){flag ^= (ch == '-');in.get(ch);}
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch-'0');in.get(ch);}
	if(flag)x = -x;
}

void addedge(int u,int v)
{
	edges[++edge_cnt] = (edge){v,head[u]};
	head[u] = edge_cnt;
}

void tarjan(int u)
{
	int v;
	dfn[u] = low[u] = ++jzm_clock;
	st.push(u);
	for(int i = head[u];i;i = edges[i].next)
	{
		v = edges[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else
			low[u] = min(low[u],dfn[v]);
	}

	if(dfn[u] == low[u])
	{
		if(st.top() == u)
			st.pop();
		else
		{
			do
			{
				v = st.top();
				ans[v] = 1;
				st.pop();
			}
			while(u != v);
		}
	}
}

int main()
{
	int u,v;

	read(V);read(E);
	for(int i = 0;i < E;++i)
	{
		read(u);read(v);
		addedge(u,v);
	}

	for(int i = 1;i <= V;++i)
		if(!dfn[i])
			tarjan(i);

	for(int i = 1;i <= V;++i)
		cout<<(ans[i] ? "T\n" : "F\n");

#if DEBUG
	system("pause");
#endif

	return 0;
}