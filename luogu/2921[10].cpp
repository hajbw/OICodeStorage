/*
	P2921 [USACO08DEC]在农场万圣节Trick or Treat on the Farm
*/
#include <iostream>
#include <stack>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1000010;//MAXV = MAXE

int next[MAXN],dfn[MAXN],low[MAXN],vis[MAXN],jzm,ans[MAXN];
std::stack<int> st,scc;

void tarjan(int u)
{
	dfn[u] = low[u] = ++jzm;
	++vis[u];
	st.push(u);

	if(!vis[next[u]])
	{
		tarjan(next[u]);
		low[u] = min(low[u],low[next[u]]);
	}
	else if(vis[next[u]] == 1)
		low[u] = min(low[u],dfn[next[u]]);

	if(low[u] != dfn[u])
		return;

	int v,cnt = 0;
	do
	{
		v = st.top();
		st.pop();
		scc.push(v);
		++vis[v];
		++cnt;
	}
	while(u != v);

	if(ans[u] == 1)
		return;

	if(cnt == 1)
		ans[u] = ans[next[u]] + 1;
	else
	{
		do
		{
			v = scc.top();
			scc.pop();
			ans[u] = cnt;
		}
		while(!scc.empty());
	}

}

int main()
{
	int N;

	cin>>N;
	for(int i = 1;i <= N;++i)
	{
		cin>>next[i];
		if(next[i] == i)
			ans[i] = 1;
	}

	for(int i = 1;i <= N;++i)
		if(!dfn[i])
			tarjan(i);

	for(int i = 1;i <= N;++i)
		cout<<ans[i]<<'\n';

	return 0;
}