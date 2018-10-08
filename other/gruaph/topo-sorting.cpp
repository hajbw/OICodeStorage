/*
	topological sort templtate
	output topological order
*/
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::queue;

const int MAXV = 10000,MAXE = 50000;

struct edge
{
	int v,n;
}
e[MAXE];

int head[MAXV],indegree[MAXV],iedge,V,E,toad,order[MAXV],otov[MAXV];

inline void addedge(int u,int v)
{
	e[++iedge] = (edge){v,head[u]};
	head[u] = iedge;
}

int main()
{
	int u,v;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>u>>v;
		addedge(u,v);
		++indegree[v];
	}

	{
		queue<int> quq;

		for(int i = 1;i <= V;++i)
		{
			if(indegree[i])
				continue;
			queue.push(i);
			++toad;
			order[i] = toad;
			otov[toad] = i;
		}

		while(!quq.empty())
		{
			u = quq.top();
			quq.pop();

			for(int i = head[a];i;i = e[i].n)
			{
				v = e[i].to;
				if(order[v])
					continue;
				queue.push(v);
				++toad;
				order[i] = toad;
				otov[toad] = i;
			}
		}

		cout<<"|order\t|otov";

		for(int i = 1;i <= N;++i)
			cout<<order[i]<<"\t"<<otov[toad]<<'\n';
	}

	return 0;
}