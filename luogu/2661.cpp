#include <iostream>
#include <stack>

#define min(a,b) (a < b ? a : b)

#define DEBUG 0

/*
	P2661 信息传递
	AC
*/

using std::cin;
using std::cout;

const int MAXN = 200010;

int
	N,jzm_clock = 0,ans = 19260817,
	graph[MAXN],dfn[MAXN],low[MAXN];

std::stack<int> st;

void read(int &x)
{
	char ch = '\0';x = 0;
	cin.get(ch);
	while(ch < '0' || ch > '9')cin.get(ch);
	while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + ch - '0';cin.get(ch);}
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

	if(low[u] == dfn[u])
	{
		int count = 0;
		while(v != u)
		{
			v = st.top();st.pop();
			++count;
		}
		if(count > 1 && count < ans)
			ans = count;
	}
}

int main()
{
	//std::ios::sync_with_stdio(false);

	read(N);

	for(int i = 1;i <= N;++i)
		read(graph[i]);

	for(int i = 1;i <= N;++i)
		if(!dfn[i])
			tarjan(i);

	cout<<ans;


	return 0;
}