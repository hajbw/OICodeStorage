/*
	T2049 漂浮的鸭子
	in contest 12607 NOIp热身赛
	AC
*/
#include <iostream>

using std::cin;
using std::cout;

const int MAXN = 100010;

class hstack
{
	int data[MAXN],*head = data;

public:

	void push(const int &a)
	{
		*(head++) = a;
	}

	void pop()
	{
		--head;
	}

	int& top()
	{
		return head[-1];
	}

	bool empty()
	{
		return head == data;
	}

	size_t size()
	{
		return head - data;
	}
}
st;

int N,to[MAXN],w[MAXN],dfn[MAXN],low[MAXN],stat[MAXN],toad,ans;

template<class T>inline const T& min(const T &a,const T &b){return a < b ? a : b;}
template<class T>inline const T& max(const T &a,const T &b){return a > b ? a : b;}

void tarjan(const int &u)
{
	low[u] = dfn[u] = ++toad;
	++stat[u];
	st.push(u);

	if(!stat[to[u]])
	{
		tarjan(to[u]);
		low[u] = min(low[u],low[to[u]]);
	}
	else if(stat[to[u]] == 1)
		low[u] = min(low[u],low[to[u]]);

	if(low[u] == dfn[u])
	{
		register int v,cnt = 0;
		do
		{
			v = st.top();
			st.pop();
			cnt += w[v];
		}
		while(v != u);
		ans = max(ans,cnt);
	}

	++stat[u];
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N;
	for(register int i = 1;i <= N;++i)
		cin>>to[i]>>w[i];

	for(register int i = 1;i <= N;++i)
		if(!stat[i])
			tarjan(i);

	cout<<ans;

	return 0;
}