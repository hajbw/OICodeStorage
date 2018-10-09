/*
	topological sort templtate.
	output topological order.

	works.
*/
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

const int MAXV = 10000,MAXE = 50000;

struct edge
{
	int v,w,n;
}
e[MAXE];

int head[MAXV],indegree[MAXV],iedge,V,E,toad,order[MAXV],otov[MAXV];

inline void addedge(int u,int v,int w)
{
	e[++iedge] = (edge){v,w,head[u]};
	head[u] = iedge;
}

int main()
{
	int u,v,w;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v>>w;
		addedge(u,v,w);
		++indegree[v];
	}

	{
		queue<int> quq;

		for(int i = 1;i <= V;++i)
			if(!indegree[i])
				quq.push(i);

		while(!quq.empty())
		{
			u = quq.front();
			quq.pop();

			++toad;
			order[u] = toad;
			otov[toad] = u;
			cout<<u<<'\t'<<toad<<'\n';

			for(int i = head[u];i;i = e[i].n)
			{
				v = e[i].v;
				--indegree[v];
				if(!indegree[v])
					quq.push(v);	
			}
		}

		cout<<"u\t|order\t|otov\n";

		for(int i = 1;i <= V;++i)
			cout<<i<<"\t|"<<order[i]<<"\t|"<<otov[i]<<'\n';
	}

	return 0;
}