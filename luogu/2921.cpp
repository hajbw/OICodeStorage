/*
	P2921 [USACO08DEC]在农场万圣节Trick or Treat on the Farm
*/
#include <iostream>
#include <stack>

#define min(a,b) ((a) < (b) ? (a) : (b))

using std::cin;
using std::cout;

const int MAXN = 1000010;//MAXV = MAXE

int next[MAXN],dfn[MAXN],low[MAXN],jzm,ans[MAXN];
std::stack<int> st,scc;

void tarjan(int u)
{
	dfn[u] = low[u] = ++jzm;
	st.push(u);

	if(!dfn[next[u]])
	{
		tarjan(next[u]);
		low[u] = min(low[u],low[next[u]]);
	}
	else
		low[u] = min(low[u],dfn[next[u]]);

	if(low[u] == dfn[u])
	{
		int v,cnt = 0;
		do
		{
			v = st.top();
			scc.push(v);
			st.pop();
			++cnt;
		}
		while(u != v);
		do
		{
			v = scc.top();
			scc.pop();
			ans[v] = cnt;
		}
		while(!scc.empty());
	}
	else
		ans[u] = ans[next[u]] + 1;
}

int main()
{
	int N;

	cin>>N;
	for(int i = 1;i <= N;++i)
		cin>>next[i];

	for(int i = 1;i <= N;++i)
		if(!dfn[i])
			tarjan(i);

	for(int i = 1;i <= N;++i)
		cout<<ans[i]<<'\n';

	return 0;
}