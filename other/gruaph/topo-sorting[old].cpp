#include <iostream>
#include <vector>
#include <queue>

/*
	topological sorting.
	(old template)
	works.
*/

using std::cin;
using std::cout;
using std::queue;
using std::vector;

typedef int Status;

const int MAXV = 1001,MAXE = 5005;

vector<int> graph[MAXV];
int id[MAXV];//in-degree
int V,E;

queue<int> kahn()
/**
	Kahn's algorithm for topological sorting
*/
{
	queue<int> res,id0;
	int flag = 0;

	for(int i = 0;i < V;++i)
		if(!id[i])
			id0.push(i);


	while(!id0.empty())
	{
		int n = id0.front();
		id0.pop();

		res.push(n);

		for(vector<int>::iterator it = graph[n].begin();it != graph[n].end();++it)
		{
			--id[*it];
			if(!id[*it])
				id0.push(*it);
		}

		graph[n].clear();
	}

	//if graph has edges left,flag != 0
	for(int i = 0;i < E;++i)
		flag += graph[i].size();

	return flag ? queue<int>() : res;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y,w;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y>>w;
		graph[x].push_back(y);
		++id[y];
	}

	cout<<"agrareger\n";

	queue<int> res = kahn();

	while(!res.empty())
	{
		cout<<res.front()<<'\n';
		res.pop();
	}

	return 0;
}