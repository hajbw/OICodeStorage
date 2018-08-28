#include <iostream>
#include <stack>

#define min(a,b) (a < b ? a : b)

/*
	P2661 信息传递
*/

using std::cin;
using std::cout;

const int MAXN = 200010;

int
	N,jzm_clock = 0,ans = 19260817,
	graph[MAXN],dfn[MAXN],low[MAXN];

stack<int> st;

void read(int &x)
{
	char ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';}
}

void tarjan(int u)
{
	int v = graph[u];
	dfn[u] = low[u] = ++jzm_clock;
	st.push(u);

	if(!dfn[v])
	{
		tarjan(graph[u]);
		low[u] = min(low[u],low[v]);
	}
	else
		low[u] = min(low[u],dfn[v]);

	if(low[u] = dfn[u])
	{
		int count = 0;
		do
		{
			v = st.top();st.pop();
			++count;
		}
		while(v != u);
		if(count > 1)
			ans = min(ans,count);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	read(N);

	for(int i = 0;i < N;++i)
		read(to[i]);

	for(int i = 0;i < N;++i)
		if(!dfn[i])
			tarjan(i);

	cout<<ans;

	return 0;
}