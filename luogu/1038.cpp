/*
	P1038 神经网络
*/
#include <queue>
#include <iostream>

#define DEBUG 1

using std::cin;
using std::cout;
using std::pair;
using std::queue;
using std::make_pair;
using std::priority_queue;

const int MAXN = 105;

struct edge
{
	int v,w,n;
}
e[MAXN * MAXN];

int
	head[MAXN],iedge,N,P,
	id[MAXN],otov[MAXN],toad,
	gate,stat[MAXN];

inline void addedge(int u,int v,int w)
{
	e[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

void bfs()
{
	int u,v;
	std::queue<int> quq;

	for(u = 1;u <= N;++u)
		if(!id[u])
			quq.push(u);

	while(!quq.empty())
	{
		u = quq.front();
		quq.pop();
#if DEBUG
		cout<<"u:"<<u<<"\n";
#endif
		++toad;
		otov[toad] = u;

		for(int i = head[u];i;i = e[i].n)
		{
			v = e[i].v;
#if DEBUG
			cout<<"v:"<<v<<"\ti:"<<i<<"|\n";
#endif
			--id[v];
			if(!id[v])
				quq.push(v);
		}
	}
}

int main()
{
	int u,v,w;
	std::priority_queue<pair<int,int>,std::vector<pair<int,int> >,std::greater<pair<int,int> > >quq;//(v,stat)

	cin>>N>>P;
	for(int i = 1;i <= N;++i)
	{
		cin>>stat[i]>>gate;
		stat[i] -= gate;
	}

	for(int i = 1;i <= P;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		++id[v];
	}

	bfs();

#if DEBUG

	cout<<"i\totov\tgate\tstat\n";
	for(int i = 1;i <= N;++i)
		cout<<i<<'\t'<<otov[i]<<'\t'<<gate[i]<<'\t'<<stat[i]<<'\n';
	cout.put('\n');
#endif

	for(int i = 1,j;i <= N;++i)
	{
		u = otov[i];
		j = head[u];

		if(stat[u] <= 0)
			continue;

		if(!j)//output nerve
			quq.push(make_pair(u,stat[u]));

		for(;j;j = e[j].n)
		{
			cout<<u<<'\t'<<e[j].v<<'\t'<<(
			stat[e[j].v] += stat[u] * e[j].w)<<'\n';
		}
	}

#if DEBUG

	cout<<"\ni\totov\tgate\tstat\n";
	for(int i = 1;i <= N;++i)
		cout<<i<<'\t'<<otov[i]<<'\t'<<gate[i]<<'\t'<<stat[i]<<'\n';

#endif

	if(quq.empty())
		cout<<"NULL";
	else while(!quq.empty())
	{
		cout<<quq.top().first<<' '<<quq.top().second<<'\n';
		quq.pop();
	}

	return 0;
}