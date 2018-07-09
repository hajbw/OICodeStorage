#include <iostream>
#include <vector>
#include <queue>

/**
	topological sorting
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

queue kahn()
/**
	Kahn's algorithm for topological sorting
*/
{
	queue res,id0;
	int flag = 0;

	for(int i = 0;i < V;++i)
		if(!id[i])
			res.push(i);

	while(!id0.empty())
	{
		int n = id0.front();
		id0.pop();

		res.push(n);

		for(vector<int>::iterator it = graph[n].begin;it != graph[n].end();++it)
		{
			--id[*it];
			if(!id[*it])
				id0.push(*it);
		}

		graph[n].clear();
	}

	//if graph has edges left,flag != 0
	for(int i = 0;i < E;++i)
		flag += graph[i].empty();

	return flag ? queue() : res;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int x,y;

	cin>>V>>E;

	for(int i = 0;i < E;++i)
	{
		cin>>x>>y;
		graph[x].push_back(y);
		++indegree[y];
	}
}